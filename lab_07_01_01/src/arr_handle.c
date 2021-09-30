#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/arr_handle.h"

int get_mem(int **p_arr, const size_t sz)
{
    *p_arr = malloc(sizeof(int) * sz);

    if (*p_arr == NULL)
        return ERR_NULL_MEM_POINTER;

    return EXIT_SUCCESS;
}

int int_cmp(const void *a, const void *b)
{
    int first = *(const int *)a;
    int second = *(const int *)b;

    return (first > second) - (second > first);
}

void swap(void *a, void *b, size_t sz)
{
    for (size_t i = 0; i < sz; i++)
    {
        char buf = *((char *)a + i);
        *((char *)a + i) = *((char *)b + i);
        *((char *)b + i) = buf;
    }
}

void mysort(void *ptr, size_t count, size_t size,
int (*comp)(const void *, const void *))
{
    const size_t max_pos = size * count;

    for (char *i = ptr; i < (char *)ptr + max_pos; i += size)
    {
        char *min_elem = i;

        for (char *j = i; j < (char *)ptr + max_pos; j += size)
            if (comp(min_elem, j) > 0)
                min_elem = j;

        if (comp(i, min_elem) > 0)
            swap(i, min_elem, size);
    }
}

int find_max(const int *start, const int *end)
{
    int value = *start;

    for (int i = 0; start + i != end; i++)
        if (*(start + i) > value)
            value = *(start + i);

    return value;
}

int find_min(const int *start, const int *end)
{
    int value = *start;

    for (int i = 0; start + i != end; i++)
        if (*(start + i) < value)
            value = *(start + i);

    return value;
}

size_t first_min_index(const int *arr_start, const int *arr_end)
{
    size_t sz = arr_end - arr_start;
    size_t min_index = 0;

    for (size_t i = 0; i < sz; i++)
        if (*(arr_start + i) < *(arr_start + min_index))
            min_index = i;

    return min_index;
}

size_t first_max_index(const int *arr_start, const int *arr_end)
{
    size_t sz = arr_end - arr_start;
    size_t max_index = 0;

    for (size_t i = 0; i < sz; i++)
        if (*(arr_start + i) > *(arr_start + max_index))
            max_index = i;

    return max_index;
}

int is_valid_int_arr(const int *start, const int *end)
{
    if (start == NULL || end == NULL)
        return ERR_KEY_NULL_POINTER;

    if (start >= end)
        return ERR_WRONG_POINTERS_VAL;

    if ((((char *)end - (char *)start)) % sizeof(int) != 0)
        return ERR_WRONG_POINTERS_VAL;

    return EXIT_SUCCESS;
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int error;

    if ((error = is_valid_int_arr(pb_src, pe_src)) != EXIT_SUCCESS)
        return error;

    size_t index_of_max = first_max_index(pb_src, pe_src);
    int max_elem = *(pb_src + index_of_max);

    size_t index_of_min = first_min_index(pb_src, pe_src);
    int min_elem = *(pb_src + index_of_min);

    size_t start = index_of_min + 1, end = index_of_max;

    if (index_of_min > index_of_max)
    {
        start = index_of_max + 1;
        end = index_of_min;
    }

    size_t new_arr_sz = end - start;

    if (new_arr_sz == 0)
        return ERR_NOT_ENOUGH_ELEMENTS;

    if ((error = get_mem(pb_dst, new_arr_sz)) != EXIT_SUCCESS)
        return error;

    int wrote = 0;

    for (size_t i = 0; i < new_arr_sz; i++)
        if (*(pb_src + start + i) != min_elem &&
            *(pb_src + start + i) != max_elem)
            *(*pb_dst + wrote++) = *(pb_src + start + i);

    *pe_dst = *pb_dst + wrote;

    if (*pe_dst == *pb_dst)
        return ERR_NOT_ENOUGH_ELEMENTS;

    return EXIT_SUCCESS;
}
