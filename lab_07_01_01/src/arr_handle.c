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

int max_index(const int *start, const int *end)
{
    int index = 0;

    for (int i = 0; start + i != end; i++)
        if (*(start + i) > *(start + index))
            index = i;

    return index;
}

int min_index(const int *start, const int *end)
{
    int index = 0;

    for (int i = 0; start + i != end; i++)
        if (*(start + i) < *(start + index))
            index = i;

    return index;
}

int min(const int a, const int b)
{
    return (a <= b) ? a : b;
}

int max(const int a, const int b)
{
    return (a >= b) ? a : b;
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int error;

    if ((error = is_valid_int_arr(pb_src, pe_src)) != EXIT_SUCCESS)
        return error;

    int src_max_index = max_index(pb_src, pe_src);
    int src_min_index = min_index(pb_src, pe_src);
    int cpy_start_index = min(src_max_index, src_min_index) + 1;
    int dst_sz = max(src_max_index, src_min_index) -
        min(src_max_index, src_min_index) - 1;

    if (dst_sz <= 0)
        return ERR_NOT_ENOUGH_ELEMENTS;

    *pb_dst = malloc(dst_sz * sizeof(int));

    if (*pb_dst == NULL)
        return ERR_NULL_MEM_POINTER;

    *pe_dst = *pb_dst + dst_sz;

    for (int i = 0; i < dst_sz; i++)
        *(*pb_dst + i) = *(pb_src + cpy_start_index + i);

    return EXIT_SUCCESS;
}
