#include <stdlib.h>
#include <check.h>
#include "../inc/arr_handle.h"

START_TEST (test_key_normal)
{
    const int src_lng = 5;
    const int arr[src_lng] = { 5, 6, 7, 8, 0 };

    const int expected_lng = 2;
    int expected[expected_lng] = { 6, 7 };

    int *res_start = NULL, *res_end = NULL;

    key(arr, arr + src_lng, &res_start, &res_end);

    ck_assert_int_eq(expected[0], res_start[0]);
    ck_assert_int_eq(expected[1], res_start[1]);

    ck_assert_ptr_eq(res_end, res_start + expected_lng);

    free(res_start);
}
END_TEST

START_TEST (test_key_one_elem)
{
    const int src_lng = 5;
    const int arr[src_lng] = { 0, 0, 0, 1, 5 };

    const int expected_lng = 1;
    int expected[expected_lng] = { 1 };

    int *res_start = NULL, *res_end = NULL;

    key(arr, arr + src_lng, &res_start, &res_end);

    ck_assert_int_eq(expected[0], res_start[0]);

    ck_assert_ptr_eq(res_end, res_start + expected_lng);

    free(res_start);
}
END_TEST

START_TEST (test_key_whole_array)
{
    const int src_lng = 5;
    const int arr[src_lng] = { 0, 1, 2, 3, 4 };
    const int expected_lng = 3;
    int expected[expected_lng] = { 1, 2, 3 };


    int *res_start = NULL, *res_end = NULL;

    key(arr, arr + src_lng, &res_start, &res_end);

    ck_assert_int_eq(expected[0], res_start[0]);
    ck_assert_int_eq(expected[1], res_start[1]);
    ck_assert_int_eq(expected[2], res_start[2]);

    ck_assert_ptr_eq(res_end, res_start + expected_lng);

    free(res_start);
}
END_TEST

START_TEST (test_key_null_pointer)
{
    int rc = key(NULL, NULL, NULL, NULL);

    ck_assert_int_ne(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST (test_key_eq_elements)
{
    const int src_lng = 5;
    const int arr[src_lng] = { 0, 0, 0, 0, 0 };

    int *res_start = NULL, *res_end = NULL;

    int rc = key(arr, arr + src_lng, &res_start, &res_end);

    ck_assert_int_ne(rc, EXIT_SUCCESS);

    free(res_start);
}
END_TEST

START_TEST (test_key_same_pointer)
{
    const int src_lng = 5;
    const int arr[src_lng] = { 0, 1, 2, 3, 4 };

    int *res_start = NULL, *res_end = NULL;

    int rc = key(arr, arr, &res_start, &res_end);

    ck_assert_int_ne(rc, EXIT_SUCCESS);

    free(res_start);
}
END_TEST

Suite *test_key_suite(void)
{
    Suite *s;

    s = suite_create("key");

    TCase *tc_pos;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_key_normal);
    tcase_add_test(tc_pos, test_key_one_elem);
    tcase_add_test(tc_pos, test_key_whole_array);

    suite_add_tcase(s, tc_pos);

    TCase *tc_neg;

    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_key_null_pointer);
    tcase_add_test(tc_neg, test_key_eq_elements);
    tcase_add_test(tc_neg, test_key_same_pointer);

    suite_add_tcase(s, tc_neg);

    return s;
}

int main()
{
    int no_failed = 0;
    struct Suite *s;
    SRunner *runner;

    s = test_key_suite();

    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    return 0;
}
