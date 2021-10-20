#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(void)
{
    int error;
    matrix_t matrix;

    if ((error = input_matrix(&matrix)) != EXIT_SUCCESS)
        return error;

    print_matrix(matrix);
    printf("\n");
    make_square_matrix(&matrix);
    print_matrix(matrix);
    free_matrix(&matrix);

    return EXIT_SUCCESS;
}
