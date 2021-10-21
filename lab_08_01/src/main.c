#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(void)
{
    int error;
    matrix_t matrix_1, matrix_2;

    if ((error = input_matrix(&matrix_1)) != EXIT_SUCCESS)
        return error;

    if ((error = input_matrix(&matrix_2)) != EXIT_SUCCESS)
    {
        free_matrix(&matrix_1);
        return error;
    }

    int first_pow, second_pow;

    if ((error = input_powers(&first_pow, &second_pow)) != EXIT_SUCCESS)
    {
        free_matrix(&matrix_1);
        free_matrix(&matrix_2);
        return error;
    }

    make_square_matrix(&matrix_1);
    make_square_matrix(&matrix_2);
    expand_matrix(&matrix_1, MAX(matrix_1.cols, matrix_2.cols));
    expand_matrix(&matrix_2, MAX(matrix_1.cols, matrix_2.cols));

    matrix_t raised_matrix_1 = pow_matrix(matrix_1, first_pow);
    free_matrix(&matrix_1);
    matrix_t raised_matrix_2 = pow_matrix(matrix_2, second_pow);
    free_matrix(&matrix_2);

    matrix_t result = multiply_matrix(raised_matrix_1, raised_matrix_2);
    free_matrix(&raised_matrix_1);
    free_matrix(&raised_matrix_2);

    print_matrix(result);
    free_matrix(&result);

    return EXIT_SUCCESS;
}

