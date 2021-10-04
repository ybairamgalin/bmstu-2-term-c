#include <stdlib.h>
#include <check.h>
#include "../inc/check_arr_handle.h"
#include "../inc/arr_handle.h"

START_TEST (test_key_first_arg_null)
{
    const int arr_sz = 3;
    const int arr[arr_sz] = { 0, 1, 2 };

    int *p_start = NULL, *p_end = NULL;

    int rc = key(NULL, arr + arr_sz, &p_start, &p_end);

    ck_assert_int_ne(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST (test_key_second_arg_null)
{
    const int arr_sz = 3;
    const int arr[arr_sz] = { 0, 1, 2};

    int *p_start = NULL, *p_end = NULL;

    int rc = key(arr, NULL, &p_start, &p_end);

    ck_assert_int_ne(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST (test_key_pointers_order)
{
    const int arr_sz = 3;
    const int arr[arr_sz] = { 0, 1, 2};

    int *p_start = NULL, *p_end = NULL;

    int rc = key(arr + arr_sz, arr, &p_start, &p_end);

    ck_assert_int_ne(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST (test_key_non_int_pointer)
{
    const int arr_sz = 3;
    const int arr[arr_sz] = { 0, 1, 2};

    int *p_start = NULL, *p_end = NULL;

    int rc = key(arr, (const int *)((char *)arr + 1), &p_start, &p_end);

    ck_assert_int_ne(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST (test_key_src_one_elem)
{
    const int arr_sz = 1;
    const int arr[arr_sz] = { 0 };

    int *p_start = NULL, *p_end = NULL;

    int rc = key(arr, arr + arr_sz, &p_start, &p_end);

    ck_assert_int_ne(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST (test_key_src_two_elem)
{
    const int arr_sz = 2;
    const int arr[arr_sz] = { 0, 1 };

    int *p_start = NULL, *p_end = NULL;

    int rc = key(arr, arr + arr_sz, &p_start, &p_end);

    ck_assert_int_ne(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST (test_key_src_only_min_max)
{
    const int arr_sz = 3;
    const int arr[arr_sz] = { 0, 0, 1 };

    int *p_start = NULL, *p_end = NULL;

    int rc = key(arr, arr + arr_sz, &p_start, &p_end);

    ck_assert_int_ne(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST (test_key_src_only_min_max_reversed)
{
    const int arr_sz = 3;
    const int arr[arr_sz] = { 1, 1, 1 };

    int *p_start = NULL, *p_end = NULL;

    int rc = key(arr, arr + arr_sz, &p_start, &p_end);

    ck_assert_int_ne(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST (test_key_src_no_gap_min_max)
{
    const int arr_sz = 5;
    const int arr[arr_sz] = { 1, 2, 3, 4, 0 };

    int *p_start = NULL, *p_end = NULL;

    int rc = key(arr, arr + arr_sz, &p_start, &p_end);

    ck_assert_int_ne(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST (test_key_normal)
{
    const int arr_sz = 4;
    const int arr[arr_sz] = { 0, 1, 2, 3 };

    const int expected_lng = 2;
    const int expected[expected_lng] = { 1, 2 };

    int *p_start = NULL, *p_end = NULL;

    int rc = key(arr, arr + arr_sz, &p_start, &p_end);

    for (int i = 0; i < expected_lng; i++)
        ck_assert_int_eq(p_start[i], expected[i]);

    ck_assert_ptr_eq(p_start + expected_lng, p_end);
    ck_assert_int_eq(rc, EXIT_SUCCESS);

    free(p_start);
}
END_TEST

START_TEST (test_key_normal_reversed)
{
    const int arr_sz = 4;
    const int arr[arr_sz] = { 3, 2, 1, 0 };

    const int expected_lng = 2;
    const int expected[expected_lng] = { 2, 1 };

    int *p_start = NULL, *p_end = NULL;

    int rc = key(arr, arr + arr_sz, &p_start, &p_end);

    for (int i = 0; i < expected_lng; i++)
        ck_assert_int_eq(p_start[i], expected[i]);

    ck_assert_ptr_eq(p_start + expected_lng, p_end);
    ck_assert_int_eq(rc, EXIT_SUCCESS);

    free(p_start);
}
END_TEST

START_TEST (test_key_max_in_the_middle)
{
    const int arr_sz = 6;
    const int arr[arr_sz] = { 3, 3, 2, 3, 1, 0 };

    const int expected_lng = 2;
    const int expected[expected_lng] = { 2, 1 };

    int *p_start = NULL, *p_end = NULL;

    int rc = key(arr, arr + arr_sz, &p_start, &p_end);

    for (int i = 0; i < expected_lng; i++)
        ck_assert_int_eq(p_start[i], expected[i]);

    ck_assert_ptr_eq(p_start + expected_lng, p_end);
    ck_assert_int_eq(rc, EXIT_SUCCESS);

    free(p_start);
}
END_TEST

Suite *test_key_suite(void)
{
    Suite *s;

    s = suite_create("key");

    TCase *tc_pos;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_key_normal);
    tcase_add_test(tc_pos, test_key_normal_reversed);
    tcase_add_test(tc_pos, test_key_max_in_the_middle);

    suite_add_tcase(s, tc_pos);

    TCase *tc_neg;

    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_key_first_arg_null);
    tcase_add_test(tc_neg, test_key_second_arg_null);
    tcase_add_test(tc_neg, test_key_pointers_order);
    tcase_add_test(tc_neg, test_key_non_int_pointer);
    tcase_add_test(tc_neg, test_key_src_one_elem);
    tcase_add_test(tc_neg, test_key_src_two_elem);
    tcase_add_test(tc_neg, test_key_src_only_min_max);
    tcase_add_test(tc_neg, test_key_src_only_min_max_reversed);
    tcase_add_test(tc_neg, test_key_src_no_gap_min_max);


    suite_add_tcase(s, tc_neg);

    return s;
}

int run_check_arr_handle()
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
