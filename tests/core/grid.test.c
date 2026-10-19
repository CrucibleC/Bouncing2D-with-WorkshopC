#include "hammerc.h"

#include "core/grid.h"
#include "core/spheres.h"

static void place(core_spheres_view *view, u32 i, f32 x, f32 y, f32 vx, f32 vy, f32 radius)
{
    view->x[i] = x;
    view->y[i] = y;
    view->vx[i] = vx;
    view->vy[i] = vy;
    view->radius[i] = radius;
}

/* O(n^2) count of pairs overlapping by more than slack, the reference the grid must match */
static size_t brute_force_overlaps(const core_spheres_view *view, f32 slack)
{
    size_t overlaps = 0;
    for (size_t a = 0; a < view->count; a++) {
        for (size_t b = a + 1; b < view->count; b++) {
            f32 dx = view->x[b] - view->x[a];
            f32 dy = view->y[b] - view->y[a];
            f32 reach = view->radius[a] + view->radius[b] - slack;
            overlaps += dx * dx + dy * dy < reach * reach;
        }
    }
    return overlaps;
}

void test_grid_size_for_picks_square_cells(HammerCtx *t)
{
    u32 columns = 0;
    u32 rows = 0;
    data_bounds window = data_bounds_pod(0.0f, 0.0f, 800.0f, 600.0f);
    /* 400 spheres: 100 cells of ~69.3 units -> 11 x 8 */
    core_grid_size_for(400, window, 2.0f, &columns, &rows);
    CHECK_EQ_UINT(columns, 11);
    CHECK_EQ_UINT(rows, 8);
    /* big spheres: cells at least one diameter wide */
    core_grid_size_for(400, window, 200.0f, &columns, &rows);
    CHECK_EQ_UINT(columns, 4);
    CHECK_EQ_UINT(rows, 3);
    /* no spheres, or no area: one cell */
    core_grid_size_for(0, window, 2.0f, &columns, &rows);
    CHECK(columns == 1 && rows == 1);
    core_grid_size_for(400, data_bounds_pod(0.0f, 0.0f, 0.0f, 600.0f), 2.0f, &columns, &rows);
    CHECK(columns == 1 && rows == 1);
    /* a huge count is capped */
    core_grid_size_for(1000000000, window, 0.0f, &columns, &rows);
    CHECK(columns == 4096 && rows == 4096);
}

void test_grid_make_and_resize(HammerCtx *t)
{
    core_grid grid = core_grid_make(0, 0);
    REQUIRE(core_grid_valid(&grid));
    CHECK_EQ_INT(core_grid_status(&grid), STATUS_OK);
    CHECK(core_grid_columns(&grid) == 1 && core_grid_rows(&grid) == 1);
    CHECK_EQ_INT(core_grid_resize(&grid, 11, 8), STATUS_OK);
    CHECK(core_grid_columns(&grid) == 11 && core_grid_rows(&grid) == 8);
    core_grid copy = core_grid_copy(&grid);
    CHECK(core_grid_valid(&copy) && core_grid_columns(&copy) == 11);
    core_grid moved = core_grid_move(&grid);
    CHECK(!core_grid_valid(&grid));
    CHECK(core_grid_valid(&moved) && core_grid_rows(&moved) == 8);
    core_grid_destroy(&moved);
    core_grid_destroy(&copy);
    core_grid_destroy(&grid);
}

void test_grid_pair_in_four_shared_cells_is_resolved_once(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(2);
    core_grid grid = core_grid_make(2, 2);
    REQUIRE(core_spheres_valid(&spheres) && core_grid_valid(&grid));
    core_spheres_view view = core_spheres_get_view(&spheres);
    /* both straddle the center of a 2 x 2 grid over 10 x 10, so both touch all four cells */
    place(&view, 0, 5.0f, 5.0f, 0.0f, 0.0f, 1.0f);
    place(&view, 1, 5.5f, 5.0f, 0.0f, 0.0f, 1.0f);
    CHECK_EQ_UINT(core_grid_resolve_pairs(&grid, &view, data_bounds_pod(0.0f, 0.0f, 10.0f, 10.0f)), 1);
    /* resolved: now just touching */
    CHECK(view.x[1] - view.x[0] > 1.99f && view.x[1] - view.x[0] < 2.01f);
    core_grid_destroy(&grid);
    core_spheres_destroy(&spheres);
}

void test_grid_finds_pairs_across_a_cell_border(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(2);
    core_grid grid = core_grid_make(2, 1);
    REQUIRE(core_spheres_valid(&spheres) && core_grid_valid(&grid));
    core_spheres_view view = core_spheres_get_view(&spheres);
    /* the border is at x = 5: sphere 0 only in column 0, sphere 1 in both */
    place(&view, 0, 4.2f, 5.0f, 1.0f, 0.0f, 0.5f);
    place(&view, 1, 5.3f, 5.0f, -1.0f, 0.0f, 0.7f);
    CHECK_EQ_UINT(core_grid_resolve_pairs(&grid, &view, data_bounds_pod(0.0f, 0.0f, 10.0f, 10.0f)), 1);
    core_grid_destroy(&grid);
    core_spheres_destroy(&spheres);
}

void test_grid_puts_spheres_outside_the_bounds_in_edge_cells(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(4);
    core_grid grid = core_grid_make(4, 4);
    REQUIRE(core_spheres_valid(&spheres) && core_grid_valid(&grid));
    core_spheres_view view = core_spheres_get_view(&spheres);
    place(&view, 0, -50.0f, 5.0f, 0.0f, 0.0f, 1.0f);
    place(&view, 1, -49.0f, 5.0f, 0.0f, 0.0f, 1.0f);
    place(&view, 2, 500.0f, 500.0f, 0.0f, 0.0f, 1.0f);
    place(&view, 3, 501.0f, 500.5f, 0.0f, 0.0f, 1.0f);
    CHECK_EQ_UINT(core_grid_resolve_pairs(&grid, &view, data_bounds_pod(0.0f, 0.0f, 100.0f, 100.0f)), 2);
    core_grid_destroy(&grid);
    core_spheres_destroy(&spheres);
}

void test_grid_matches_brute_force_on_many_separate_pairs(HammerCtx *t)
{
    /* 50 overlapping pairs on a 10 x 5 lattice, spaced 20 apart in 200 x 100, shifted so many
       straddle cell borders; plus 20 lone spheres. Groups never reach each other, so resolving
       one pair can't create or remove another overlap. */
    core_spheres spheres = core_spheres_make(120);
    REQUIRE(core_spheres_valid(&spheres));
    core_spheres_view view = core_spheres_get_view(&spheres);
    u32 i = 0;
    for (u32 row = 0; row < 5; row++) {
        for (u32 column = 0; column < 10; column++) {
            f32 cx = 20.0f * (f32)column + 7.0f + (f32)((column * 3 + row * 5) % 7);
            f32 cy = 20.0f * (f32)row + 7.0f + (f32)((column * 5 + row * 3) % 7);
            place(&view, i++, cx, cy, 1.0f, 0.5f, 1.0f);
            place(&view, i++, cx + 1.5f, cy + 0.3f, -1.0f, 0.0f, 1.0f);
        }
    }
    for (u32 lone = 0; lone < 20; lone++) {
        place(&view, i++, 20.0f * (f32)(lone % 10) + 17.0f, 20.0f * (f32)(lone / 10) + 17.0f, 0.0f, 0.0f, 0.5f);
    }
    REQUIRE(i == 120);
    size_t expected = brute_force_overlaps(&view, 0.0f);
    CHECK_EQ_UINT(expected, 50);

    data_bounds box = data_bounds_pod(0.0f, 0.0f, 200.0f, 100.0f);
    u32 columns = 0;
    u32 rows = 0;
    core_grid_size_for(view.count, box, 2.0f, &columns, &rows);
    core_grid grid = core_grid_make(columns, rows);
    REQUIRE(core_grid_valid(&grid));
    CHECK_EQ_UINT(core_grid_resolve_pairs(&grid, &view, box), expected);
    /* resolved: nothing overlaps any more (pairs now just touch, give or take float rounding) */
    CHECK_EQ_UINT(brute_force_overlaps(&view, 1e-3f), 0);
    core_grid_destroy(&grid);
    core_spheres_destroy(&spheres);
}

void test_grid_grows_with_the_sphere_count(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(2);
    core_grid grid = core_grid_make(1, 1);
    REQUIRE(core_spheres_valid(&spheres) && core_grid_valid(&grid));
    core_spheres_view view = core_spheres_get_view(&spheres);
    place(&view, 0, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f);
    place(&view, 1, 2.0f, 1.0f, 0.0f, 0.0f, 1.0f);
    data_bounds box = data_bounds_pod(0.0f, 0.0f, 1000.0f, 10.0f);
    CHECK_EQ_UINT(core_grid_resolve_pairs(&grid, &view, box), 1);

    /* 1000 spheres in one row, each overlapping only its neighbor in its own pair */
    REQUIRE_EQ_INT(core_spheres_resize(&spheres, 1000), STATUS_OK);
    view = core_spheres_get_view(&spheres);
    for (u32 k = 0; k < 500; k++) {
        place(&view, 2 * k, 1.0f + 2.0f * (f32)k, 2.0f, 0.0f, 0.0f, 0.4f);
        place(&view, 2 * k + 1, 1.5f + 2.0f * (f32)k, 2.0f, 0.0f, 0.0f, 0.4f);
    }
    u32 columns = 0;
    u32 rows = 0;
    core_grid_size_for(view.count, box, 0.8f, &columns, &rows);
    REQUIRE_EQ_INT(core_grid_resize(&grid, columns, rows), STATUS_OK);
    CHECK_EQ_UINT(core_grid_resolve_pairs(&grid, &view, box), 500);
    CHECK_EQ_INT(core_grid_status(&grid), STATUS_OK);
    core_grid_destroy(&grid);
    core_spheres_destroy(&spheres);
}

void test_grid_with_no_spheres_resolves_nothing(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(0);
    core_grid grid = core_grid_make(3, 3);
    REQUIRE(core_spheres_valid(&spheres) && core_grid_valid(&grid));
    core_spheres_view view = core_spheres_get_view(&spheres);
    CHECK_EQ_UINT(core_grid_resolve_pairs(&grid, &view, data_bounds_pod(0.0f, 0.0f, 10.0f, 10.0f)), 0);
    core_grid_destroy(&grid);
    core_spheres_destroy(&spheres);
}

void test_grid_sort_orders_spheres_by_cell_and_keeps_them_whole(HammerCtx *t)
{
    /* 40 spheres placed right to left, bottom to top, in a 4 x 4 grid over 100 x 100. Each
       sphere's other values encode its x, so a sphere torn apart by the sort would show. */
    core_spheres spheres = core_spheres_make(40);
    core_grid grid = core_grid_make(4, 4);
    REQUIRE(core_spheres_valid(&spheres) && core_grid_valid(&grid));
    core_spheres_view view = core_spheres_get_view(&spheres);
    for (u32 i = 0; i < 40; i++) {
        f32 x = 99.0f - 2.4f * (f32)i;
        f32 y = 99.0f - 2.0f * (f32)i;
        place(&view, i, x, y, x * 2.0f, x * 3.0f, x * 0.01f + 0.5f);
        view.rgba[i] = data_rgba_pod((u8)i, 0, 0, 255);
    }
    data_bounds box = data_bounds_pod(0.0f, 0.0f, 100.0f, 100.0f);
    REQUIRE(core_grid_sort_spheres(&grid, &view, box));
    CHECK_EQ_UINT(view.count, 40);
    int out_of_order = 0;
    int torn = 0;
    u32 previous_cell = 0;
    for (u32 i = 0; i < 40; i++) {
        u32 cell = (u32)(view.y[i] / 25.0f) * 4 + (u32)(view.x[i] / 25.0f);
        out_of_order += cell < previous_cell;
        previous_cell = cell;
        torn += view.vx[i] != view.x[i] * 2.0f || view.vy[i] != view.x[i] * 3.0f;
        torn += view.radius[i] != view.x[i] * 0.01f + 0.5f;
        /* the color still belongs to the sphere it was given to */
        torn += view.x[i] != 99.0f - 2.4f * (f32)view.rgba[i].r;
    }
    CHECK_EQ_INT(out_of_order, 0);
    CHECK_EQ_INT(torn, 0);
    core_grid_destroy(&grid);
    core_spheres_destroy(&spheres);
}

void test_grid_sort_with_fewer_than_two_spheres_does_nothing(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(1);
    core_grid grid = core_grid_make(2, 2);
    REQUIRE(core_spheres_valid(&spheres) && core_grid_valid(&grid));
    core_spheres_view view = core_spheres_get_view(&spheres);
    place(&view, 0, 3.0f, 4.0f, 5.0f, 6.0f, 1.0f);
    CHECK(core_grid_sort_spheres(&grid, &view, data_bounds_pod(0.0f, 0.0f, 10.0f, 10.0f)));
    CHECK(view.x[0] == 3.0f && view.vy[0] == 6.0f);
    core_grid_destroy(&grid);
    core_spheres_destroy(&spheres);
}
