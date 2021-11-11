#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int int_cmp(const void *first, const void *second)
{
    int *fir = (int*)first;
    int *sec = (int*)second;

    if (*fir < *sec)
        return 1;

    if (*fir > *sec)
        return -1;

    return 0;
}

int main(void)
{
    return EXIT_SUCCESS;
}
