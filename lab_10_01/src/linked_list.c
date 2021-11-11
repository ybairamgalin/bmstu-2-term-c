#include <stdlib.h>
#include "linked_list.h"

node_t *node_create(void *data)
{
    struct node *node = malloc(sizeof(struct node));

    if (node == NULL)
        return NULL;

    node->data = data;
    node->next = NULL;

    return node;
}

node_t *node_push_back(node_t *head, node_t *elem)
{
    struct node *cur = head;

    if (cur == NULL)
        return elem;

    while (cur->next)
        cur = cur->next;

    cur->next = elem;

    return head;
}

node_t *find(node_t *head, const void *data,
int (*cmp)(const void*, const void*))
{
    struct node *cur = head;

    if (head == NULL)
        return NULL;

    do {
        if (cmp(cur->data, data) == 0)
            return cur;

        cur = cur->next;
    } while (cur->next);

    return NULL;
}
