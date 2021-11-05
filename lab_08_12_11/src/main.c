#include <stdlib.h>
#include <string.h>
#include "matrix.h"

int main(const int argc, const char **argv)
{
    int error;

    if (argc == 5 && strcmp(argv[1], "a") == 0)
    {
        if ((error = add_matrices_from_file(argv[2], argv[3], argv[4])) !=
        EXIT_SUCCESS)
            return error;
    }
    else if (argc == 5 && strcmp(argv[1], "m") == 0)
    {
        if ((error = multiply_matrices_from_file(argv[2], argv[3], argv[4])) !=
        EXIT_SUCCESS)
            return error;
    }
    else if (argc == 4 && strcmp(argv[1], "o") == 0)
    {
        if ((error = det_matrix_from_file(argv[2], argv[3])))
            return error;
    }
    else
        return INVALID_ARGS;

    return EXIT_SUCCESS;
}

