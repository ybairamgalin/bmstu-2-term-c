#include <stdlib.h>
#include <check.h>
#include "queue.h"

START_TEST(test_enqueue_normal)
{
    my_queue_t *queue = enqueue(NULL, 5);

    ck_assert_int_eq(queue->head->value, 5);

    destruct_queue(queue);
}
END_TEST

START_TEST(test_enqueue_double)
{
    my_queue_t *queue = enqueue(NULL, 5);
    queue = enqueue(queue, 6);

    ck_assert_int_eq(queue->head->value, 6);
    ck_assert_int_eq(queue->head->prev->value, 5);

    destruct_queue(queue);
}
END_TEST

START_TEST(test_dequeue_normal)
{
    my_queue_t *queue = enqueue(NULL, 5);
    queue = enqueue(queue, 6);

    int res;
    queue = dequeue(queue, &res);

    ck_assert_int_eq(res, 5);

    destruct_queue(queue);
}
END_TEST

Suite *suite_dequeue(void)
{
    Suite *s = suite_create("dequeue");

    TCase *pos = tcase_create("positive");
    tcase_add_test(pos, test_dequeue_normal);

    suite_add_tcase(s, pos);

    return s;
}

Suite *suite_enqueue(void)
{
    Suite *s = suite_create("enqueue");

    TCase *pos = tcase_create("positive");
    tcase_add_test(pos, test_enqueue_normal);
    tcase_add_test(pos, test_enqueue_double);

    suite_add_tcase(s, pos);

    return s;
}

int run_suite(Suite *(test_suite)(void))
{
    Suite *s = test_suite();
    SRunner *runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    int failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return failed;
}

int run_queue_tests(void)
{
    int failed = 0;

    failed += run_suite(suite_enqueue);
    failed += run_suite(suite_dequeue);

    return failed;
}
