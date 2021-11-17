#include <stdlib.h>
#include <check.h>
#include "check_my_string.h"
#include "my_string.h"

START_TEST(test_my_string_create_normal)
{
    char *str = "Some text";

    my_string_t *string = my_string_create(str);

    ck_assert(string->head->data[0] == 'S');
    ck_assert(string->head->data[1] == 'o');
    ck_assert(string->head->data[2] == 'm');
    ck_assert(string->head->data[3] == 'e');

    ck_assert(string->head->next->data[0] == ' ');
    ck_assert(string->head->next->data[1] == 't');
    ck_assert(string->head->next->data[2] == 'e');
    ck_assert(string->head->next->data[3] == 'x');

    ck_assert(string->head->next->next->data[0] == 't');
    ck_assert(string->head->next->next->data[1] == '\0');
    ck_assert(string->head->next->next->data[2] == '\0');
    ck_assert(string->head->next->next->data[3] == '\0');

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

    ck_assert(string1->head->data[0] == 'F');
    ck_assert(string1->head->data[1] == 'i');
    ck_assert(string1->head->data[2] == 'r');
    ck_assert(string1->head->data[3] == 's');

    ck_assert(string1->head->next->data[0] == 't');
    ck_assert(string1->head->next->data[1] == '\0');
    ck_assert(string1->head->next->data[2] == '\0');
    ck_assert(string1->head->next->data[3] == '\0');

    ck_assert(string1->head->next->next->data[0] == 'S');
    ck_assert(string1->head->next->next->data[1] == 'e');
    ck_assert(string1->head->next->next->data[2] == 'c');
    ck_assert(string1->head->next->next->data[3] == 'o');

    ck_assert(string1->head->next->next->next->data[0] == 'n');
    ck_assert(string1->head->next->next->next->data[1] == 'd');
    ck_assert(string1->head->next->next->next->data[2] == '\0');
    ck_assert(string1->head->next->next->next->data[3] == '\0');

    my_string_free(string1);
}
END_TEST

START_TEST(test_my_string_concat_little_str)
{
    char *str1 = "F";
    char *str2 = "S";

    my_string_t *string1 = my_string_create(str1);
    my_string_t *string2 = my_string_create(str2);

    string1 = my_string_concat(string1, string2);

    ck_assert(string1->head->data[0] == 'F');
    ck_assert(string1->head->data[1] == '\0');
    ck_assert(string1->head->data[2] == '\0');
    ck_assert(string1->head->data[3] == '\0');

    ck_assert(string1->head->next->data[0] == 'S');
    ck_assert(string1->head->next->data[1] == '\0');
    ck_assert(string1->head->next->data[2] == '\0');
    ck_assert(string1->head->next->data[3] == '\0');

    my_string_free(string1);
}
END_TEST

START_TEST(test_my_string_del_spaces_normal)
{
    char *str = "S  pa   c es";

    my_string_t *string = my_string_create(str);

    string = my_string_del_spaces(string);

    ck_assert(string->head->data[0] == 'S');
    ck_assert(string->head->data[1] == '\0');
    ck_assert(string->head->data[2] == ' ');
    ck_assert(string->head->data[3] == 'p');

    ck_assert(string->head->next->data[0] == 'a');
    ck_assert(string->head->next->data[1] == '\0');
    ck_assert(string->head->next->data[2] == '\0');
    ck_assert(string->head->next->data[3] == ' ');

    ck_assert(string->head->next->next->data[0] == 'c');
    ck_assert(string->head->next->next->data[1] == ' ');
    ck_assert(string->head->next->next->data[2] == 'e');
    ck_assert(string->head->next->next->data[3] == 's');

    ck_assert(string->head->next->next->next->data[0] == '\0');
    ck_assert(string->head->next->next->next->data[1] == '\0');
    ck_assert(string->head->next->next->next->data[2] == '\0');
    ck_assert(string->head->next->next->next->data[3] == '\0');

    my_string_free(string);
}
END_TEST

START_TEST(test_my_string_find_normal)
{
    char *str = "String with info";
    char *to_find = "with";

    my_string_t *string = my_string_create(str);
    int index = my_string_find(string, to_find);

    ck_assert_int_eq(index, 7);

    my_string_free(string);
}
END_TEST

START_TEST(test_my_string_find_whole_string)
{
    char *str = "Cars and planes";
    char *to_find = "Cars and planes";

    my_string_t *string = my_string_create(str);
    int index = my_string_find(string, to_find);

    ck_assert_int_eq(index, 0);

    my_string_free(string);
}
END_TEST

START_TEST(test_my_string_find_not_found)
{
    char *str = "Cars and planes";
    char *to_find = "cow";

    my_string_t *string = my_string_create(str);
    int index = my_string_find(string, to_find);

    ck_assert_int_eq(index, -1);

    my_string_free(string);
}
END_TEST

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
    tcase_add_test(pos, test_my_string_concat_little_str);
    suite_add_tcase(suite, pos);

    return suite;
}

Suite *test_my_string_del_spaces(void)
{
    Suite *suite = suite_create("my_string_del_spaces");

    TCase *pos = tcase_create("positive");
    tcase_add_test(pos, test_my_string_del_spaces_normal);
    suite_add_tcase(suite, pos);

    return suite;
}

Suite *test_my_string_find(void)
{
    Suite *suite = suite_create("my_string_find");

    TCase *pos = tcase_create("positive");
    tcase_add_test(pos, test_my_string_find_normal);
    tcase_add_test(pos, test_my_string_find_whole_string);
    suite_add_tcase(suite, pos);

    TCase *neg = tcase_create("negative");
    tcase_add_test(neg, test_my_string_find_not_found);

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
//    failed += run_suite(test_my_string_del_spaces);
//    failed += run_suite(test_my_string_find);

    return failed;
}