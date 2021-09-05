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
    {
        printf("%s\n%s\n%d\n", films[i].title, films[i].name, films[i].year);
    }
}

int read_movie_from_file(FILE *file, movie *film)
{
    if (fgets(film->title, sizeof(film->name), file) == NULL)
        return ERR_NOTHING_TO_READ;

    if (film->title[strlen(film->title) - 1] != '\n')
        return ERR_STRING_LNG;

    film->title[strlen(film->title) - 1] = '\0';

    if (strlen(film->title) == 0)
        return ERR_STRING_LNG;

    if (fgets(film->name, sizeof(film->name), file) == NULL)
        return ERR_FILE_STRUCT;

    if (film->name[strlen(film->name) - 1] != '\n')
        return ERR_STRING_LNG;

    film->name[strlen(film->name) - 1] = '\0';

    if (strlen(film->name) == 0)
        return ERR_STRING_LNG;

    char tmp_year[MAX_YEAR_LNG + 1];

    if (fgets(tmp_year, sizeof(tmp_year), file) == NULL)
        return ERR_FILE_STRUCT;

    if ((film->year = atoi(tmp_year)) == 0)
        return ERR_FILE_STRUCT;

    return OK;
}

void shift_arr_right(movie *arr, const int from, const int arr_sz)
{
    for (int i = arr_sz - 1; i >= from; i--)
        arr[i + 1] = arr[i];
}

int get_ins_pos_by_title(const movie *arr, const movie film, const int arr_sz)
{
    for (int i = 0; i < arr_sz; i++)
        if (strcmp(arr[i].title, film.title) > 0)
            return i;

    return arr_sz;
}

int get_ins_pos_by_name(const movie *arr, const movie film, const int arr_sz)
{
    for (int i = 0; i < arr_sz; i++)
        if (strcmp(arr[i].name, film.name) > 0)
            return i;

    return arr_sz;
}

int get_ins_pos_by_year(const movie *arr, const movie film, const int arr_sz)
{
    for (int i = 0; i < arr_sz; i++)
        if (arr[i].year > film.year)
            return i;

    return arr_sz;
}


void insert_elem_in_sorted_arr_by_key(movie *arr, const movie element,
const int cur_sz, const sort_by field)
{
    int (*get_ins_pos)(const movie *arr, const movie film,
            const int arr_sz) = NULL;

    if (field == title)
    {
        get_ins_pos = get_ins_pos_by_title;
    }
    else if (field == name)
    {
        get_ins_pos = get_ins_pos_by_name;
    }
    else if (field == year)
    {
        get_ins_pos = get_ins_pos_by_year;
    }

    if (get_ins_pos == NULL)
        exit(1);

    int ins_pos = get_ins_pos(arr, element, cur_sz);

    shift_arr_right(arr, ins_pos, cur_sz);
    arr[ins_pos] = element;
}

int read_movies_from_file(const char *filename, movie *films,
                          int *num_of_films, const sort_by field)
{
    FILE *file = fopen(filename, "r");
    *num_of_films = 0;

    if (file == NULL)
        return ERR_NO_SUCH_FILE;

    for (int i = 0; ; i++)
    {
        int err;
        movie film;

        if ((err = read_movie_from_file(file, &film)) == ERR_NOTHING_TO_READ)
            break;

        if (err != 0)
            return err;

        insert_elem_in_sorted_arr_by_key(films, film, *num_of_films, field);
        (*num_of_films)++;
    }

    fclose(file);

    return OK;
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
        *result = strcmp(key, film.title);
    }
    else if (field == year)
    {
        int date;

        if ((date = atoi(key)) == 0)
            return ERR_COMMAND_LINE_ARGS_CONTENT;

        *result =  date - film.year;
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
    int index;
    int error;

    if ((error  = get_index_by_field_and_key(films, num_of_films, field,
                                            key, &index)) != OK)
        return error;

    *found = films[index];

    return OK;
}
