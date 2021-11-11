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
//    int values[4] = { 1, 2, 3, 4};
//
//    node_t *head = NULL;
//    head = node_push_back(head, node_create(&values[0]));
//    head = node_push_back(head, node_create(&values[1]));
//    head = node_push_back(head, node_create(&values[2]));
//    head = node_push_back(head, node_create(&values[3]));
//
//    node_t *new_head;
//    int rc = copy(head, &new_head);

    return EXIT_SUCCESS;
}
