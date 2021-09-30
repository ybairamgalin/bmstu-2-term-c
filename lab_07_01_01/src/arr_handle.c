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

void cpy_until_except(const int *pb_src, const int *pe_src, int **pb_dst,
int **pe_dst, const int until, const int except)
{
    int wrote = 0;

    for (int i = 0; pb_src + i != pe_src && *(pb_src + i) != until; i++)
        if (*(pb_src + i) != except)
            *(*pb_dst + wrote++) = *(pb_src + i);

    *pe_dst = *pb_dst + wrote;
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int error;

    if ((error = is_valid_int_arr(pb_src, pe_src)) != EXIT_SUCCESS)
        return error;

    size_t src_sz = pe_src - pb_src;
    int src_max = find_max(pb_src, pe_src);
    int src_min = find_min(pb_src, pe_src);

    if (src_max == src_min)
        return ERR_NOT_ENOUGH_ELEMENTS;

    if ((error = get_mem(pb_dst, src_sz)) != EXIT_SUCCESS)
        return error;

    for (int i = 0; pb_src + i != pe_src; i++)
    {
        if (*(pb_src + i) == src_min)
        {
            cpy_until_except(pb_src + i, pe_src, pb_dst, pe_dst,
                             src_max, src_min);
            break;
        }

        if (*(pb_src + i) == src_max)
        {
            cpy_until_except(pb_src + i, pe_src, pb_dst, pe_dst,
                             src_min, src_max);
            break;
        }

    }

    if (*pe_dst == *pb_dst)
        return ERR_NOT_ENOUGH_ELEMENTS;

    return EXIT_SUCCESS;
}

