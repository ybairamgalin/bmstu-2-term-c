#include <stdlib.h>
#include <check.h>
#include "../inc/check_arr_handle.h"
#include "../inc/arr_handle.h"

START_TEST (test_key_first_arg_null)
{
    const int arr_sz = 3;
    const int arr[3] = { 0, 1, 2 };

    int *p_start = NULL, *p_end = NULL;

    int rc = key(NULL, arr + arr_sz, &p_start, &p_end);

    ck_assert_int_ne(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST (test_key_second_arg_null)
{
    const int arr[3] = { 0, 1, 2};
    int *p_start = NULL, *p_end = NULL;

    int rc = key(arr, NULL, &p_start, &p_end);

    ck_assert_int_ne(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST (test_key_pointers_order)
{
    const int arr_sz = 3;
    const int arr[3] = { 0, 1, 2};

    int *p_start = NULL, *p_end = NULL;

    int rc = key(arr + arr_sz, arr, &p_start, &p_end);

    ck_assert_int_ne(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST (test_key_non_int_pointer)
{
    const int arr[3] = { 0, 1, 2};

    int *p_start = NULL, *p_end = NULL;

    int rc = key(arr, (const int *)((char *)arr + 1), &p_start, &p_end);

    ck_assert_int_ne(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST (test_key_src_one_elem)
{
    const int arr_sz = 1;
    const int arr[1] = { 0 };

    int *p_start = NULL, *p_end = NULL;

    int rc = key(arr, arr + arr_sz, &p_start, &p_end);

    ck_assert_int_ne(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST (test_key_src_two_elem)
{
    const int arr_sz = 2;
    const int arr[2] = { 0, 1 };

    int *p_start = NULL, *p_end = NULL;

    int rc = key(arr, arr + arr_sz, &p_start, &p_end);

    ck_assert_int_ne(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST (test_key_src_only_min_max)
{
    const int arr_sz = 3;
    const int arr[3] = { 0, 0, 1 };

    int *p_start = NULL, *p_end = NULL;

    int rc = key(arr, arr + arr_sz, &p_start, &p_end);

    ck_assert_int_eq(rc, EXIT_SUCCESS);

    free(p_start);
}
END_TEST

START_TEST (test_key_src_same_elem)
{
    const int arr_sz = 3;
    const int arr[3] = { 1, 1, 1 };

    int *p_start = NULL, *p_end = NULL;

    int rc = key(arr, arr + arr_sz, &p_start, &p_end);

    ck_assert_int_ne(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST (test_key_src_no_gap_min_max)
{
    const int arr_sz = 5;
    const int arr[5] = { 1, 2, 3, 4, 0 };

    int *p_start = NULL, *p_end = NULL;

    int rc = key(arr, arr + arr_sz, &p_start, &p_end);

    ck_assert_int_ne(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST (test_key_normal)
{
    const int arr_sz = 4;
    const int arr[4] = { 0, 1, 2, 3 };

    const int expected_lng = 2;
    const int expected[2] = { 1, 2 };

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
    const int arr[4] = { 3, 2, 1, 0 };

    const int expected_lng = 2;
    const int expected[2] = { 2, 1 };

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
    tcase_add_test(tc_pos, test_key_src_only_min_max);

    suite_add_tcase(s, tc_pos);

    TCase *tc_neg;

    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_key_first_arg_null);
    tcase_add_test(tc_neg, test_key_second_arg_null);
    tcase_add_test(tc_neg, test_key_pointers_order);
    tcase_add_test(tc_neg, test_key_non_int_pointer);
    tcase_add_test(tc_neg, test_key_src_one_elem);
    tcase_add_test(tc_neg, test_key_src_two_elem);
    tcase_add_test(tc_neg, test_key_src_same_elem);
    tcase_add_test(tc_neg, test_key_src_no_gap_min_max);


    suite_add_tcase(s, tc_neg);

    return s;
}


START_TEST (test_mysort_normal)
{
    int arr_sz = 4;
    int arr[4] = { 4, 1, 2, 3 };

    const int expected_lng = 4;
    const int expected[4] = { 1, 2, 3, 4 };

    mysort(arr, arr_sz, sizeof(int), int_cmp);

    for (int i = 0; i < expected_lng; i++)
        ck_assert_int_eq(arr[i], expected[i]);
}
END_TEST

START_TEST (test_mysort_reversed)
{
    int arr_sz = 4;
    int arr[4] = { 4, 3, 2, 1 };

    const int expected_lng = 4;
    const int expected[4] = { 1, 2, 3, 4 };

    mysort(arr, arr_sz, sizeof(int), int_cmp);

    for (int i = 0; i < expected_lng; i++)
        ck_assert_int_eq(arr[i], expected[i]);
}
END_TEST

START_TEST (test_mysort_same_elements)
{
    int arr_sz = 4;
    int arr[4] = { 1, 0, 1, 0 };

    const int expected_lng = 4;
    const int expected[4] = { 0, 0, 1, 1 };

    mysort(arr, arr_sz, sizeof(int), int_cmp);

    for (int i = 0; i < expected_lng; i++)
        ck_assert_int_eq(arr[i], expected[i]);
}
END_TEST


Suite *test_mysort_suite(void )
{
    Suite *s;

    s = suite_create("mysort");

    TCase *tc_pos;
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_mysort_normal);
    tcase_add_test(tc_pos, test_mysort_reversed);
    tcase_add_test(tc_pos, test_mysort_same_elements);

    suite_add_tcase(s, tc_pos);

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
    srunner_free(runner);

    no_failed += srunner_ntests_failed(runner);

    s = test_mysort_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    srunner_free(runner);

    no_failed += srunner_ntests_failed(runner);

    return 0;
}
