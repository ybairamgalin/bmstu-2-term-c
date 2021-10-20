#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int create_matrix(matrix_t *matrix, const int cols, const int rows)
{
    matrix->cols = cols;
    matrix->rows = rows;

    matrix->values = malloc(matrix->rows * sizeof(int*));

    if (matrix->values == NULL)
        return EXIT_FAILURE;

    for (int i = 0; i < matrix->rows; i++)
    {
        matrix->values[i] = malloc(matrix->cols * sizeof(int));

        if (matrix->values[i] == NULL)
        {
            for (int j = i; j >= 0; j++)
                free(matrix->values[i]);

            free(matrix->values);

            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}

void free_matrix(matrix_t *matrix)
{
    for (int i = 0; i < matrix->rows; i++)
        free(matrix->values[i]);

    free(matrix->values);
}

int input_row(matrix_t *matrix, const int row)
{
    for (int i = 0; i < matrix->cols; i++)
        if (scanf("%d", &matrix->values[row][i]) != 1)
            return INPUT_ERR;

    return EXIT_SUCCESS;
}

int input_matrix(matrix_t *matrix)
{
    int cols, rows;

    if (scanf("%d%d", &rows, &cols) != 2)
        return INPUT_ERR;

    if (create_matrix(matrix, cols, rows) != EXIT_SUCCESS)
        return MEM_ERR;

    for (int i = 0; i < matrix->rows; i++)
        if (input_row(matrix, i) != EXIT_SUCCESS)
            return INPUT_ERR;

    return EXIT_SUCCESS;
}

int row_max_elem(const matrix_t matrix)
{
    int max = matrix.values[0][0];
    int max_index = 0;

    for (int i = 0; i < matrix.rows; i++)
        for (int j = 0; j < matrix.cols; j++)
            if (matrix.values[i][j] > max)
            {
                max = matrix.values[i][j];
                max_index = i;
            }

    return max_index;
}

int col_max_elem(const matrix_t matrix)
{
    int max = matrix.values[0][0];
    int max_index = 0;

    for (int i = 0; i < matrix.rows; i++)
        for (int j = 0; j < matrix.cols; j++)
            if (matrix.values[i][j] > max)
            {
                max = matrix.values[i][j];
                max_index = j;
            }

    return max_index;
}

void delete_matrix_row(matrix_t *matrix, const int row)
{
    free(matrix->values[row]);

    for (int i = row; i < matrix->rows - 1; i++)
        matrix->values[i] = matrix->values[i + 1];

    (matrix->rows)--;
}

void delete_matrix_col(matrix_t *matrix, const int col)
{
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = col; j < matrix->cols - 1; j++)
            matrix->values[i][j] = matrix->values[i][j + 1];

        matrix->values[i] = realloc(matrix->values[i], sizeof(int) * matrix->cols - 1);
    }

    (matrix->cols)--;
}

void make_square_matrix(matrix_t *matrix)
{
    while (matrix->rows != matrix->cols)
    {
        if (matrix->rows > matrix->cols)
        {
            int to_del_row = row_max_elem(*matrix);
            delete_matrix_row(matrix, to_del_row);
        }
        else if (matrix->rows < matrix->cols)
        {
            int to_del_col = col_max_elem(*matrix);
            delete_matrix_col(matrix, to_del_col);
        }
    }
}

void print_matrix(const matrix_t matrix)
{
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.cols; j++)
            printf("%d ", matrix.values[i][j]);

        printf("\n");
    }
}