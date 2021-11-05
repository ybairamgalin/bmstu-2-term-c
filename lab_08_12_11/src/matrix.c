#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"

int create_matrix(matrix_t *matrix, const int rows, const int cols)
{
    matrix->rows = rows;
    matrix->cols = cols;

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

    if (create_matrix(matrix, rows, cols) != EXIT_SUCCESS)
    {
        fclose(file);
        return MEM_ERR;
    }

    for (int i = 0; i < matrix->rows; i++)
        if (read_row_from_file(file, matrix, i) != EXIT_SUCCESS)
        {
            free_matrix(matrix);
            fclose(file);
            return FILE_FORMAT_ERR;
        }

    fclose(file);

    return EXIT_SUCCESS;
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

        matrix->values[i] = realloc(matrix->values[i], sizeof(double) *
            matrix->cols - 1);
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
    create_matrix(&result, first.rows, second.cols);

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

int matrix_det(const matrix_t matrix, double *result)
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

        if (create_matrix(&complement, matrix.rows,
        matrix.cols) != EXIT_SUCCESS)
        {
            return EXIT_FAILURE;
        }

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
    create_matrix(&result, first.rows, first.cols);

    for (int i = 0; i < first.rows; i++)
        for (int j = 0; j < first.cols; j++)
            result.values[i][j] = first.values[i][j] + second.values[i][j];

    return result;
}

int add_matrices_from_file(const char *filename_1, const char *filename_2,
const char *dest_file)
{
    int error;
    matrix_t first, second;

    if ((error = read_matrix_from_file(filename_1, &first)) != EXIT_SUCCESS)
        return error;

    if ((error = read_matrix_from_file(filename_2, &second)) != EXIT_SUCCESS)
    {
        free_matrix(&first);
        return error;
    }

    if (first.rows != second.rows || first.cols != second.cols)
    {
        free_matrix(&first);
        free_matrix(&second);
        return WRONG_DIMS;
    }

    matrix_t result = add_matrix(first, second);
    free_matrix(&first);
    free_matrix(&second);

    if ((error = save_matrix_to_file(dest_file, result)) != EXIT_SUCCESS)
    {
        free_matrix(&result);
        return error;
    }

    free_matrix(&result);

    return EXIT_SUCCESS;
}

int multiply_matrices_from_file(const char *filename_1, const char *filename_2,
const char *dest_file)
{
    int error;
    matrix_t first, second;

    if ((error = read_matrix_from_file(filename_1, &first)) != EXIT_SUCCESS)
        return error;

    if ((error = read_matrix_from_file(filename_2, &second)) != EXIT_SUCCESS)
    {
        free_matrix(&first);
        return error;
    }

    if (first.cols != second.rows)
    {
        free_matrix(&first);
        free_matrix(&second);
        return WRONG_DIMS;
    }

    matrix_t result = multiply_matrix(first, second);
    free_matrix(&first);
    free_matrix(&second);

    if ((error = save_matrix_to_file(dest_file, result)) != EXIT_SUCCESS)
    {
        free_matrix(&result);
        return error;
    }

    free_matrix(&result);

    return EXIT_SUCCESS;
}

int det_matrix_from_file(const char *filename, const char *dest_file)
{
    int error;
    matrix_t matrix;
    double det;

    if ((error = read_matrix_from_file(filename, &matrix)) != EXIT_SUCCESS)
        return error;

    if ((error = matrix_det(matrix, &det) != EXIT_SUCCESS))
    {
        free_matrix(&matrix);
        return error;
    }

    if ((error = save_num_to_file(dest_file, det)) != EXIT_SUCCESS)
    {
        free_matrix(&matrix);
        return error;
    }

    free_matrix(&matrix);

    return EXIT_SUCCESS;
}
