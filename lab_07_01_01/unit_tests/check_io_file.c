#include <stdlib.h>
#include <check.h>
#include "../inc/check_io_file.h"
#include "../inc/io_file.h"

START_TEST(test_get_number_of_int_in_file_six_nums)
{
    int received;
    int rc = get_number_of_int_in_file("func_tests/in_files/six_nums.txt",
        &received);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(received, 6);
}

Suite* get_number_of_int_in_file_suite(void)
{
    Suite *s;
    s = suite_create("get_number_of_int_in_file");

    TCase *tc_pos;

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_get_number_of_int_in_file_six_nums);

    suite_add_tcase(s, tc_pos);

    return s;
}

int run_check_io_file(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = get_number_of_int_in_file_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);

    srunner_free(runner);


    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
