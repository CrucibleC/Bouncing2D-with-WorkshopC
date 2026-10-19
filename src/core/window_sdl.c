// The real window, on SDL3: only in CI release builds (BOUNCING2D_SDL=ON). Local builds and every
// test use window_mock.c instead, so WorkshopC never sees this file (SDL's headers never exist
// locally; it is listed in third_party_includes) and the CI compiler is its only check. Keep it
// thin: everything that can be pure lives in core/sprite_batch, app/hud and app/simulation.
//
// Sizes and positions are in pixels of the drawable area (SDL's "render output"), so a high-DPI
// display gets its full resolution; mouse positions are converted to the same pixels.
#include "core/window.h"

#include <inttypes.h>

#define SDL_MAIN_HANDLED   // main.c keeps its own main: only declare SDL_SetMainReady
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "util/log.h"
#include "workshopc_tags.h"

#define CORE_WINDOW_SDL_TEXT_MAX 128   // longest text drawn at once, including the '\0'

static const u32 CIRCLE_TEXTURE_SIZE = 256;   // pixels per side; big spheres are scaled up from it
static const u32 BYTES_PER_PIXEL = 4;          // SDL_PIXELFORMAT_RGBA32
static const u32 MINIMIZED_DELAY_MS = 16;     // VSync does nothing while minimized: don't spin

struct core_window_impl
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* circle;   // white, alpha from core_sprite_circle_alpha; tinted per vertex
    u32 width;             // drawable area in pixels
    u32 height;
};

static core_window_impl* core_window_get_impl(MUTABLE REF core_window* self)
{
    return memory_block_data(&self->impl);
}

static const core_window_impl* core_window_get_const_impl(REF const core_window* self)
{
    return memory_block_const_data(&self->impl);
}

static status core_window_sdl_init(void)
{
    SDL_SetMainReady();
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        UTIL_LOG_ERROR("SDL_Init failed: %s", SDL_GetError());
        return STATUS_UNSUPPORTED;
    }
    UTIL_LOG_INFO("SDL %d.%d.%d, video driver %s", SDL_VERSIONNUM_MAJOR(SDL_GetVersion()),
                  SDL_VERSIONNUM_MINOR(SDL_GetVersion()), SDL_VERSIONNUM_MICRO(SDL_GetVersion()),
                  SDL_GetCurrentVideoDriver() != NULL ? SDL_GetCurrentVideoDriver() : "none");
    return STATUS_OK;
}

static void core_window_sdl_shutdown(void)
{
    SDL_Quit();
}

util_singleton_subsystem core_window_subsystem(void)
{
    return util_singleton_subsystem_pod(core_window_sdl_init, core_window_sdl_shutdown);
}

bool core_window_headless(void)
{
    return false;
}

f32 core_window_glyph_size(void)
{
    return cast_i32_to_f32(SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE);
}

static SDL_FColor core_window_sdl_color(data_rgba color)
{
    return (SDL_FColor){ .r = cast_u8_to_f32(color.r) / 255.0f, .g = cast_u8_to_f32(color.g) / 255.0f,
                         .b = cast_u8_to_f32(color.b) / 255.0f, .a = cast_u8_to_f32(color.a) / 255.0f };
}

// Reads the drawable size in pixels into impl->width and impl->height
static void core_window_sdl_read_size(MUTABLE REF core_window_impl* impl)
{
    int width = 0;
    int height = 0;
    if (SDL_GetCurrentRenderOutputSize(impl->renderer, &width, &height) && width > 0 && height > 0)
    {
        impl->width = cast_i32_to_u32(width);
        impl->height = cast_i32_to_u32(height);
    }
}

// The one texture every sphere is drawn with: a white anti-aliased circle
static SDL_Texture* core_window_sdl_make_circle(SDL_Renderer* renderer)
{
    u32 size = CIRCLE_TEXTURE_SIZE;
    memory_block pixels_block = memory_block_make(cast_u32_to_size_t(size) * size * BYTES_PER_PIXEL, 1);
    u8* pixels = memory_block_data(&pixels_block);
    SDL_Texture* texture = NULL;
    if (pixels != NULL)
    {
        for (u32 py = 0; py < size; py++)
        {
            for (u32 px = 0; px < size; px++)
            {
                size_t at = (cast_u32_to_size_t(py) * size + px) * BYTES_PER_PIXEL;
                pixels[at + 0] = 255;
                pixels[at + 1] = 255;
                pixels[at + 2] = 255;
                pixels[at + 3] = cast_f32_to_u8(core_sprite_circle_alpha(size, px, py) * 255.0f + 0.5f);
            }
        }
        texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STATIC, cast_u32_to_i32(size),
                                    cast_u32_to_i32(size));
    }
    if (texture != NULL)
    {
        (void)SDL_UpdateTexture(texture, NULL, pixels, cast_u32_to_i32(size * BYTES_PER_PIXEL));
        (void)SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
        (void)SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_LINEAR);
    }
    memory_block_destroy(&pixels_block);
    return texture;
}

core_window core_window_make(const char* title, u32 width, u32 height)
{
    core_window result = { .impl = memory_block_make(1, sizeof(core_window_impl)) };
    core_window_impl* impl = core_window_get_impl(&result);
    if (impl == NULL)
    {
        return core_window_return(&result);
    }
    // Zeroed by memory_block_make: every pointer starts NULL, so destroy works at any point
    impl->width = width;
    impl->height = height;
    impl->window = SDL_CreateWindow(title, cast_u32_to_i32(width), cast_u32_to_i32(height),
                                    SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIGH_PIXEL_DENSITY);
    if (impl->window != NULL)
    {
        impl->renderer = SDL_CreateRenderer(impl->window, NULL);
    }
    if (impl->renderer != NULL)
    {
        impl->circle = core_window_sdl_make_circle(impl->renderer);
    }
    if (impl->circle == NULL)
    {
        UTIL_LOG_ERROR("couldn't make the window: %s", SDL_GetError());
        core_window_destroy(&result);
        return core_window_return(&result);
    }
    if (!SDL_SetRenderVSync(impl->renderer, 1))
    {
        UTIL_LOG_WARN("no VSync: %s", SDL_GetError());
    }
    core_window_sdl_read_size(impl);
    UTIL_LOG_INFO("renderer %s, %" PRIu32 " x %" PRIu32 " pixels", SDL_GetRendererName(impl->renderer),
                  impl->width, impl->height);
    return core_window_return(&result);
}

void core_window_destroy(MUTABLE REF core_window* self)
{
    core_window_impl* impl = core_window_get_impl(self);
    if (impl != NULL)
    {
        if (impl->circle != NULL)
        {
            SDL_DestroyTexture(impl->circle);
        }
        if (impl->renderer != NULL)
        {
            SDL_DestroyRenderer(impl->renderer);
        }
        if (impl->window != NULL)
        {
            SDL_DestroyWindow(impl->window);
        }
    }
    memory_block_destroy(&self->impl);
}

core_window core_window_return(MUTABLE REF core_window* self)
{
    return *self;
}

bool core_window_valid(REF const core_window* self)
{
    return memory_block_valid(&self->impl);
}

// The neutral event for an SDL event; DATA_INPUT_NONE for events the app doesn't use
static data_input_event core_window_sdl_translate(MUTABLE REF core_window_impl* impl, SDL_Event* event)
{
    switch (event->type)
    {
        case SDL_EVENT_QUIT:
            return data_input_event_pod(DATA_INPUT_QUIT, 0.0f, 0.0f);
        case SDL_EVENT_KEY_DOWN:
            if (event->key.key == SDLK_ESCAPE)
            {
                return data_input_event_pod(DATA_INPUT_QUIT, 0.0f, 0.0f);
            }
            break;
        case SDL_EVENT_MOUSE_BUTTON_DOWN:
        case SDL_EVENT_MOUSE_BUTTON_UP:
            if (event->button.button == SDL_BUTTON_LEFT)
            {
                (void)SDL_ConvertEventToRenderCoordinates(impl->renderer, event);   // window -> pixels
                data_input_kind kind =
                    event->type == SDL_EVENT_MOUSE_BUTTON_DOWN ? DATA_INPUT_MOUSE_DOWN : DATA_INPUT_MOUSE_UP;
                return data_input_event_pod(kind, event->button.x, event->button.y);
            }
            break;
        case SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED:
            // A minimized window may report 0 x 0: keep the last real size for the simulation
            if (event->window.data1 > 0 && event->window.data2 > 0)
            {
                impl->width = cast_i32_to_u32(event->window.data1);
                impl->height = cast_i32_to_u32(event->window.data2);
                return data_input_event_pod(DATA_INPUT_RESIZE, cast_u32_to_f32(impl->width),
                                            cast_u32_to_f32(impl->height));
            }
            break;
        default:
            break;
    }
    return data_input_event_pod(DATA_INPUT_NONE, 0.0f, 0.0f);
}

bool core_window_poll_event(MUTABLE REF core_window* self, OUTPUT REF data_input_event* event)
{
    *event = data_input_event_pod(DATA_INPUT_NONE, 0.0f, 0.0f);
    core_window_impl* impl = core_window_get_impl(self);
    if (impl == NULL)
    {
        return false;
    }
    SDL_Event sdl_event;
    // Skips the events the app doesn't use, so a true result always carries one it does
    while (SDL_PollEvent(&sdl_event))
    {
        data_input_event translated = core_window_sdl_translate(impl, &sdl_event);
        if (translated.kind != DATA_INPUT_NONE)
        {
            *event = translated;
            return true;
        }
    }
    return false;
}

data_bounds core_window_bounds(REF const core_window* self)
{
    const core_window_impl* impl = core_window_get_const_impl(self);
    if (impl == NULL)
    {
        return data_bounds_pod(0.0f, 0.0f, 0.0f, 0.0f);
    }
    return data_bounds_pod(0.0f, 0.0f, cast_u32_to_f32(impl->width), cast_u32_to_f32(impl->height));
}

u64 core_window_time_ns(REF const core_window* self)
{
    (void)self;
    return SDL_GetTicksNS();
}

void core_window_clear(MUTABLE REF core_window* self, data_rgba color)
{
    core_window_impl* impl = core_window_get_impl(self);
    if (impl != NULL)
    {
        (void)SDL_SetRenderDrawColor(impl->renderer, color.r, color.g, color.b, color.a);
        (void)SDL_RenderClear(impl->renderer);
    }
}

void core_window_draw_sprites(MUTABLE REF core_window* self, REF const core_sprite_batch_view* sprites)
{
    core_window_impl* impl = core_window_get_impl(self);
    // core_sprite_batch_prepare keeps count <= INT32_MAX / 4, so the counts below fit an int
    if (impl == NULL || sprites->count == 0 || sprites->xy == NULL || sprites->count > cast_i32_to_size_t(SDL_MAX_SINT32 / 6))
    {
        return;
    }
    int vertices = cast_size_t_to_i32(sprites->count * 4);
    int indices = cast_size_t_to_i32(sprites->count * 6);
    // colors: 4 f32 per vertex, laid out exactly like SDL_FColor
    (void)SDL_RenderGeometryRaw(impl->renderer, impl->circle, sprites->xy, cast_size_t_to_i32(2 * sizeof(f32)),
                                (const SDL_FColor*)sprites->colors, cast_size_t_to_i32(sizeof(SDL_FColor)),
                                sprites->uv, cast_size_t_to_i32(2 * sizeof(f32)), vertices, sprites->indices,
                                indices, cast_size_t_to_i32(sizeof(u32)));
}

void core_window_draw_triangle(MUTABLE REF core_window* self, data_triangle triangle, data_rgba color)
{
    core_window_impl* impl = core_window_get_impl(self);
    if (impl == NULL)
    {
        return;
    }
    SDL_FColor fcolor = core_window_sdl_color(color);
    SDL_Vertex vertices[3] = {
        { .position = { triangle.x0, triangle.y0 }, .color = fcolor, .tex_coord = { 0.0f, 0.0f } },
        { .position = { triangle.x1, triangle.y1 }, .color = fcolor, .tex_coord = { 0.0f, 0.0f } },
        { .position = { triangle.x2, triangle.y2 }, .color = fcolor, .tex_coord = { 0.0f, 0.0f } },
    };
    (void)SDL_RenderGeometry(impl->renderer, NULL, vertices, 3, NULL, 0);
}

void core_window_draw_text(MUTABLE REF core_window* self, f32 x, f32 y, f32 scale, char_const_span text,
                           data_rgba color)
{
    core_window_impl* impl = core_window_get_impl(self);
    if (impl == NULL || text.data == NULL || text.size == 0 || scale <= 0.0f)
    {
        return;
    }
    // SDL wants a '\0'-terminated string: copy up to the first '\0', the span's end or the buffer's
    char line[CORE_WINDOW_SDL_TEXT_MAX];
    size_t length = 0;
    while (length < text.size && length < CORE_WINDOW_SDL_TEXT_MAX - 1 && text.data[length] != '\0')
    {
        line[length] = text.data[length];
        length++;
    }
    line[length] = '\0';
    // The debug font is 8 x 8 pixels: draw it scaled, in scaled coordinates
    (void)SDL_SetRenderScale(impl->renderer, scale, scale);
    (void)SDL_SetRenderDrawColor(impl->renderer, color.r, color.g, color.b, color.a);
    (void)SDL_RenderDebugText(impl->renderer, x / scale, y / scale, line);
    (void)SDL_SetRenderScale(impl->renderer, 1.0f, 1.0f);
}

void core_window_present(MUTABLE REF core_window* self)
{
    core_window_impl* impl = core_window_get_impl(self);
    if (impl == NULL)
    {
        return;
    }
    (void)SDL_RenderPresent(impl->renderer);
    if ((SDL_GetWindowFlags(impl->window) & SDL_WINDOW_MINIMIZED) != 0)
    {
        SDL_Delay(MINIMIZED_DELAY_MS);
    }
}
