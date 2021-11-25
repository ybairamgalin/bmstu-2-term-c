#include <stdlib.h>
#include <check.h>
#include <stdio.h>
#include <linked_list.h>
#include "check_linked_list.h"

int int_cmp(const void *first, const void *second)
{
    int *fir = (int*)first;
    int *sec = (int*)second;

    if (*fir > *sec)
        return 1;

    if (*fir < *sec)
        return -1;

    return 0;
}

START_TEST(test_node_push_back_normal)
{
    char *data = "Some useful data";

    node_t *head = node_create(data);

    char *new_data = "New data";
    node_t *new = node_create(new_data);
    head = node_push_back(head, new);

    ck_assert_str_eq((char*)head->data, data);
    ck_assert_ptr_eq(head->next, new);

    ck_assert_str_eq((char*)head->next->data, new_data);
    ck_assert_ptr_null(head->next->next);

    node_free_all(head);
}
END_TEST

START_TEST(test_node_push_back_null)
{
    node_t *head = NULL;
    char *data = "Data";
    node_t *new = node_create(data);

    head = node_push_back(head, new);

    ck_assert_ptr_eq(head, new);

    node_free_all(head);
}
END_TEST

START_TEST(test_find_normal)
{
    int values[4] = { 1, 2, 3, 4};

    node_t *head = NULL;
    head = node_push_back(head, node_create(&values[0]));
    head = node_push_back(head, node_create(&values[1]));
    head = node_push_back(head, node_create(&values[2]));
    head = node_push_back(head, node_create(&values[3]));

    int to_find = 3;

    node_t *found = find(head, &to_find, int_cmp);

    ck_assert_int_eq(*(int*)found->data, 3);

    node_free_all(head);
}
END_TEST

START_TEST(test_find_no_element)
{
    int values[4] = { 1, 2, 3, 4};

    node_t *head = NULL;
    head = node_push_back(head, node_create(&values[0]));
    head = node_push_back(head, node_create(&values[1]));
    head = node_push_back(head, node_create(&values[2]));
    head = node_push_back(head, node_create(&values[3]));

    int to_find = -1;

    node_t *found = find(head, &to_find, int_cmp);

    ck_assert_ptr_null(found);

    node_free_all(head);
}
END_TEST

START_TEST(test_pop_front_normal)
{
    int values[4] = { 1, 2, 3, 4};

    node_t *head = NULL;
    head = node_push_back(head, node_create(&values[0]));
    head = node_push_back(head, node_create(&values[1]));
    head = node_push_back(head, node_create(&values[2]));
    head = node_push_back(head, node_create(&values[3]));

    int *data = pop_front(&head);

    ck_assert_int_eq(*data, 1);
    ck_assert_int_eq(*(int*)(head->data), 2);

    node_free_all(head);
}
END_TEST

START_TEST(test_copy_normal)
{
    int values[4] = { 1, 2, 3, 4};

    node_t *head = NULL;
    head = node_push_back(head, node_create(&values[0]));
    head = node_push_back(head, node_create(&values[1]));
    head = node_push_back(head, node_create(&values[2]));
    head = node_push_back(head, node_create(&values[3]));

    node_t *new_head;
    int rc = copy(head, &new_head);

    ck_assert_ptr_eq(head->data, new_head->data);
    ck_assert_ptr_eq(head->next->data, new_head->next->data);
    ck_assert_ptr_eq(new_head->next->next->data,
    new_head->next->next->data);
    ck_assert_ptr_eq(new_head->next->next->next->data,
    new_head->next->next->next->data);

    ck_assert_int_eq(rc, EXIT_SUCCESS);

    node_free_all(head);
    node_free_all(new_head);
}
END_TEST

START_TEST(test_front_back_split_even)
{
    int values[4] = { 1, 2, 3, 4};

    node_t *head = NULL;
    head = node_push_back(head, node_create(&values[0]));
    head = node_push_back(head, node_create(&values[1]));
    head = node_push_back(head, node_create(&values[2]));
    head = node_push_back(head, node_create(&values[3]));

    node_t *back;

    front_back_split(head, &back);

    ck_assert_int_eq(*(int*)head->data, 1);
    ck_assert_int_eq(*(int*)head->next->data, 2);
    ck_assert_int_eq(*(int*)back->data, 3);
    ck_assert_int_eq(*(int*)back->next->data, 4);

    ck_assert_ptr_null(head->next->next);
    ck_assert_ptr_null(back->next->next);

    node_free_all(head);
    node_free_all(back);
}
END_TEST

START_TEST(test_front_back_split_odd)
{
    int values[3] = { 1, 2, 3 };

    node_t *head = NULL;
    head = node_push_back(head, node_create(&values[0]));
    head = node_push_back(head, node_create(&values[1]));
    head = node_push_back(head, node_create(&values[2]));

    node_t *back;

    front_back_split(head, &back);

    ck_assert_int_eq(*(int*)head->data, 1);
    ck_assert_int_eq(*(int*)head->next->data, 2);
    ck_assert_int_eq(*(int*)back->data, 3);

    ck_assert_ptr_null(head->next->next);
    ck_assert_ptr_null(back->next);

    node_free_all(head);
    node_free_all(back);
}
END_TEST

START_TEST(test_front_back_split_one_elem)
{
    int values[1] = { 1 };

    node_t *head = NULL;
    head = node_push_back(head, node_create(&values[0]));

    node_t *back;

    front_back_split(head, &back);

    ck_assert_int_eq(*(int*)head->data, 1);

    ck_assert_ptr_null(head->next);
    ck_assert_ptr_null(back);

    node_free_all(head);
    node_free_all(back);
}
END_TEST

START_TEST(test_front_back_split_two_elems)
{
    int values[2] = { 1, 2 };

    node_t *head = NULL;
    head = node_push_back(head, node_create(&values[0]));
    head = node_push_back(head, node_create(&values[1]));

    node_t *back;

    front_back_split(head, &back);

    ck_assert_int_eq(*(int*)head->data, 1);
    ck_assert_int_eq(*(int*)back->data, 2);

    ck_assert_ptr_null(head->next);
    ck_assert_ptr_null(back->next);

    node_free_all(head);
    node_free_all(back);
}
END_TEST

START_TEST(test_sorted_merge_normal)
{
    int values[4] = { 1, 2, 3, 4 };

    node_t *first = NULL;
    first = node_push_back(first, node_create(&values[0]));
    first = node_push_back(first, node_create(&values[2]));

    node_t *second = NULL;

    second = node_push_back(second, node_create(&values[1]));
    second = node_push_back(second, node_create(&values[3]));

    node_t *sorted = sorted_merge(&first, &second, int_cmp);

    ck_assert_int_eq(*(int*)sorted->data, 1);
    ck_assert_int_eq(*(int*)sorted->next->data, 2);
    ck_assert_int_eq(*(int*)sorted->next->next->data, 3);
    ck_assert_int_eq(*(int*)sorted->next->next->next->data, 4);

    node_free_all(sorted);
}
END_TEST

START_TEST(test_sort_normal)
{
    int values[6] = { 5, 6, 3, 1, 2, 4};

    node_t *head = NULL;
    head = node_push_back(head, node_create(&values[0]));
    head = node_push_back(head, node_create(&values[1]));
    head = node_push_back(head, node_create(&values[2]));
    head = node_push_back(head, node_create(&values[3]));
    head = node_push_back(head, node_create(&values[4]));
    head = node_push_back(head, node_create(&values[5]));

    head = sort(head, int_cmp);

    ck_assert_int_eq(*(int*)head->data, 1);
    ck_assert_int_eq(*(int*)head->next->data, 2);
    ck_assert_int_eq(*(int*)head->next->next->data, 3);
    ck_assert_int_eq(*(int*)head->next->next->next->data, 4);
    ck_assert_int_eq(*(int*)head->next->next->next->next->data, 5);
    ck_assert_int_eq(*(int*)head->next->next->next->next->next->data, 6);

    node_free_all(head);
}
END_TEST

START_TEST(test_sort_repeated_values)
{
    int values[6] = { 0, 1, 1, 0, 0, 1};

    node_t *head = NULL;
    head = node_push_back(head, node_create(&values[0]));
    head = node_push_back(head, node_create(&values[1]));
    head = node_push_back(head, node_create(&values[2]));
    head = node_push_back(head, node_create(&values[3]));
    head = node_push_back(head, node_create(&values[4]));
    head = node_push_back(head, node_create(&values[5]));

    head = sort(head, int_cmp);

    ck_assert_int_eq(*(int*)head->data, 0);
    ck_assert_int_eq(*(int*)head->next->data, 0);
    ck_assert_int_eq(*(int*)head->next->next->data, 0);
    ck_assert_int_eq(*(int*)head->next->next->next->data, 1);
    ck_assert_int_eq(*(int*)head->next->next->next->next->data, 1);
    ck_assert_int_eq(*(int*)head->next->next->next->next->next->data, 1);

    node_free_all(head);
}
END_TEST

START_TEST(test_sort_one_elem)
{
    int values[1] = { 3 };

    node_t *head = NULL;
    head = node_push_back(head, node_create(&values[0]));

    head = sort(head, int_cmp);

    ck_assert_int_eq(*(int*)head->data, 3);

    node_free_all(head);
}
END_TEST

Suite *test_node_push_back(void)
{
    Suite *suite = suite_create("node_push_back");

    TCase *pos = tcase_create("positive");
    tcase_add_test(pos, test_node_push_back_normal);
    tcase_add_test(pos, test_node_push_back_null);
    suite_add_tcase(suite, pos);

    return suite;
}

Suite *test_find(void)
{
    Suite *suite = suite_create("find");

    TCase *pos = tcase_create("positive");
    tcase_add_test(pos, test_find_normal);
    tcase_add_test(pos, test_find_no_element);
    suite_add_tcase(suite, pos);

    return suite;
}

Suite *test_pop_front(void)
{
    Suite *suite = suite_create("pop_front");

    TCase *pos = tcase_create("positive");
    tcase_add_test(pos, test_pop_front_normal);
    suite_add_tcase(suite, pos);

    return suite;
}

Suite *test_copy(void)
{
    Suite *suite = suite_create("copy");

    TCase *pos = tcase_create("positive");
    tcase_add_test(pos, test_copy_normal);
    suite_add_tcase(suite, pos);

    return suite;
}

Suite *test_front_back_split(void)
{
    Suite *suite = suite_create("front_back_split");

    TCase *pos = tcase_create("positive");
    tcase_add_test(pos, test_front_back_split_even);
    tcase_add_test(pos, test_front_back_split_odd);
    tcase_add_test(pos, test_front_back_split_one_elem);
    tcase_add_test(pos, test_front_back_split_two_elems);
    suite_add_tcase(suite, pos);

    return suite;
}

Suite *test_sorted_merge(void)
{
    Suite *suite = suite_create("sorted_merge");

    TCase *pos = tcase_create("positive");
    tcase_add_test(pos, test_sorted_merge_normal);
    suite_add_tcase(suite, pos);

    return suite;
}

Suite *test_sort(void)
{
    Suite *suite = suite_create("sort");

    TCase *pos = tcase_create("positive");
    tcase_add_test(pos, test_sort_normal);
    tcase_add_test(pos, test_sort_repeated_values);
    tcase_add_test(pos, test_sort_one_elem);
    suite_add_tcase(suite, pos);

    return suite;
}


int run_suite(Suite *(test_suite)(void))
{
    Suite *s;
    SRunner *runner;

    s = test_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    int failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return failed;
}

int run_check_linked_list(void)
{
    int failed = 0;

    failed += run_suite(test_node_push_back);
    failed += run_suite(test_find);
    failed += run_suite(test_pop_front);
    failed += run_suite(test_copy);
    failed += run_suite(test_front_back_split);
    failed += run_suite(test_sorted_merge);
    failed += run_suite(test_sort);

    return failed;
}
