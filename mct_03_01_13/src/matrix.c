#include <stdlib.h>
#include "matrix.h"

int create_matrix(matrix_t *matrix, const int rows, const int cols)
{
    matrix->rows = rows;
    matrix->cols = cols;

    matrix->values = malloc(matrix->rows * sizeof(int));

    if (matrix->values == NULL)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
