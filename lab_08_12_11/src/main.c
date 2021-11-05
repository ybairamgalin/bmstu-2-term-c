#include <stdlib.h>
#include <string.h>
#include "matrix.h"

int main(const int argc, const char **argv)
{
    int error;

    if (argc > 5 || argc < 4)
        return ARGS_COUNT_ERR;

    if (strcmp(argv[1], "a") == 0 && argc == 5)
    {
        if ((error = add_matrices_from_file(argv[2], argv[3], argv[4])) !=
        EXIT_SUCCESS)
            return error;
    }
    else if (strcmp(argv[1], "m") == 0 && argc == 5)
    {
        if ((error = multiply_matrices_from_file(argv[2], argv[3], argv[4])) !=
        EXIT_SUCCESS)
            return error;
    }
    else if (strcmp(argv[1], "o") == 0 && argc == 4)
    {
        if ((error = det_matrix_from_file(argv[2], argv[3])))
            return error;
    }
    else
        return INVALID_OPERATION;

    return EXIT_SUCCESS;
}

