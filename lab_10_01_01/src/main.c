#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int int_cmp(const void *first, const void *second)
{
    int *fir = (int*)first;
    int *sec = (int*)second;

    if (*fir > *sec)
        return 1;

    if (*fir < *sec)
        return -1;

    return 0;
}

int main(void)
{
//    int values[4] = { 1, 2, 3, 4 };
//
//    node_t *first = NULL;
//    first = node_push_back(first, node_create(&values[0]));
//    first = node_push_back(first, node_create(&values[2]));
//
//    node_t *second = NULL;
//
//    second = node_push_back(second, node_create(&values[1]));
//    second = node_push_back(second, node_create(&values[3]));
//
//    node_t *sorted = sorted_merge(&first, &second, int_cmp);
//
//    node_free_all(sorted);

    return EXIT_SUCCESS;
}
