#include <string.h>

#include "hammerc.h"

#include "app/app.h"
#include "util/fs.h"
#include "util/log.h"
#include "util/string.h"

/* app_run logs to a file named after the executable, next to it: here tests_app.log. */
static util_string log_path(HammerCtx *t)
{
    util_string path = util_string_make("");
    CHECK_EQ_INT(util_fs_executable_folder(&path), STATUS_OK);
    CHECK_EQ_INT(util_string_append(&path, "/tests_app.log"), STATUS_OK);
    return path;
}

/* Without SDL, app_run is the headless benchmark: 100 x 100 bodies on the mock window until its
   frame limit sends a quit, then a timing line. */
void test_app_run_benchmarks_headless_and_logs_next_to_the_executable(HammerCtx *t)
{
    util_string path = log_path(t);
    (void)util_fs_remove_file(util_string_c_str(&path));
    util_log_set_terminal(false);

    CHECK_EQ_INT(app_run(), 0);

    util_string text = util_string_make("");
    CHECK_EQ_INT(util_fs_read_file(util_string_c_str(&path), &text), STATUS_OK);
    CHECK(strstr(util_string_c_str(&text), "[INFO ] app/app.c:") != NULL);
    CHECK(strstr(util_string_c_str(&text), ": headless benchmark: n = 100, 10000 bodies\n") != NULL);
    CHECK(strstr(util_string_c_str(&text), ": 600 frames, ") != NULL);
    CHECK(strstr(util_string_c_str(&text), " ms per step\n") != NULL);
    /* util_random_subsystem started second and logged its seed */
    CHECK(strstr(util_string_c_str(&text), "util/random.c:") != NULL);
    CHECK(strstr(util_string_c_str(&text), ": random seed ") != NULL);

    util_log_set_terminal(true);
    (void)util_fs_remove_file(util_string_c_str(&path));
    util_string_destroy(&text);
    util_string_destroy(&path);
}
