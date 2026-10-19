// The headless window: used by every build without SDL and by every test. No display: it
// records what was drawn, plays back scripted events and runs a fake 60 Hz clock.
#include "core/window.h"
#include "core/window_mock.h"

#include "workshopc_tags.h"

#define CORE_WINDOW_MOCK_QUEUE_SIZE 64

static const u64 FRAME_NS = 16666667;          // one 60 Hz frame
static const u64 DEFAULT_FRAME_LIMIT = 600;    // ten seconds of fake time
static const f32 GLYPH_SIZE = 8.0f;

struct core_window_impl
{
    u32 width;
    u32 height;
    data_input_event queue[CORE_WINDOW_MOCK_QUEUE_SIZE];
    size_t queue_head;     // next event to poll
    size_t queue_count;    // events waiting
    u64 now_ns;
    u64 frame_limit;       // 0: never quits on its own
    bool quit_sent;
    size_t frame_sprites;  // drawn since the last present
    size_t frame_triangles;
    size_t frame_texts;
    core_window_mock_stats stats;
};

core_window_mock_stats core_window_mock_stats_pod(u64 frames, size_t sprites, size_t triangles, size_t texts,
                                                  u64 clears)
{
    return (core_window_mock_stats){
        .frames = frames, .sprites = sprites, .triangles = triangles, .texts = texts, .clears = clears
    };
}

static void core_window_impl_init(OUTPUT REF core_window_impl* self, u32 width, u32 height)
{
    self->width = width;
    self->height = height;
    self->queue_head = 0;
    self->queue_count = 0;
    self->now_ns = 0;
    self->frame_limit = DEFAULT_FRAME_LIMIT;
    self->quit_sent = false;
    self->frame_sprites = 0;
    self->frame_triangles = 0;
    self->frame_texts = 0;
    self->stats = core_window_mock_stats_pod(0, 0, 0, 0, 0);
}

static core_window_impl* core_window_get_impl(MUTABLE REF core_window* self)
{
    return memory_block_data(&self->impl);
}

static const core_window_impl* core_window_get_const_impl(REF const core_window* self)
{
    return memory_block_const_data(&self->impl);
}

util_singleton_subsystem core_window_subsystem(void)
{
    // Nothing to start or stop without a windowing library
    return util_singleton_subsystem_pod(NULL, NULL);
}

bool core_window_headless(void)
{
    return true;
}

f32 core_window_glyph_size(void)
{
    return GLYPH_SIZE;
}

core_window core_window_make(const char* title, u32 width, u32 height)
{
    (void)title;
    core_window result = { .impl = memory_block_make(1, sizeof(core_window_impl)) };
    core_window_impl* impl = core_window_get_impl(&result);
    if (impl != NULL)
    {
        core_window_impl_init(OUT(impl), width, height);
    }
    return core_window_return(&result);
}

void core_window_destroy(MUTABLE REF core_window* self)
{
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

bool core_window_poll_event(MUTABLE REF core_window* self, OUTPUT REF data_input_event* event)
{
    *event = data_input_event_pod(DATA_INPUT_NONE, 0.0f, 0.0f);
    core_window_impl* impl = core_window_get_impl(self);
    if (impl == NULL)
    {
        return false;
    }
    if (impl->queue_count > 0)
    {
        data_input_event next = data_input_event_pod(impl->queue[impl->queue_head].kind, impl->queue[impl->queue_head].x,
                                                     impl->queue[impl->queue_head].y);
        *event = next;
        impl->queue_head = (impl->queue_head + 1) % CORE_WINDOW_MOCK_QUEUE_SIZE;
        impl->queue_count -= 1;
        if (next.kind == DATA_INPUT_RESIZE)
        {
            impl->width = cast_f32_to_u32(next.x);
            impl->height = cast_f32_to_u32(next.y);
        }
        return true;
    }
    bool limit_reached = impl->frame_limit > 0 && impl->stats.frames >= impl->frame_limit;
    if (limit_reached && !impl->quit_sent)
    {
        impl->quit_sent = true;
        *event = data_input_event_pod(DATA_INPUT_QUIT, 0.0f, 0.0f);
        return true;
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
    const core_window_impl* impl = core_window_get_const_impl(self);
    return impl != NULL ? impl->now_ns : 0;
}

void core_window_clear(MUTABLE REF core_window* self, data_rgba color)
{
    (void)color;
    core_window_impl* impl = core_window_get_impl(self);
    if (impl != NULL)
    {
        impl->stats.clears += 1;
    }
}

void core_window_draw_sprites(MUTABLE REF core_window* self, REF const core_sprite_batch_view* sprites)
{
    core_window_impl* impl = core_window_get_impl(self);
    if (impl != NULL)
    {
        impl->frame_sprites += sprites->count;
    }
}

void core_window_draw_triangle(MUTABLE REF core_window* self, data_triangle triangle, data_rgba color)
{
    (void)triangle;
    (void)color;
    core_window_impl* impl = core_window_get_impl(self);
    if (impl != NULL)
    {
        impl->frame_triangles += 1;
    }
}

void core_window_draw_text(MUTABLE REF core_window* self, f32 x, f32 y, f32 scale, char_const_span text,
                           data_rgba color)
{
    (void)x;
    (void)y;
    (void)scale;
    (void)color;
    core_window_impl* impl = core_window_get_impl(self);
    if (impl != NULL && text.data != NULL && text.size > 0)
    {
        impl->frame_texts += 1;
    }
}

void core_window_present(MUTABLE REF core_window* self)
{
    core_window_impl* impl = core_window_get_impl(self);
    if (impl == NULL)
    {
        return;
    }
    impl->stats = core_window_mock_stats_pod(impl->stats.frames + 1, impl->frame_sprites, impl->frame_triangles,
                                             impl->frame_texts, impl->stats.clears);
    impl->frame_sprites = 0;
    impl->frame_triangles = 0;
    impl->frame_texts = 0;
    impl->now_ns += FRAME_NS;
}

bool core_window_mock_push_event(MUTABLE REF core_window* self, data_input_event event)
{
    core_window_impl* impl = core_window_get_impl(self);
    if (impl == NULL || impl->queue_count == CORE_WINDOW_MOCK_QUEUE_SIZE)
    {
        return false;
    }
    size_t tail = (impl->queue_head + impl->queue_count) % CORE_WINDOW_MOCK_QUEUE_SIZE;
    impl->queue[tail] = event;
    impl->queue_count += 1;
    return true;
}

core_window_mock_stats core_window_mock_get_stats(REF const core_window* self)
{
    const core_window_impl* impl = core_window_get_const_impl(self);
    if (impl == NULL)
    {
        return core_window_mock_stats_pod(0, 0, 0, 0, 0);
    }
    return impl->stats;
}

void core_window_mock_set_frame_limit(MUTABLE REF core_window* self, u64 frames)
{
    core_window_impl* impl = core_window_get_impl(self);
    if (impl != NULL)
    {
        impl->frame_limit = frames;
    }
}

u64 core_window_mock_default_frames(void)
{
    return DEFAULT_FRAME_LIMIT;
}
