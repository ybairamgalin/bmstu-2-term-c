#include <stdlib.h>
#include "matrix.h"

int main(void)
{
    matrix_t *multiple_matrix = NULL;
    size_t sz;

    if (input_multiple_matrix(multiple_matrix, &sz) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    for (size_t i = 0; i < sz; i++)
        free_matrix(&multiple_matrix[i]);

    return EXIT_SUCCESS;
}
