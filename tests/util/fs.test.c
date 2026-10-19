#include <string.h>

#include "hammerc.h"

#include "util/fs.h"
#include "util/string.h"

/* Every test works inside fs_test_tmp/ in the working directory (ctest: the build folder)
   and removes what it made. */
#define ROOT "fs_test_tmp"

/* Removes leftovers of an earlier, crashed run: files first, then folders deepest first. */
static void remove_all(const char *const *files, int file_count, const char *const *folders, int folder_count)
{
    for (int i = 0; i < file_count; i++) {
        (void)util_fs_remove_file(files[i]);
    }
    for (int i = 0; i < folder_count; i++) {
        (void)util_fs_remove_folder(folders[i]);
    }
}

static void read_back(HammerCtx *t, const char *path, const char *expected)
{
    util_string text = util_string_make("");
    CHECK_EQ_INT(util_fs_read_file(path, &text), STATUS_OK);
    CHECK_EQ_STR(util_string_c_str(&text), expected);
    util_string_destroy(&text);
}

void test_fs_exists_tells_files_from_folders(HammerCtx *t)
{
    const char *files[] = { ROOT "/file.txt" };
    const char *folders[] = { ROOT };
    remove_all(files, 1, folders, 1);
    REQUIRE_EQ_INT(util_fs_create_folder(ROOT), STATUS_OK);
    REQUIRE_EQ_INT(util_fs_create_file(ROOT "/file.txt"), STATUS_OK);

    CHECK(util_fs_file_exists(ROOT "/file.txt"));
    CHECK(!util_fs_folder_exists(ROOT "/file.txt"));
    CHECK(util_fs_folder_exists(ROOT));
    CHECK(!util_fs_file_exists(ROOT));
    CHECK(!util_fs_file_exists(ROOT "/missing.txt"));
    CHECK(!util_fs_folder_exists(ROOT "/missing"));
    CHECK(!util_fs_file_exists(NULL));
    CHECK(!util_fs_folder_exists(NULL));

    remove_all(files, 1, folders, 1);
    CHECK(!util_fs_folder_exists(ROOT));
}

void test_fs_create_file_does_not_truncate_existing_file(HammerCtx *t)
{
    const char *files[] = { ROOT "/keep.txt" };
    const char *folders[] = { ROOT };
    remove_all(files, 1, folders, 1);
    REQUIRE_EQ_INT(util_fs_create_folder(ROOT), STATUS_OK);

    CHECK_EQ_INT(util_fs_create_file(ROOT "/keep.txt"), STATUS_OK);
    read_back(t, ROOT "/keep.txt", "");
    CHECK_EQ_INT(util_fs_write_file(ROOT "/keep.txt", "content"), STATUS_OK);
    CHECK_EQ_INT(util_fs_create_file(ROOT "/keep.txt"), STATUS_ALREADY_EXISTS);
    read_back(t, ROOT "/keep.txt", "content");
    CHECK_EQ_INT(util_fs_create_file(ROOT), STATUS_ALREADY_EXISTS);
    CHECK_EQ_INT(util_fs_create_file(ROOT "/no_such_folder/x.txt"), STATUS_NOT_FOUND);
    CHECK_EQ_INT(util_fs_create_file(NULL), STATUS_INVALID_ARGUMENT);

    remove_all(files, 1, folders, 1);
}

void test_fs_create_folder_creates_parents(HammerCtx *t)
{
    const char *folders[] = { ROOT "/a/b/c", ROOT "/a/b", ROOT "/a", ROOT };
    remove_all(NULL, 0, folders, 4);

    CHECK_EQ_INT(util_fs_create_folder(ROOT "/a/b/c"), STATUS_OK);
    CHECK(util_fs_folder_exists(ROOT "/a"));
    CHECK(util_fs_folder_exists(ROOT "/a/b"));
    CHECK(util_fs_folder_exists(ROOT "/a/b/c"));
    CHECK_EQ_INT(util_fs_create_folder(ROOT "/a/b/c"), STATUS_ALREADY_EXISTS);
    CHECK_EQ_INT(util_fs_create_folder(ROOT "/a//b2/"), STATUS_OK);
    CHECK(util_fs_folder_exists(ROOT "/a/b2"));
    CHECK_EQ_INT(util_fs_create_folder(""), STATUS_INVALID_ARGUMENT);
    CHECK_EQ_INT(util_fs_create_folder(NULL), STATUS_INVALID_ARGUMENT);

    (void)util_fs_remove_folder(ROOT "/a/b2");
    remove_all(NULL, 0, folders, 4);
    CHECK(!util_fs_folder_exists(ROOT));
}

void test_fs_create_folder_fails_when_a_file_is_in_the_way(HammerCtx *t)
{
    const char *files[] = { ROOT "/blocker" };
    const char *folders[] = { ROOT };
    remove_all(files, 1, folders, 1);
    REQUIRE_EQ_INT(util_fs_create_folder(ROOT), STATUS_OK);
    REQUIRE_EQ_INT(util_fs_create_file(ROOT "/blocker"), STATUS_OK);

    CHECK_EQ_INT(util_fs_create_folder(ROOT "/blocker"), STATUS_ALREADY_EXISTS);
    CHECK(util_fs_create_folder(ROOT "/blocker/inner") != STATUS_OK);

    remove_all(files, 1, folders, 1);
}

void test_fs_write_then_read(HammerCtx *t)
{
    const char *files[] = { ROOT "/text.txt" };
    const char *folders[] = { ROOT };
    remove_all(files, 1, folders, 1);
    REQUIRE_EQ_INT(util_fs_create_folder(ROOT), STATUS_OK);

    CHECK_EQ_INT(util_fs_write_file(ROOT "/text.txt", "line one\nline two\n"), STATUS_OK);
    read_back(t, ROOT "/text.txt", "line one\nline two\n");
    CHECK_EQ_INT(util_fs_write_file(ROOT "/text.txt", "replaced"), STATUS_OK);
    read_back(t, ROOT "/text.txt", "replaced");
    CHECK_EQ_INT(util_fs_write_file(ROOT "/text.txt", NULL), STATUS_INVALID_ARGUMENT);
    CHECK_EQ_INT(util_fs_write_file(NULL, "x"), STATUS_INVALID_ARGUMENT);

    remove_all(files, 1, folders, 1);
}

void test_fs_append_adds_to_the_end(HammerCtx *t)
{
    const char *files[] = { ROOT "/log.txt" };
    const char *folders[] = { ROOT };
    remove_all(files, 1, folders, 1);
    REQUIRE_EQ_INT(util_fs_create_folder(ROOT), STATUS_OK);

    CHECK_EQ_INT(util_fs_append_file(ROOT "/log.txt", "first"), STATUS_OK);
    CHECK_EQ_INT(util_fs_append_file(ROOT "/log.txt", ", second"), STATUS_OK);
    read_back(t, ROOT "/log.txt", "first, second");

    remove_all(files, 1, folders, 1);
}

void test_fs_read_missing_file_leaves_string_unchanged(HammerCtx *t)
{
    util_string text = util_string_make("before");
    REQUIRE(util_string_valid(&text));
    CHECK_EQ_INT(util_fs_read_file(ROOT "/does_not_exist.txt", &text), STATUS_NOT_FOUND);
    CHECK_EQ_STR(util_string_c_str(&text), "before");
    CHECK_EQ_INT(util_fs_read_file(NULL, &text), STATUS_INVALID_ARGUMENT);
    util_string_destroy(&text);
}

void test_fs_read_file_larger_than_one_chunk(HammerCtx *t)
{
    const char *files[] = { ROOT "/big.txt" };
    const char *folders[] = { ROOT };
    remove_all(files, 1, folders, 1);
    REQUIRE_EQ_INT(util_fs_create_folder(ROOT), STATUS_OK);

    util_string big = util_string_make("");
    for (int i = 0; i < 1000; i++) {
        REQUIRE_EQ_INT(util_string_append(&big, "0123456789"), STATUS_OK);
    }
    CHECK_EQ_INT(util_fs_write_file(ROOT "/big.txt", util_string_c_str(&big)), STATUS_OK);
    util_string text = util_string_make("old");
    CHECK_EQ_INT(util_fs_read_file(ROOT "/big.txt", &text), STATUS_OK);
    CHECK_EQ_UINT(util_string_length(&text), 10000);
    CHECK(strcmp(util_string_c_str(&text), util_string_c_str(&big)) == 0);
    util_string_destroy(&text);
    util_string_destroy(&big);

    remove_all(files, 1, folders, 1);
}

void test_fs_remove_checks_what_is_there(HammerCtx *t)
{
    const char *files[] = { ROOT "/full/item.txt" };
    const char *folders[] = { ROOT "/full", ROOT };
    remove_all(files, 1, folders, 2);
    REQUIRE_EQ_INT(util_fs_create_folder(ROOT "/full"), STATUS_OK);
    REQUIRE_EQ_INT(util_fs_create_file(ROOT "/full/item.txt"), STATUS_OK);

    CHECK_EQ_INT(util_fs_remove_folder(ROOT "/full"), STATUS_IO_ERROR);
    CHECK_EQ_INT(util_fs_remove_file(ROOT "/full"), STATUS_NOT_FOUND);
    CHECK_EQ_INT(util_fs_remove_folder(ROOT "/full/item.txt"), STATUS_NOT_FOUND);
    CHECK_EQ_INT(util_fs_remove_file(ROOT "/full/item.txt"), STATUS_OK);
    CHECK(!util_fs_file_exists(ROOT "/full/item.txt"));
    CHECK_EQ_INT(util_fs_remove_file(ROOT "/full/item.txt"), STATUS_NOT_FOUND);
    CHECK_EQ_INT(util_fs_remove_folder(ROOT "/full"), STATUS_OK);
    CHECK_EQ_INT(util_fs_remove_folder(ROOT "/full"), STATUS_NOT_FOUND);
    CHECK_EQ_INT(util_fs_remove_file(NULL), STATUS_INVALID_ARGUMENT);
    CHECK_EQ_INT(util_fs_remove_folder(NULL), STATUS_INVALID_ARGUMENT);

    remove_all(files, 1, folders, 2);
}

void test_fs_executable_folder_holds_the_test_runner(HammerCtx *t)
{
    util_string folder = util_string_make("");
    REQUIRE_EQ_INT(util_fs_executable_folder(&folder), STATUS_OK);
    CHECK(util_string_length(&folder) > 0);
    CHECK(util_fs_folder_exists(util_string_c_str(&folder)));
    util_string runner = util_string_copy(&folder);
    CHECK_EQ_INT(util_string_append(&runner, "/tests_util"), STATUS_OK);
    util_string runner_exe = util_string_copy(&runner);
    CHECK_EQ_INT(util_string_append(&runner_exe, ".exe"), STATUS_OK);
    CHECK(util_fs_file_exists(util_string_c_str(&runner)) || util_fs_file_exists(util_string_c_str(&runner_exe)));
    util_string_destroy(&runner_exe);
    util_string_destroy(&runner);
    util_string_destroy(&folder);
}

void test_fs_executable_path_names_the_test_runner(HammerCtx *t)
{
    util_string path = util_string_make("");
    REQUIRE_EQ_INT(util_fs_executable_path(&path), STATUS_OK);
    CHECK(util_fs_file_exists(util_string_c_str(&path)));
    CHECK(strstr(util_string_c_str(&path), "tests_util") != NULL);
    util_string_destroy(&path);
}
