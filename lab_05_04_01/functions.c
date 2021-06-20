#include <stdio.h>
#include "functions.h"

int file_size(FILE *f, size_t *size)
{
    long sz;

    if (fseek(f, 0L, SEEK_END))
        return 1;

    sz = ftell(f);

    if (sz < 0)
        return 1;

    *size = sz;

    return fseek(f, 0L, SEEK_SET);
}

float find_average(float *arr, size_t sz)
{
    float sum = 0;

    for (size_t i = 0; i < sz; i++)
        sum += arr[i];

    return sum / (float)sz;
}

void del_arr_elem(float *arr, int size, const int elem)
{
    for (int i = elem; i < size - 1; i++)
        arr[i] = arr[i + 1];
}