#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"

sort_by_t set_field_from_str(const char *str)
{
    sort_by_t result;

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

void print_movie(const movie_t film)
{
    printf("%s\n%s\n%d\n", films.title, films.name, films.year);
}

void print_movies(const movie_t *films, const int sz)
{
    for (int i = 0; i < sz; i++)
        print_movie(films[i]);
}

int cmp_film_with_key(const movie_t film,
const sort_by_t field, const char *key, int *result)
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

    return EXIT_SUCCESS;
}

int get_index_by_field_and_key(const movie_t *films, const int num_of_films,
const sort_by_t field, const char *key, int *result)
{
    int left = 0, right = num_of_films - 1, center;

    while (left <= right)
    {
        center = (left + right) / 2;

        int cmp;
        int error;

        if ((error = cmp_film_with_key(films[center], field, key, &cmp)) != EXIT_SUCCESS)
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

            return EXIT_SUCCESS;
        }
    }

    return ERR_MOVIE_NOT_FOUND;
}

int find_movie_by_key(const movie_t *films, movie_t *found, const int num_of_films,
const sort_by_t field, const char *key)
{
    if (key == NULL)
        return ERR_COMMAND_LINE_ARGS_CONTENT;

    if (strlen(key) == 0)
        return ERR_KEY_CANNOT_BE_READ;

    int index;
    int error;

    if ((error = get_index_by_field_and_key(films, num_of_films, field,
    key, &index)) != EXIT_SUCCESS)
        return error;

    *found = films[index];

    return EXIT_SUCCESS;
}

int print_movie_by_key(const movie_t *films, const int num_of_films,
const sort_by_t field, const char *key)
{
    movie_t found_film;
    int error = find_movie_by_key(films, &found_film,
    num_of_films, field, key);

    if (error == ERR_MOVIE_NOT_FOUND)
    {
        printf("Not found\n");
    }
    else if (error != EXIT_SUCCESS)
    {
        return error;
    }
    else
    {
        print_movies(&found_film, 1);
    }

    return EXIT_SUCCESS;
}
