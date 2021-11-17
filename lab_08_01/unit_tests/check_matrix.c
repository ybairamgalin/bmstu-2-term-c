#include <check.h>
#include "check_matrix.h"
#include "matrix.h"

START_TEST(test_multiply_3x3)
{
    matrix_t matrix_1;
    matrix_t matrix_2;

    create_matrix(&matrix_1, 3, 3);
    create_matrix(&matrix_2, 3, 3);

    matrix_1.values[0][0] = 1;
    matrix_1.values[0][1] = 2;
    matrix_1.values[0][2] = 3;
    matrix_1.values[1][0] = 4;
    matrix_1.values[1][1] = 5;
    matrix_1.values[1][2] = 6;
    matrix_1.values[2][0] = 7;
    matrix_1.values[2][1] = 8;
    matrix_1.values[2][2] = 9;

    matrix_2.values[0][0] = -1;
    matrix_2.values[0][1] = -2;
    matrix_2.values[0][2] = -3;
    matrix_2.values[1][0] = -4;
    matrix_2.values[1][1] = -5;
    matrix_2.values[1][2] = -6;
    matrix_2.values[2][0] = -7;
    matrix_2.values[2][1] = -8;
    matrix_2.values[2][2] = -9;

    matrix_t result = multiply_matrix(matrix_1, matrix_2);

    ck_assert_int_eq(result.values[0][0], -30);
    ck_assert_int_eq(result.values[0][1], -36);
    ck_assert_int_eq(result.values[0][2], -42);
    ck_assert_int_eq(result.values[1][0], -66);
    ck_assert_int_eq(result.values[1][1], -81);
    ck_assert_int_eq(result.values[1][2], -96);
    ck_assert_int_eq(result.values[2][0], -102);
    ck_assert_int_eq(result.values[2][1], -126);
    ck_assert_int_eq(result.values[2][2], -150);

    free_matrix(&matrix_1);
    free_matrix(&matrix_2);
    free_matrix(&result);
}
END_TEST

START_TEST(test_del_row_3x3)
{
    matrix_t matrix;

    create_matrix(&matrix, 3, 3);

    matrix.values[0][0] = 1;
    matrix.values[0][1] = 2;
    matrix.values[0][2] = 3;
    matrix.values[1][0] = 4;
    matrix.values[1][1] = 5;
    matrix.values[1][2] = 6;
    matrix.values[2][0] = 7;
    matrix.values[2][1] = 8;
    matrix.values[2][2] = 9;

    delete_matrix_row(&matrix, 1);

    ck_assert_int_eq(matrix.rows, 2);
    ck_assert_int_eq(matrix.cols, 3);

    ck_assert_int_eq(matrix.values[0][0], 1);
    ck_assert_int_eq(matrix.values[0][1], 2);
    ck_assert_int_eq(matrix.values[0][2], 3);

    ck_assert_int_eq(matrix.values[1][0], 7);
    ck_assert_int_eq(matrix.values[1][1], 8);
    ck_assert_int_eq(matrix.values[1][2], 9);

    free_matrix(&matrix);
}
END_TEST

START_TEST(test_del_row_3x1)
{
    matrix_t matrix;

    create_matrix(&matrix, 3, 1);

    matrix.values[0][0] = 1;
    matrix.values[1][0] = 2;
    matrix.values[2][0] = 3;

    delete_matrix_row(&matrix, 0);

    ck_assert_int_eq(matrix.rows, 2);
    ck_assert_int_eq(matrix.cols, 1);

    ck_assert_int_eq(matrix.values[0][0], 2);
    ck_assert_int_eq(matrix.values[1][0], 3);

    free_matrix(&matrix);
}
END_TEST

Suite *test_multiply_matrix(void)
{
    Suite *suite;
    suite = suite_create("multiply_matrix");

    TCase *pos;
    pos = tcase_create("positive");

    tcase_add_test(pos, test_multiply_3x3);

    suite_add_tcase(suite, pos);

    return suite;
}

Suite *test_delete_matrix_row(void)
{
    Suite *suite;
    suite = suite_create("delete_matrix_row");

    TCase *pos;
    pos = tcase_create("positive");

    tcase_add_test(pos, test_del_row_3x3);
    tcase_add_test(pos, test_del_row_3x1);

    suite_add_tcase(suite, pos);

    return suite;
}

int run_check_matrix(void)
{
    int failed = 0;
    Suite *s;
    SRunner *runner;

    s = test_multiply_matrix();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    failed += srunner_ntests_failed(runner);

    srunner_free(runner);

    s = test_delete_matrix_row();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    failed += srunner_ntests_failed(runner);

    srunner_free(runner);

    return failed;
}