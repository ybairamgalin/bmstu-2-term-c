#include <stdlib.h>
#include <stdio.h>
#include "movies.h"
#include "movie.h"

#define MIN_ARGC 3
#define MAX_ARGC 4

#define ARGC_ERR 1

int main(const int argc, const char **argv)
{
    int error;

    if (argc < MIN_ARGC || argc > MAX_ARGC)
        return ARGC_ERR;

    field_t field;

    if (str_to_field(&field, argv[2]) != EXIT_SUCCESS)
        return FIELD_ERR;

    movies_t *movies = movies_create();

    if (movies == NULL)
        return MEM_ERR;

    if ((error = movies_read(argv[1], movies, field)) != EXIT_SUCCESS)
        return error;

    if (argc == 3)
        movies_print(movies);

    if (argc == 4)
        if ((error = movies_print_by_field(movies, field,
        argv[3])) != EXIT_SUCCESS)
            return error;

    movies_free(movies);

    return EXIT_SUCCESS;
}
