#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "movie.h"
#include "insert_movie.h"

typedef int (ins_pos_func_t)(const movie*, const movie, const int);

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

ins_pos_func_t *get_ins_pos_func(const sort_by field)
{
    if (field == title)
    {
        return &get_ins_pos_by_title;
    }
    else if (field == name)
    {
        return &get_ins_pos_by_name;
    }
    else if (field == year)
    {
        return &get_ins_pos_by_year;
    }

    return NULL;
}

int insert_elem_in_arr_by_key(movie *arr, const movie element,
const int cur_sz, const sort_by field)
{
    if (cur_sz >= MAX_FILMS)
        return ERR_TOO_MANY_FILMS;

    ins_pos_func_t *get_ins_pos = get_ins_pos_func(field);

    if (get_ins_pos == NULL)
        return ERR_FIELD_IS_WRONG;

    int ins_pos = get_ins_pos(arr, element, cur_sz);

    shift_arr_right(arr, ins_pos, cur_sz);
    arr[ins_pos] = element;

    return OK;
}
