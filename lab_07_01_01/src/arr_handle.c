#include <stdio.h>
#include "../inc/arr_handle.h"

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