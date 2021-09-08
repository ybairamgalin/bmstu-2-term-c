#include <stdio.h>
#include <stdlib.h>
#include "movie.h"

int main(const int argc, const char *argv[])
{
    if (argc < MIN_COMMAND_LINE_ARGS || argc > MAX_COMMAND_LINE_ARGS)
        return ERR_COMMAND_LINE_ARGS_COUNT;

    movie films[MAX_FILMS];
    sort_by field;
    int num_of_films;
    int error;

    if ((field = set_field_from_str(argv[2])) == err)
        return ERR_COMMAND_LINE_ARGS_CONTENT;

    if ((error = read_movies_from_file(argv[1],
    films, &num_of_films, field, MAX_FILMS)) != OK)
        return error;

    if (argc == 3)
        print_movies(films, num_of_films);

    if (argc == 4)
    {
        movie found_film;
        error = find_movie_by_key(films, &found_film,
        num_of_films, field, argv[3]);

        if (error == ERR_MOVIE_NOT_FOUND)
        {
            printf("Not found\n");
        }
        else if (error != OK)
        {
            return error;
        }
        else
        {
            print_movies(&found_film, 1);
        }
    }

    return OK;
}
