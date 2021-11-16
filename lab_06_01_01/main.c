#include <stdio.h>
#include <stdlib.h>
#include "movie.h"

int main(const int argc, const char *argv[])
{
    if (argc < MIN_COMMAND_LINE_ARGS || argc > MAX_COMMAND_LINE_ARGS)
        return ERR_COMMAND_LINE_ARGS_COUNT;

    movie_t films[MAX_FILMS];
    sort_by_t field;
    int num_of_films;
    int error;

    if ((field = set_field_from_str(argv[2])) == err)
        return ERR_COMMAND_LINE_ARGS_CONTENT;

    if ((error = read_movies_from_file(argv[1],
    films, &num_of_films, field, MAX_FILMS)) != EXIT_SUCCESS)
        return error;

    if (argc == 3)
        print_movies(films, num_of_films);

    if (argc == 4)
        if ((error = print_movie_by_key(films, num_of_films, field,
        argv[3])) != EXIT_SUCCESS)
            return error;

    return EXIT_SUCCESS;
}
