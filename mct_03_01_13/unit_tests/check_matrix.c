#include <stdlib.h>
#include <check.h>
#include "matrix.h"

START_TEST(swap_cols_normal)
{
    matrix_t *matrix = matrix_alloc(2, 3);

    matrix->values[0][0] = 0;
    matrix->values[0][1] = 1;
    matrix->values[0][2] = 2;
    matrix->values[1][0] = 3;
    matrix->values[1][1] = 4;
    matrix->values[1][2] = 5;

    matrix_swap_cols(matrix, 0, 2);

    ck_assert_int_eq(matrix->values[0][0], 2);
    ck_assert_int_eq(matrix->values[0][1], 1);
    ck_assert_int_eq(matrix->values[0][2], 0);
    ck_assert_int_eq(matrix->values[1][0], 5);
    ck_assert_int_eq(matrix->values[1][1], 4);
    ck_assert_int_eq(matrix->values[1][2], 3);

    matrix_free(matrix);
}
END_TEST

START_TEST(swap_cols_1x1)
{
    matrix_t *matrix = matrix_alloc(1, 1);

    matrix->values[0][0] = 10;

    matrix_swap_cols(matrix, 0, 0);

    ck_assert_int_eq(matrix->values[0][0], 10);

    matrix_free(matrix);
}
END_TEST

Suite *test_matrix_swap_cols()
{
    Suite *suite = suite_create("matrix_swap_cols");

    TCase *pos = tcase_create("positive");
    tcase_add_test(pos, swap_cols_normal);
    tcase_add_test(pos, swap_cols_1x1);
    suite_add_tcase(suite, pos);

    return suite;
}

int run_check_matrix()
{
    int failed = 0;

    SRunner *runner = srunner_create(test_matrix_swap_cols());
    srunner_run_all(runner, CK_VERBOSE);
    failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    return failed;
}
