#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"

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

void shift_arr_right(movie *arr, const int from, const int arr_sz)
{
    for (int i = arr_sz - 1; i >= from; i--)
        arr[i + 1] = arr[i];
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

    if (tmp_year[strlen(tmp_year) - 1] != '\n')
        if (!feof(file))
            return ERR_MAX_STRING_LNG;

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
int *num_of_films, const sort_by field)
{
    FILE *file = fopen(filename, "r");
    *num_of_films = 0;

    if (file == NULL)
        return ERR_NO_SUCH_FILE;

    while(1)
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
