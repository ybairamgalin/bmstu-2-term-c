#include <stdlib.h>
#include <check.h>
#include "check_my_string.h"
#include "my_string.h"

START_TEST(test_my_string_create_normal)
{
    char *str = "Some fancy string";

    my_string_t *string = my_string_create(str);

    ck_assert_int_eq(strlen(str) * sizeof(char) + 1, string->data_sz);
    ck_assert_ptr_eq(string->data, string->string_head->data);
    ck_assert_ptr_eq(string->data + NODE_LNG, string->string_head->next->data);
    ck_assert_ptr_eq(string->data + NODE_LNG * 2,
                     string->string_head->next->next->data);
    ck_assert_ptr_eq(string->data + NODE_LNG * 3,
                     string->string_head->next->next->next->data);
    ck_assert_ptr_eq(string->data + NODE_LNG * 4,
                     string->string_head->next->next->next->next->data);
    ck_assert_ptr_null(string->string_head->next->next->next->next->next);

    my_string_free(string);
}
END_TEST

START_TEST(test_my_string_concat_normal)
{
    char *str1 = "First";
    char *str2 = "Second";

    my_string_t *string1 = my_string_create(str1);
    my_string_t *string2 = my_string_create(str2);

    string1 = my_string_concat(string1, string2);

    ck_assert_int_eq(string1->data_sz, 12);

    my_string_free(string1);
    my_string_free(string2);
}

Suite *test_my_string_create(void)
{
    Suite *suite = suite_create("my_string_create");

    TCase *pos = tcase_create("positive");
    tcase_add_test(pos, test_my_string_create_normal);
    suite_add_tcase(suite, pos);

    return suite;
}

Suite *test_my_string_concat(void)
{
    Suite *suite = suite_create("my_string_concat");

    TCase *pos = tcase_create("positive");
    tcase_add_test(pos, test_my_string_concat_normal);
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

int run_check_my_string(void)
{
    int failed = 0;
    failed += run_suite(test_my_string_create);
    failed += run_suite(test_my_string_concat);

    return failed;
}