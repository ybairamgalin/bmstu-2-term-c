#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#include "read_movies.h"
#include "insert_movie.h"

int read_movie_title_from_file(FILE *file, movie *film)
{
    if (fgets(film->title, sizeof(film->title), file) == NULL)
        return ERR_NOTHING_TO_READ;

    if (film->title[strlen(film->title) - 1] != '\n')
        return ERR_MAX_STRING_LNG;

    film->title[strlen(film->title) - 1] = '\0';

    if (strlen(film->title) == 0)
        return ERR_EMPTY_STRING;

    return OK;
}

int read_name_from_file(FILE *file, movie *film)
{
    if (fgets(film->name, sizeof(film->name), file) == NULL)
        return ERR_FILE_STRUCT_NAME;

    if (film->name[strlen(film->name) - 1] != '\n')
        return ERR_MAX_STRING_LNG;

    film->name[strlen(film->name) - 1] = '\0';

    if (strlen(film->name) == 0)
        return ERR_EMPTY_STRING;

    return OK;
}

int read_year_from_file(FILE *file, movie *film)
{
    char tmp_year[MAX_YEAR_LNG + 1];

    if (fgets(tmp_year, sizeof(tmp_year), file) == NULL)
        return ERR_FILE_STRUCT_YEAR;

    if (strchr(tmp_year, '.') != NULL || strchr(tmp_year, ',') != NULL)
        return ERR_FILE_STRUCT_YEAR;

    if ((film->year = atoi(tmp_year)) == 0)
        return ERR_FILE_STRUCT_YEAR;

    if (film->year <= 0)
        return ERR_FILE_STRUCT_YEAR;

    return OK;
}

int read_movie_from_file(FILE *file, movie *film)
{
    int error;

    if ((error = read_movie_title_from_file(file, film)) != OK)
        return error;

    if ((error = read_name_from_file(file, film)) != OK)
        return error;

    if ((error = read_year_from_file(file, film)) != OK)
        return error;

    return OK;
}

int read_movies_from_file(const char *filename, movie *films,
int *num_of_films, const sort_by field, const int max_films)
{
    FILE *file = fopen(filename, "r");
    *num_of_films = 0;

    if (file == NULL)
        return ERR_NO_SUCH_FILE;

    int error;
    movie film;

    while ((error = read_movie_from_file(file, &film)) == OK)
        if ((error = insert_elem_in_arr_by_key(films, film, (*num_of_films)++,
        field)) != OK)
            return error;

    if (error != ERR_NOTHING_TO_READ)
        return error;

    if (*num_of_films == 0)
        return ERR_FILE_IS_EMPTY;

    fclose(file);

    return OK;
}
