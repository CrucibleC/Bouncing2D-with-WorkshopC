#ifndef CORE_SPHERES_H
#define CORE_SPHERES_H

#include <stdbool.h>
#include <stddef.h>

#include "data/rgba.h"
#include "data/sphere.h"
#include "memory_block.h"
#include "numbers.h"
#include "status.h"
#include "workshopc_tags.h"

// The simulation's spheres as a structure of arrays in ONE memory_block: all x values next to
// each other, then all y, vx, vy, radius and rgba. Each array is stride elements long (the count
// rounded up to 16), so every array starts 64 bytes apart from the next: cache-line and SIMD
// friendly. Each array is only ever accessed through its own type, so there is no aliasing.
// Storage only: core_spheres never chooses values; set them through the view. make and resize
// leave every sphere zeroed, and the count changes only through core_spheres_resize.
typedef struct core_spheres
{
    PRIVATE memory_block block;   // the six arrays, 24 bytes per sphere slot
    PRIVATE size_t count;         // spheres in use; 0 when invalid
    PRIVATE size_t stride;        // elements per array: count rounded up to a multiple of 16
    PRIVATE u32 generation;       // bumped by resize, move (the source) and destroy: see the views
} core_spheres;

// Every array at once, count elements each, for system loops: copy the pointers into local
// restrict pointers and loop over count. Valid until the next resize, move or destroy, which
// core_spheres_view_is_current checks (functions taking a view assert it in Debug builds).
// The view's type says what may change, not its pointer's const: a const core_spheres_view* still
// writes the spheres (it only can't re-point the view); read-only code takes a core_spheres_const_view.
typedef struct core_spheres_view
{
    size_t count;
    f32* x;
    f32* y;
    f32* vx;
    f32* vy;
    f32* radius;
    data_rgba* rgba;
    const u32* generation;   // the owner's counter; NULL for an empty view (never stale)
    u32 taken_at;            // its value when the view was taken
} core_spheres_view;

// The same, read-only
typedef struct core_spheres_const_view
{
    size_t count;
    const f32* x;
    const f32* y;
    const f32* vx;
    const f32* vy;
    const f32* radius;
    const data_rgba* rgba;
    const u32* generation;
    u32 taken_at;
} core_spheres_const_view;

// { count, x, y, vx, vy, radius, rgba, generation, taken_at }; made by core_spheres_get_view
core_spheres_view core_spheres_view_pod(size_t count, MUTABLE f32* x, MUTABLE f32* y, MUTABLE f32* vx,
                                        MUTABLE f32* vy, MUTABLE f32* radius, MUTABLE data_rgba* rgba,
                                        const u32* generation, u32 taken_at);
// { count, x, y, vx, vy, radius, rgba, generation, taken_at }; made by core_spheres_get_const_view
core_spheres_const_view core_spheres_const_view_pod(size_t count, const f32* x, const f32* y, const f32* vx,
                                                    const f32* vy, const f32* radius, const data_rgba* rgba,
                                                    const u32* generation, u32 taken_at);

// Whether the view still matches its spheres: false once they were resized, moved from or
// destroyed (the arrays may have moved). Functions taking a view assert it, so Debug builds catch
// a stale view at its first use; NDEBUG (Release) drops the asserts
static inline bool core_spheres_view_is_current(REF const core_spheres_view* view)
{
    return view->generation == NULL || *view->generation == view->taken_at;
}

static inline bool core_spheres_const_view_is_current(REF const core_spheres_const_view* view)
{
    return view->generation == NULL || *view->generation == view->taken_at;
}

// count zeroed spheres; invalid (count 0) when the allocation fails
core_spheres core_spheres_make(size_t count);
core_spheres core_spheres_copy(REF const core_spheres* self);
core_spheres core_spheres_move(MUTABLE REF core_spheres* self);
void core_spheres_destroy(MUTABLE REF core_spheres* self);
core_spheres core_spheres_return(MUTABLE REF core_spheres* self);
bool core_spheres_valid(REF const core_spheres* self);
status core_spheres_status(REF const core_spheres* self);

// Changes the count and zeroes every sphere, old and new. On failure (STATUS_OUT_OF_RANGE when
// count is too big, or the allocation's status) the spheres are unchanged. Invalidates every view
status core_spheres_resize(MUTABLE REF core_spheres* self, size_t count);
size_t core_spheres_count(REF const core_spheres* self);

// All arrays, for system loops; an empty view (count 0, NULL pointers) when invalid
core_spheres_view core_spheres_get_view(MUTABLE REF core_spheres* self);
core_spheres_const_view core_spheres_get_const_view(REF const core_spheres* self);

// One whole sphere, for tests, debugging and picking; never use it in system loops.
// false (and a zeroed sphere) when index is out of range
bool core_spheres_get(REF const core_spheres* self, size_t index, OUTPUT REF data_sphere* sphere);

#endif // CORE_SPHERES_H
