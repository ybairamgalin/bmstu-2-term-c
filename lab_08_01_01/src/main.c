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
        return error;

    make_square_matrix(&matrix_1);
    make_square_matrix(&matrix_2);
    print_matrix(matrix_1);
    printf("\n");
    print_matrix(matrix_2);
    printf("\n");
    expand_matrix(&matrix_1, 3);
    print_matrix(matrix_1);
    printf("\n");

    matrix_t result = multiply_matrix(matrix_1, matrix_2);
    print_matrix(result);
    printf("\n");

    free_matrix(&matrix_1);
    free_matrix(&matrix_2);
    free_matrix(&result);

    return EXIT_SUCCESS;
}

//2 3
//4 7 1
//3 2 7
//5 3
//0 2 9
//1 2 2
//3 3 3
//8 8 2
//1 8 3