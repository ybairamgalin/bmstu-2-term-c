#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"

int create_matrix(matrix_t *matrix, const int cols, const int rows)
{
    matrix->cols = cols;
    matrix->rows = rows;

    matrix->values = malloc(matrix->rows * sizeof(double*));

    if (matrix->values == NULL)
        return EXIT_FAILURE;

    for (int i = 0; i < matrix->rows; i++)
    {
        matrix->values[i] = malloc(matrix->cols * sizeof(double));

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
        if (scanf("%lf", &matrix->values[row][i]) != 1)
            return INPUT_ERR;

    return EXIT_SUCCESS;
}

int input_matrix(matrix_t *matrix)
{
    int rows, cols;

    if (scanf("%d", &rows) != 1)
        return INPUT_ERR;

    if (rows <= 0)
        return INPUT_ERR;

    if (scanf("%d", &cols) != 1)
        return INPUT_ERR;

    if (cols <= 0)
        return INPUT_ERR;

    if (create_matrix(matrix, cols, rows) != EXIT_SUCCESS)
        return MEM_ERR;

    for (int i = 0; i < matrix->rows; i++)
        if (input_row(matrix, i) != EXIT_SUCCESS)
        {
            free_matrix(matrix);
            return INPUT_ERR;
        }

    return EXIT_SUCCESS;
}

int read_row_from_file(FILE *file, matrix_t *matrix, const int row)
{
    for (int i = 0; i < matrix->cols; i++)
        if (fscanf(file, "%lf", &matrix->values[row][i]) != 1)
            return FILE_FORMAT_ERR;

    return EXIT_SUCCESS;
}

int read_matrix_from_file(const char *filename, matrix_t *matrix)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
        return NO_SUCH_FILE_ERR;

    int rows, cols;

    if (fscanf(file, "%d", &rows) != 1)
    {
        fclose(file);
        return FILE_FORMAT_ERR;
    }

    if (rows <= 0)
    {
        fclose(file);
        return INPUT_ERR;
    }

    if (fscanf(file, "%d", &cols) != 1)
    {
        fclose(file);
        return FILE_FORMAT_ERR;
    }

    if (cols <= 0)
    {
        fclose(file);
        return INPUT_ERR;
    }

    if (create_matrix(matrix, cols, rows) != EXIT_SUCCESS)
    {
        fclose(file);
        return MEM_ERR;
    }

    for (int i = 0; i < matrix->cols; i++)
        if (read_row_from_file(file, matrix, i) != EXIT_SUCCESS)
        {
                fclose(file);
                return FILE_FORMAT_ERR;
        }

    fclose(file);

    return EXIT_SUCCESS;
}

int row_max_elem(const matrix_t matrix)
{
    double max = matrix.values[0][0];
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
    double max = matrix.values[0][0];
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

        matrix->values[i] = realloc(matrix->values[i], sizeof(double)
            * matrix->cols - 1);
    }

    (matrix->cols)--;
}

double max_in_row(const matrix_t matrix, const int row)
{
    double max = matrix.values[row][0];

    for (int i = 0; i < matrix.cols; i++)
        if (matrix.values[row][i] > max)
            max = matrix.values[row][i];

    return max;
}

void matrix_cpy(matrix_t *dest, const matrix_t src)
{
    dest->rows = src.rows;
    dest->cols = src.cols;

    for (int i = 0; i < src.rows; i++)
        for (int j = 0; j < src.cols; j++)
            dest->values[i][j] = src.values[i][j];
}

matrix_t multiply_matrix(const matrix_t first, const matrix_t second)
{
    matrix_t result;
    create_matrix(&result, second.cols, first.rows);

    for (int i = 0; i < result.rows; i++)
        for (int j = 0; j < result.cols; j++)
        {
            result.values[i][j] = 0;

            for (int k = 0; k < first.cols; k++)
                result.values[i][j] += first.values[i][k] * second.values[k][j];
        }

    return result;
}

int save_matrix_to_file(const char *filename, const matrix_t matrix)
{
    FILE *file = fopen(filename, "w");

    if (file == NULL)
        return NO_SUCH_FILE_ERR;

    fprintf(file, "%d %d\n", matrix.rows, matrix.cols);

    for (int i = 0; i < matrix.rows; i++)
    {
        fprintf(file, "%lf", matrix.values[i][0]);

        for (int j = 1; j < matrix.cols; j++)
            fprintf(file, " %lf", matrix.values[i][j]);

        fprintf(file, "\n");
    }

    fclose(file);

    return EXIT_SUCCESS;
}

double matrix_det(const matrix_t matrix, double *result)
{
    if (matrix.rows != matrix.cols)
        return EXIT_FAILURE;

    if (matrix.cols == 1)
    {
        *result = matrix.values[0][0];
        return EXIT_SUCCESS;
    }

    double res = 0;
    int sign = 1;

    for (int i = 0; i < matrix.cols; i++)
    {
        matrix_t complement;
        create_matrix(&complement, matrix.cols, matrix.rows);

        matrix_cpy(&complement, matrix);
        delete_matrix_row(&complement, 0);
        delete_matrix_col(&complement, i);

        double ith_det;
        matrix_det(complement, &ith_det);
        res += ith_det * matrix.values[0][i] * sign;

        free_matrix(&complement);
        sign *= -1;
    }

    *result = res;

    return EXIT_SUCCESS;
}

int save_num_to_file(const char *filename, const double num)
{
    FILE *file = fopen(filename, "w");

    if (file == NULL)
        return NO_SUCH_FILE_ERR;

    fprintf(file, "%lf\n", num);
    fclose(file);

    return EXIT_SUCCESS;
}

matrix_t add_matrix(const matrix_t first, const matrix_t second)
{
    matrix_t result;
    create_matrix(&result, first.cols, first.rows);

    for (int i = 0; i < first.rows; i++)
        for (int j = 0; j < first.cols; j++)
            result.values[i][j] = first.values[i][j] + second.values[i][j];

    return result;
}
