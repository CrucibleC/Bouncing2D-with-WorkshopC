#include "hammerc.h"

#include "util/singleton.h"

/* Each init and shutdown records a letter (uppercase: init, lowercase: shutdown), so a test can
   check which ran and in what order. */
static char g_calls[16];
static int g_call_count;

static void record(char letter)
{
    if (g_call_count < (int)sizeof g_calls - 1) {
        g_calls[g_call_count++] = letter;
        g_calls[g_call_count] = '\0';
    }
}

static void reset_calls(void)
{
    g_call_count = 0;
    g_calls[0] = '\0';
}

static status init_a(void) { record('A'); return STATUS_OK; }
static status init_b(void) { record('B'); return STATUS_OK; }
static status init_c(void) { record('C'); return STATUS_OK; }
static status init_fails(void) { record('X'); return STATUS_IO_ERROR; }
static void shutdown_a(void) { record('a'); }
static void shutdown_b(void) { record('b'); }
static void shutdown_c(void) { record('c'); }
static void shutdown_x(void) { record('x'); }

void test_singleton_subsystem_pod_starts_not_started(HammerCtx *t)
{
    util_singleton_subsystem subsystem = util_singleton_subsystem_pod(init_a, shutdown_a);
    CHECK(subsystem.init == init_a);
    CHECK(subsystem.shutdown == shutdown_a);
    CHECK_EQ_INT(subsystem.result, STATUS_INVALID_STATE);
}

void test_singleton_subsystem_starts_in_order_and_shuts_down_in_reverse(HammerCtx *t)
{
    util_singleton_subsystem subsystems[3] = {
        util_singleton_subsystem_pod(init_a, shutdown_a),
        util_singleton_subsystem_pod(init_b, shutdown_b),
        util_singleton_subsystem_pod(init_c, shutdown_c),
    };
    util_singleton_subsystem_span span = util_singleton_subsystem_span_pod(subsystems, 3);
    reset_calls();
    CHECK_EQ_INT(util_singleton_subsystem_init_all(span), STATUS_OK);
    CHECK_EQ_INT(subsystems[0].result, STATUS_OK);
    CHECK_EQ_INT(subsystems[2].result, STATUS_OK);
    util_singleton_subsystem_shutdown_all(span);
    CHECK_EQ_STR(g_calls, "ABCcba");
    CHECK_EQ_INT(subsystems[0].result, STATUS_INVALID_STATE);
}

void test_singleton_subsystem_failure_shuts_down_only_what_started(HammerCtx *t)
{
    util_singleton_subsystem subsystems[3] = {
        util_singleton_subsystem_pod(init_a, shutdown_a),
        util_singleton_subsystem_pod(init_fails, shutdown_x),
        util_singleton_subsystem_pod(init_c, shutdown_c),
    };
    util_singleton_subsystem_span span = util_singleton_subsystem_span_pod(subsystems, 3);
    reset_calls();
    CHECK_EQ_INT(util_singleton_subsystem_init_all(span), STATUS_IO_ERROR);
    CHECK_EQ_INT(subsystems[0].result, STATUS_OK);
    CHECK_EQ_INT(subsystems[1].result, STATUS_IO_ERROR);
    CHECK_EQ_INT(subsystems[2].result, STATUS_INVALID_STATE);
    util_singleton_subsystem_shutdown_all(span);
    /* C never started; the failed one is not shut down; only A is undone */
    CHECK_EQ_STR(g_calls, "AXa");
}

void test_singleton_subsystem_null_init_and_shutdown_are_skipped(HammerCtx *t)
{
    util_singleton_subsystem subsystems[2] = {
        util_singleton_subsystem_pod(NULL, shutdown_a),
        util_singleton_subsystem_pod(init_b, NULL),
    };
    util_singleton_subsystem_span span = util_singleton_subsystem_span_pod(subsystems, 2);
    reset_calls();
    CHECK_EQ_INT(util_singleton_subsystem_init_all(span), STATUS_OK);
    util_singleton_subsystem_shutdown_all(span);
    /* no init counts as started, so its shutdown still runs */
    CHECK_EQ_STR(g_calls, "Ba");
}

void test_singleton_subsystem_shutdown_twice_is_harmless(HammerCtx *t)
{
    util_singleton_subsystem subsystems[1] = { util_singleton_subsystem_pod(init_a, shutdown_a) };
    util_singleton_subsystem_span span = util_singleton_subsystem_span_pod(subsystems, 1);
    reset_calls();
    CHECK_EQ_INT(util_singleton_subsystem_init_all(span), STATUS_OK);
    util_singleton_subsystem_shutdown_all(span);
    util_singleton_subsystem_shutdown_all(span);
    CHECK_EQ_STR(g_calls, "Aa");
}

void test_singleton_subsystem_empty_and_null_spans_do_nothing(HammerCtx *t)
{
    reset_calls();
    CHECK_EQ_INT(util_singleton_subsystem_init_all(util_singleton_subsystem_span_pod(NULL, 3)), STATUS_OK);
    util_singleton_subsystem_shutdown_all(util_singleton_subsystem_span_pod(NULL, 3));
    util_singleton_subsystem subsystems[1] = { util_singleton_subsystem_pod(init_a, shutdown_a) };
    CHECK_EQ_INT(util_singleton_subsystem_init_all(util_singleton_subsystem_span_pod(subsystems, 0)), STATUS_OK);
    util_singleton_subsystem_shutdown_all(util_singleton_subsystem_span_pod(subsystems, 0));
    CHECK_EQ_STR(g_calls, "");
}
