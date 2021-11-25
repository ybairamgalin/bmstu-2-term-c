#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

void matrix_free(matrix_t *matrix)
{
    for (size_t i = 0; i < matrix->rows; i++)
        free(matrix->values[i]);

    free(matrix->values);
    free(matrix);
}

matrix_t *matrix_alloc(const size_t rows, const size_t cols)
{
    matrix_t *matrix;
    matrix = malloc(sizeof(matrix_t));

    if (matrix == NULL)
        return NULL;

    matrix->rows = 0;
    matrix->cols = cols;
    matrix->values = malloc(sizeof(int*) * rows);

    if (matrix->values == NULL)
    {
        matrix_free(matrix);
        return NULL;
    }

    for (size_t i = 0; i < rows; i++)
    {
        matrix->values[i] = malloc(sizeof(int) * matrix->cols);
        (matrix->rows)++;

        if (matrix->values[i] == NULL)
        {
            for (size_t j = 0; j < i; i++)
                free(matrix->values[j]);

            free(matrix->values);
        }
    }

    return matrix;
}

matrix_t *matrix_input()
{
    int cols, rows;
    printf("Input rows and cols: ");

    if (scanf("%d%d", &rows, &cols) != 2)
        return NULL;

    if (rows <= 0 || cols <= 0)
        return NULL;

    matrix_t *matrix = matrix_alloc(rows, cols);

    if (matrix == NULL)
        return NULL;

    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
        {
            printf("Input next element (row=%lu, col=%lu): ", i, j);

            if (scanf("%d", &matrix->values[i][j]) != 1)
            {
                matrix_free(matrix);
                return NULL;
            }
        }

    return matrix;
}

size_t matrix_contains_max_col(matrix_t *matrix)
{
    int max_elem = matrix->values[0][0];
    size_t res = 0;

    for (size_t i = 0; i < matrix->rows; i++)
        for (size_t j = 0; j < matrix->cols; j++)
            if (matrix->values[i][j] > max_elem)
            {
                max_elem = matrix->values[i][j];
                res = j;
            }

    return res;
}

size_t matrix_contains_min_col(matrix_t *matrix)
{
    int max_elem = matrix->values[0][0];
    size_t res = 0;

    for (size_t i = 0; i < matrix->rows; i++)
        for (size_t j = 0; j < matrix->cols; j++)
            if (matrix->values[i][j] < max_elem)
            {
                max_elem = matrix->values[i][j];
                res = j;
            }

    return res;
}

matrix_t *matrix_copy(matrix_t *old)
{
    matrix_t *new = matrix_alloc(old->rows, old->cols);

    if (new == NULL)
        return NULL;

    for (size_t i = 0; i < old->rows; i++)
        for (size_t j = 0; j < old->cols; j++)
            new->values[i][j] = old->values[i][j];

    return new;
}

void matrix_print(matrix_t *matrix)
{
    for (size_t i = 0; i < matrix->rows; i++)
    {
        printf("%d", matrix->values[i][0]);

        for (size_t j = 1; j < matrix->cols; j++)
            printf(" %d", matrix->values[i][j]);

        printf("\n");
    }
}

void matrix_swap_cols(matrix_t *matrix, const size_t first,
const size_t second)
{
    for (size_t i = 0; i < matrix->rows; i++)
    {
        int tmp = matrix->values[i][first];
        matrix->values[i][first] = matrix->values[i][second];
        matrix->values[i][second] = tmp;
    }
}
