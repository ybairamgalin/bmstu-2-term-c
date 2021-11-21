#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

#define MAX_MATRICES 100

void shift_arr_right(matrix_t *matrices[MAX_MATRICES], const int from,
const int sz)
{
    for (int i = sz; i > from; i--)
        matrices[i] = matrices[i - 1];
}

void print_matrices(matrix_t *matrices[MAX_MATRICES], const int count)
{
    printf("\n");

    for (int i = 0; i < count; i++)
    {
        printf("Matrix %d\n", i);
        matrix_print(matrices[i]);
    }
}

void matrices_free(matrix_t *matrices[MAX_MATRICES], const int count)
{
    for (int i = 0; i < count; i++)
        matrix_free(matrices[i]);
}

int main(void)
{
    matrix_t *matrices[MAX_MATRICES];
    int count;
    printf("Enter number od matrices: ");

    if (scanf("%d", &count) != 1)
        return INPUT_ERR;

    if (count > (MAX_MATRICES / 2) || count < 0)
        return VALUE_ERR;

    for (int i = 0; i < count; i++)
    {
        matrices[i] = matrix_input();

        if (matrices[i] == NULL)
        {
            matrices_free(matrices, i);
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < count ; i += 2)
    {
        matrix_t *new = matrix_copy(matrices[i]);

        if (new == NULL)
        {
            matrices_free(matrices, count);
            return EXIT_FAILURE;
        }

        shift_arr_right(matrices, i, count);
        matrices[i + 1] = new;
        count++;

        size_t col_max = matrix_contains_max_col(matrices[i + 1]);
        size_t col_min = matrix_contains_min_col(matrices[i + 1]);
        matrix_swap_cols(matrices[i + 1], col_max, col_min);
    }

    print_matrices(matrices, count);
    matrices_free(matrices, count);

    return EXIT_SUCCESS;
}
