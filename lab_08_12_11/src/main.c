#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

#define ARGS_COUNT_ERR 6
#define INVALID_OPERATION 7
#define WRONG_DIMS 8

int main(const int argc, const char **argv)
{
    int error;

    if (argc > 5 || argc < 4)
        return ARGS_COUNT_ERR;

    if (strcmp(argv[1], "a") == 0)
    {
        if (argc != 5)
            return ARGS_COUNT_ERR;

        matrix_t first, second;

        if ((error = read_matrix_from_file(argv[2], &first)) != EXIT_SUCCESS)
            return error;

        if ((error = read_matrix_from_file(argv[3], &second)) != EXIT_SUCCESS)
            return error;

        if (first.rows != second.rows || first.cols != second.rows)
            return WRONG_DIMS;

        matrix_t result = add_matrix(first, second);
        free_matrix(&first);
        free_matrix(&second);

        if ((error = save_matrix_to_file(argv[4], result)) != EXIT_SUCCESS)
        {
            free_matrix(&result);
            return error;
        }
    }
    else if (strcmp(argv[1], "m") == 0)
    {
        if (argc != 5)
            return ARGS_COUNT_ERR;

        matrix_t first, second;

        if ((error = read_matrix_from_file(argv[2], &first)) != EXIT_SUCCESS)
            return error;

        if ((error = read_matrix_from_file(argv[3], &second)) != EXIT_SUCCESS)
            return error;

        if (first.cols != second.rows)
            return WRONG_DIMS;

        matrix_t result = multiply_matrix(first, second);
        free_matrix(&first);
        free_matrix(&second);

        if ((error = save_matrix_to_file(argv[4], result)) != EXIT_SUCCESS)
        {
            free_matrix(&result);
            return error;
        }

        free_matrix(&result);
    }
    else if (strcmp(argv[1], "o") == 0)
    {
        if (argc != 4)
            return ARGS_COUNT_ERR;

        matrix_t matrix;
        long long det;

        if ((error = read_matrix_from_file(argv[2], &matrix)) != EXIT_SUCCESS)
            return error;

        if ((error = matrix_det(matrix, &det) != EXIT_SUCCESS))
        {
            free_matrix(&matrix);
            return error;
        }

        if ((error = save_num_to_file(argv[3], det)) != EXIT_SUCCESS)
        {
            free_matrix(&matrix);
            return error;
        }
    }
    else
    {
        return INVALID_OPERATION;
    }

	return EXIT_SUCCESS;
}

