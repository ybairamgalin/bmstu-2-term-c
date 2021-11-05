#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(void)
{
    int error;
    matrix_t matrix;

    if ((error = input_matrix(&matrix)) != EXIT_SUCCESS)
        return error;

    long long det;
    matrix_det(matrix, &det);
    printf("%lld\n", det);

	return EXIT_SUCCESS;
}

