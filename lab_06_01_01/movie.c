#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"

sort_by set_field_from_str(const char *str)
{
    sort_by result;

    if (strcmp(str, "title") == 0)
    {
        result = title;
    }
    else if (strcmp(str, "name") == 0)
    {
        result = name;
    }
    else if (strcmp(str, "year") == 0)
    {
        result = year;
    }
    else
    {
        result = err;
    }

    return result;
}

void print_movies(const movie *films, const int sz)
{
    for (int i = 0; i < sz; i++)
        printf("%s\n%s\n%d\n", films[i].title, films[i].name, films[i].year);
}

int cmp_film_with_key(const movie film,
const sort_by field, const char *key, int *result)
{
    if (field == title)
    {
        *result = strcmp(key, film.title);
    }
    else if (field == name)
    {
        *result = strcmp(key, film.name);
    }
    else if (field == year)
    {
        int date;

        if ((date = atoi(key)) == 0)
            return ERR_KEY_CANNOT_BE_READ;

        *result = date - film.year;
    }
    else
        return ERR_UNKNOWN;

    return OK;
}

int get_index_by_field_and_key(const movie *films, const int num_of_films,
const sort_by field, const char *key, int *result)
{
    int left = 0, right = num_of_films - 1, center;

    while (left <= right)
    {
        center = (left + right) / 2;

        int cmp;
        int error;

        if ((error = cmp_film_with_key(films[center], field, key, &cmp)) != OK)
            return error;

        if (cmp < 0)
        {
            right = center - 1;
        }
        else if (cmp > 0)
        {
            left = center + 1;
        }
        else
        {
            *result = center;

            return OK;
        }
    }

    return ERR_MOVIE_NOT_FOUND;
}

int find_movie_by_key(const movie *films, movie *found, const int num_of_films,
const sort_by field, const char *key)
{
    if (key == NULL)
        return ERR_COMMAND_LINE_ARGS_CONTENT;

    if (strlen(key) == 0)
        return ERR_KEY_CANNOT_BE_READ;

    int index;
    int error;

    if ((error = get_index_by_field_and_key(films, num_of_films, field,
    key, &index)) != OK)
        return error;

    *found = films[index];

    return OK;
}
