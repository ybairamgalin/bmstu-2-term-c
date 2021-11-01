#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

int create_matrix(matrix_t *matrix, const int rows, const int cols)
{
    matrix->rows = rows;
    matrix->cols = cols;

    matrix->values = malloc(matrix->rows * sizeof(int*));

    if (matrix->values == NULL)
        return EXIT_FAILURE;

    for (size_t i = 0; i < rows; i++)
    {
        matrix->values[i] = malloc(matrix->cols * sizeof(int));

        if (matrix->values[i] == NULL)
        {
            for (size_t j = 0; j < i; i++)
                free(matrix->values[j]);

            free(matrix->values);

            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}

void free_matrix(matrix_t *matrix)
{
    if (matrix == NULL)
        return;

    for (size_t i = 0; i < matrix->rows; i++)
        free(matrix->values[i]);

    free(matrix->values);
}

int input_matrix(matrix_t *matrix)
{
    int rows, cols;
    printf("Input rows: ");

    if (scanf("%d", &rows) != 1)
        return EXIT_FAILURE;

    if (rows <= 0)
        return EXIT_FAILURE;

    printf("Input cols: ");

    if (scanf("%d", &cols) != 1)
        return EXIT_FAILURE;

    if (cols <= 0)
        return EXIT_FAILURE;

    if (create_matrix(matrix, rows, cols) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    printf("Input matrix");

    for (size_t i = 0; i < matrix->rows; i++)
        for (size_t j = 0; j < matrix->cols; j++)
            if (scanf("%d", &matrix->values[i][j]) != 1)
            {
                free_matrix(matrix);
                return EXIT_FAILURE;
            }

    return EXIT_SUCCESS;
}

int input_multiple_matrix(matrix_t *matrix, size_t *sz)
{
    printf("Input number of matrix: ");

    if (scanf("%d", sz) != 1)
        return EXIT_FAILURE;

    if (*sz <= 0)
        return EXIT_FAILURE;

    matrix = malloc(*sz * sizeof(matrix_t));

    if (matrix == NULL)
        return EXIT_FAILURE;

    for (size_t i = 0; i < *sz; i++)
    {
        if (input_matrix(&matrix[i]) != EXIT_SUCCESS)
            return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
