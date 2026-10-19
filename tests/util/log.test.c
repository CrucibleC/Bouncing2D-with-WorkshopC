#include <stdio.h>
#include <string.h>

#include "hammerc.h"

#include "util/fs.h"
#include "util/log.h"
#include "util/string.h"

/* The logger's settings are global: each test sets what it needs, and restore_defaults puts
   them back. Files go in log_test_tmp/ in the working directory (ctest: the build folder). */
#define ROOT "log_test_tmp"
#define LOG_FILE ROOT "/test.log"

static void start(HammerCtx *t)
{
    (void)util_fs_remove_file(LOG_FILE);
    (void)util_fs_remove_folder(ROOT);
    REQUIRE_EQ_INT(util_fs_create_folder(ROOT), STATUS_OK);
    util_log_set_terminal(false);
    util_log_set_min_level(UTIL_LOG_LEVEL_DEBUG);
    REQUIRE_EQ_INT(util_log_set_file(LOG_FILE), STATUS_OK);
}

static void finish(void)
{
    (void)util_log_set_file(NULL);
    util_log_set_terminal(true);
    util_log_set_min_level(UTIL_LOG_LEVEL_DEBUG);
    (void)util_fs_remove_file(LOG_FILE);
    (void)util_fs_remove_folder(ROOT);
}

static util_string read_log(HammerCtx *t)
{
    util_string text = util_string_make("");
    CHECK_EQ_INT(util_fs_read_file(LOG_FILE, &text), STATUS_OK);
    return text;
}

static int count_lines(const char *text)
{
    int lines = 0;
    for (const char *c = text; *c != '\0'; c++) {
        lines += *c == '\n';
    }
    return lines;
}

void test_log_writes_level_and_formatted_message(HammerCtx *t)
{
    start(t);
    UTIL_LOG_INFO("loaded %d bodies from %s", 42, "level.txt");
    UTIL_LOG_WARN("slow frame: %.1f ms", 20.5);
    util_string text = read_log(t);
    const char *log = util_string_c_str(&text);
    /* Between the level and the message comes the location, "log.test.c:<line>: " */
    CHECK(strstr(log, "[INFO ] ") != NULL);
    CHECK(strstr(log, ": loaded 42 bodies from level.txt\n") != NULL);
    CHECK(strstr(log, "[WARN ] ") != NULL);
    CHECK(strstr(log, ": slow frame: 20.5 ms\n") != NULL);
    CHECK_EQ_INT(count_lines(log), 2);
    /* "YYYY-MM-DD hh:mm:ss [" */
    CHECK(strlen(log) > 21 && log[4] == '-' && log[7] == '-' && log[13] == ':' && log[20] == '[');
    util_string_destroy(&text);
    finish();
}

void test_log_tags_every_level(HammerCtx *t)
{
    start(t);
    UTIL_LOG_DEBUG("d");
    UTIL_LOG_INFO("i");
    UTIL_LOG_WARN("w");
    UTIL_LOG_ERROR("e");
    util_string text = read_log(t);
    const char *log = util_string_c_str(&text);
    CHECK(strstr(log, "[DEBUG] ") != NULL && strstr(log, ": d\n") != NULL);
    CHECK(strstr(log, "[INFO ] ") != NULL && strstr(log, ": i\n") != NULL);
    CHECK(strstr(log, "[WARN ] ") != NULL && strstr(log, ": w\n") != NULL);
    CHECK(strstr(log, "[ERROR] ") != NULL && strstr(log, ": e\n") != NULL);
    util_string_destroy(&text);
    finish();
}

void test_log_min_level_drops_lower_levels(HammerCtx *t)
{
    start(t);
    util_log_set_min_level(UTIL_LOG_LEVEL_WARN);
    UTIL_LOG_DEBUG("dropped");
    UTIL_LOG_INFO("dropped");
    UTIL_LOG_WARN("kept");
    UTIL_LOG_ERROR("kept too");
    util_string text = read_log(t);
    const char *log = util_string_c_str(&text);
    CHECK(strstr(log, "dropped") == NULL);
    CHECK_EQ_INT(count_lines(log), 2);
    util_string_destroy(&text);
    finish();
}

void test_log_set_file_null_stops_file_output(HammerCtx *t)
{
    start(t);
    UTIL_LOG_INFO("before");
    CHECK_EQ_INT(util_log_set_file(NULL), STATUS_OK);
    UTIL_LOG_INFO("after");
    util_string text = read_log(t);
    const char *log = util_string_c_str(&text);
    CHECK(strstr(log, "before") != NULL);
    CHECK(strstr(log, "after") == NULL);
    util_string_destroy(&text);
    finish();
}

void test_log_cuts_long_messages(HammerCtx *t)
{
    start(t);
    char long_message[3000];
    memset(long_message, 'x', sizeof long_message - 1);
    long_message[sizeof long_message - 1] = '\0';
    UTIL_LOG_INFO("%s", long_message);
    util_string text = read_log(t);
    const char *log = util_string_c_str(&text);
    const char *message = strstr(log, "xxx");
    REQUIRE(message != NULL);
    CHECK_EQ_UINT(strlen(message), 1023 + 3 + 1); /* 1023 x's, "...", '\n' */
    CHECK(strstr(message, "x...\n") != NULL);
    util_string_destroy(&text);
    finish();
}

void test_log_set_file_failures_keep_the_old_file(HammerCtx *t)
{
    start(t);
    CHECK_EQ_INT(util_log_set_file(ROOT "/missing_folder/x.log"), STATUS_NOT_FOUND);
    char long_path[5000];
    memset(long_path, 'p', sizeof long_path - 1);
    long_path[sizeof long_path - 1] = '\0';
    CHECK_EQ_INT(util_log_set_file(long_path), STATUS_OUT_OF_RANGE);
    UTIL_LOG_INFO("still here");
    util_string text = read_log(t);
    CHECK(strstr(util_string_c_str(&text), "still here") != NULL);
    CHECK(!util_fs_folder_exists(ROOT "/missing_folder"));
    util_string_destroy(&text);
    finish();
}

void test_log_macros_add_file_and_line(HammerCtx *t)
{
    start(t);
    int line = __LINE__ + 1;
    UTIL_LOG_INFO("located");
    util_string text = read_log(t);
    char expected[128];
    snprintf(expected, sizeof expected, "log.test.c:%d: located\n", line);
    CHECK(strstr(util_string_c_str(&text), expected) != NULL);
    util_string_destroy(&text);
    finish();
}

void test_log_write_without_file_has_no_location(HammerCtx *t)
{
    start(t);
    util_log_write(UTIL_LOG_LEVEL_ERROR, NULL, 0, "no location %d", 7);
    util_string text = read_log(t);
    CHECK(strstr(util_string_c_str(&text), "[ERROR] no location 7\n") != NULL);
    util_string_destroy(&text);
    finish();
}

void test_log_shortens_paths_after_src(HammerCtx *t)
{
    start(t);
    util_log_write(UTIL_LOG_LEVEL_INFO, "C:\\code\\game\\src\\core\\world.c", 88, "win");
    util_log_write(UTIL_LOG_LEVEL_INFO, "/home/me/game/src/util/fs.c", 120, "posix");
    util_log_write(UTIL_LOG_LEVEL_INFO, "/home/me/resources/main.c", 5, "no src");
    util_string text = read_log(t);
    const char *log = util_string_c_str(&text);
    CHECK(strstr(log, "] core\\world.c:88: win\n") != NULL);
    CHECK(strstr(log, "] util/fs.c:120: posix\n") != NULL);
    CHECK(strstr(log, "] /home/me/resources/main.c:5: no src\n") != NULL);
    util_string_destroy(&text);
    finish();
}

void test_log_subsystem_logs_next_to_the_executable(HammerCtx *t)
{
    util_string path = util_string_make("");
    REQUIRE_EQ_INT(util_fs_executable_folder(&path), STATUS_OK);
    CHECK_EQ_INT(util_string_append(&path, "/tests_util.log"), STATUS_OK);
    (void)util_fs_remove_file(util_string_c_str(&path));
    util_log_set_terminal(false);

    util_singleton_subsystem log = util_log_subsystem();
    REQUIRE(log.init != NULL && log.shutdown != NULL);
    CHECK_EQ_INT(log.init(), STATUS_OK);
    UTIL_LOG_INFO("from init");
    log.shutdown();
    UTIL_LOG_INFO("after shutdown");

    util_string text = util_string_make("");
    CHECK_EQ_INT(util_fs_read_file(util_string_c_str(&path), &text), STATUS_OK);
    CHECK(strstr(util_string_c_str(&text), ": from init\n") != NULL);
    CHECK(strstr(util_string_c_str(&text), "after shutdown") == NULL);

    util_log_set_terminal(true);
    (void)util_fs_remove_file(util_string_c_str(&path));
    util_string_destroy(&text);
    util_string_destroy(&path);
}
