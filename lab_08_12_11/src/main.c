#include <stdlib.h>
#include <string.h>
#include "matrix.h"

#define ADDITION_CL_COUNT 5
#define MULTIPLICATION_CL_COUNT 5
#define DETERMINANT_CL_COUNT 4

int main(const int argc, const char **argv)
{
    int error;

    if (argc == ADDITION_CL_COUNT && strcmp(argv[1], "a") == 0)
    {
        if ((error = add_matrices_from_file(argv[2], argv[3], argv[4])) !=
        EXIT_SUCCESS)
            return error;
    }
    else if (argc == MULTIPLICATION_CL_COUNT && strcmp(argv[1], "m") == 0)
    {
        if ((error = multiply_matrices_from_file(argv[2], argv[3], argv[4])) !=
        EXIT_SUCCESS)
            return error;
    }
    else if (argc == DETERMINANT_CL_COUNT && strcmp(argv[1], "o") == 0)
    {
        if ((error = det_matrix_from_file(argv[2], argv[3])))
            return error;
    }
    else
        return INVALID_ARGS;

    return EXIT_SUCCESS;
}

