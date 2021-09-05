#include <stdio.h>
#include <stdlib.h>
#include "movie.h"

int main(const int argc, const char *argv[])
{
    if (argc >= MIN_COMMAND_LINE_ARGS && argc <= MAX_COMMAND_LINE_ARGS)
    {
        movie films[MAX_FIlMS];
        int num_of_films;
        int error;
        sort_by field;

        if ((field = set_field_from_str(argv[2])) == err)
            return ERR_COMMAND_LINE_ARGS_CONTENT;

        if ((error = read_movies_from_file(argv[1],
                films, &num_of_films, field)) != 0)
            return error;

        if (num_of_films == 0)
            return ERR_FILE_IS_EMPTY;
    }
    else
        return ERR_COMMAND_LINE_ARGS_COUNT;

    if (argc == 3)
    {

    }

    return OK;
}
