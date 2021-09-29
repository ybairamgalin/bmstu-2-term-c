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

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    if (pb_src == NULL || pe_src == NULL)
        return ERR_KEY_NULL_POINTER;

    if (pb_src >= pe_src)
        return ERR_WRONG_POINTERS_VAL;

    size_t first_min_index = INDEX_NOT_SET, first_max_index = INDEX_NOT_SET;
    size_t src_sz = pe_src - pb_src;

    if (src_sz <= 2)
        return ERR_NOT_ENOUGH_ELEMENTS;

    if (*pb_src < *(pb_src + 1))
        first_min_index = 0;

    for (int i = 1; i < src_sz - 1; i++)
    {
        if (first_min_index == INDEX_NOT_SET)
            if (*(pb_src + i) <= *(pb_src + i - 1) &&
                    *(pb_src + i) < *(pb_src + i + 1))
                first_min_index = i;
        if (first_max_index == INDEX_NOT_SET)
            if (*(pb_src + i) > *(pb_src + i - 1) &&
                    *(pb_src + i) >= *(pb_src + i + 1))
                first_max_index = i;
    }

    if (first_max_index == INDEX_NOT_SET)
        if (*(pb_src + src_sz - 1) > *(pb_src + src_sz - 2))
            first_max_index = src_sz - 1;

    if (first_min_index == INDEX_NOT_SET || first_max_index == INDEX_NOT_SET)
        return ERR_NO_MAX_MIN_VAL_IN_ARR;

    size_t new_arr_sz = first_max_index - first_min_index - 1;

    if (new_arr_sz == 0)
        return ERR_NOT_ENOUGH_ELEMENTS;

    int error;

    if ((error = get_mem(pb_dst, new_arr_sz)) != EXIT_SUCCESS)
        return error;

    *pe_dst = *pb_dst + new_arr_sz;

    for (size_t i = 0; i < new_arr_sz; i++)
        *(*(pb_dst) + i) = *(pb_src + first_min_index + i + 1);

    return EXIT_SUCCESS;
}

