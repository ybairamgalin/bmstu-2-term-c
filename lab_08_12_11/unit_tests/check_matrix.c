#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "check_matrix.h"
#include "matrix.h"

START_TEST(test_meatrix_det_normal)
{
    matrix_t matrix;

    create_matrix(&matrix, 3, 3);

    matrix.values[0][0] = 0.1;
    matrix.values[0][1] = 0.2;
    matrix.values[0][2] = -0.3;
    matrix.values[1][0] = 0.4;
    matrix.values[1][1] = 0.5;
    matrix.values[1][2] = 0.6;
    matrix.values[2][0] = 0.7;
    matrix.values[2][1] = 0.8;
    matrix.values[2][2] = 0.9;

    double result;
    matrix_det(matrix, &result);
    free_matrix(&matrix);

    ck_assert_double_eq_tol(0.018, result, EPS);
}
END_TEST

START_TEST(test_meatrix_det_2x2)
{
    matrix_t matrix;

    create_matrix(&matrix, 2, 2);

    matrix.values[0][0] = 5.1;
    matrix.values[0][1] = 0.9;
    matrix.values[1][0] = 1.1;
    matrix.values[1][1] = 0.01;

    double result;
    matrix_det(matrix, &result);
    free_matrix(&matrix);

    ck_assert_double_eq_tol(-0.93899999, result, EPS);
}
END_TEST

START_TEST(test_meatrix_det_1x1)
{
    matrix_t matrix;

    create_matrix(&matrix, 1, 1);

    matrix.values[0][0] = 7.89;

    double result;
    matrix_det(matrix, &result);
    free_matrix(&matrix);

    ck_assert_double_eq_tol(7.89, result, EPS);
}
END_TEST

START_TEST(test_add_matrix_normal)
{
    matrix_t matrix_1;
    matrix_t matrix_2;

    create_matrix(&matrix_1, 2, 3);
    create_matrix(&matrix_2, 2, 3);

    matrix_1.values[0][0] = 0.2;
    matrix_1.values[0][1] = 2.0;
    matrix_1.values[0][2] = -1.0;
    matrix_1.values[1][0] = -0.5;
    matrix_1.values[1][1] = 3.7;
    matrix_1.values[1][2] = 0.0;

    matrix_2.values[0][0] = 0.8;
    matrix_2.values[0][1] = 0.0;
    matrix_2.values[0][2] = -1.0;
    matrix_2.values[1][0] = 0.5;
    matrix_2.values[1][1] = 0.3;
    matrix_2.values[1][2] = 4.0;

    matrix_t result = add_matrix(matrix_1, matrix_2);

    ck_assert_double_eq_tol(result.values[0][0], 1.0, EPS);
    ck_assert_double_eq_tol(result.values[0][1], 2.0, EPS);
    ck_assert_double_eq_tol(result.values[0][2], -2.0, EPS);
    ck_assert_double_eq_tol(result.values[1][0], 0.0, EPS);
    ck_assert_double_eq_tol(result.values[1][1], 4.0, EPS);
    ck_assert_double_eq_tol(result.values[1][2], 4.0, EPS);

    free_matrix(&matrix_1);
    free_matrix(&matrix_2);
    free_matrix(&result);
}

START_TEST(test_add_matrix_one_col)
{
    matrix_t matrix_1;
    matrix_t matrix_2;

    create_matrix(&matrix_1, 2, 1);
    create_matrix(&matrix_2, 2, 1);

    matrix_1.values[0][0] = -0.1;
    matrix_1.values[1][0] = -0.2;

    matrix_2.values[0][0] = 0.1;
    matrix_2.values[1][0] = 0.2;

    matrix_t result = add_matrix(matrix_1, matrix_2);

    ck_assert_double_eq_tol(result.values[0][0], 0.0, EPS);
    ck_assert_double_eq_tol(result.values[1][0], 0.0, EPS);

    free_matrix(&matrix_1);
    free_matrix(&matrix_2);
    free_matrix(&result);
}

Suite *test_matrix_det_suite(void)
{
    Suite *suite;
    suite = suite_create("matrix_det");

    TCase *pos;
    pos = tcase_create("positive");

    tcase_add_test(pos, test_meatrix_det_normal);
    tcase_add_test(pos, test_meatrix_det_2x2);
    tcase_add_test(pos, test_meatrix_det_1x1);

    suite_add_tcase(suite, pos);

    return suite;
}

Suite *test_add_matrix_suite(void)
{
    Suite *suite;
    suite = suite_create("add_matrix");

    TCase *pos;
    pos = tcase_create("positive");
    tcase_add_test(pos, test_add_matrix_normal);
    tcase_add_test(pos, test_add_matrix_one_col);

    suite_add_tcase(suite, pos);

    return suite;
}

int run_check_matrix(void)
{
    int not_failed = 0;
    Suite *s;
    SRunner *runner;

    s = test_matrix_det_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    not_failed += srunner_ntests_failed(runner);

    s= test_add_matrix_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    not_failed += srunner_ntests_failed(runner);

    srunner_free(runner);

    return EXIT_SUCCESS;
}
