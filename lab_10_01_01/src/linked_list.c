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

void node_free(node_t *node)
{
    free(node);
}

void node_free_all(node_t *head)
{
    node_t *cur = head;

    if (cur == NULL)
        return;

    if (cur->next != NULL)
        node_free_all(cur->next);

    node_free(cur);
}

node_t *find(node_t *head, const void *data,
int (*cmp)(const void*, const void*))
{
    for ( ; head; head = head->next)
        if (cmp(head->data, data) == 0)
            return head;

    return NULL;
}

void *pop_front(node_t **head)
{
    if (head == NULL)
        return NULL;

    if (*head == NULL)
        return NULL;

    node_t *old = *head;
    *head = old->next;
    void *data = old->data;
    node_free(old);

    return data;
}

int copy(node_t *head, node_t **new_head)
{
    if (head == NULL)
        return EXIT_FAILURE;

    if (new_head == NULL)
        return EXIT_FAILURE;

    *new_head = NULL;

    for ( ; head; head = head->next)
    {
        node_t *new = node_create(head->data);

        if (new == NULL)
        {
            node_free_all(*new_head);
            return EXIT_FAILURE;
        }

        *new_head = node_push_back(*new_head, new);
    }

    return EXIT_SUCCESS;
}

int list_count(node_t *head)
{
    int count = 0;

    for ( ; head; head = head->next, count++);

    return count;
}

void front_back_split(node_t *head, node_t **back)
{
    if (head == NULL)
        return;

    if (back == NULL)
        return;

    *back = NULL;
    int count = list_count(head);
    int new_list_index;

    if (count % 2 == 0)
        new_list_index = count / 2;
    else
        new_list_index = count / 2 + 1;

    node_t *new_start = head;

    for (int i = 0; i < new_list_index; i++, new_start = new_start->next);

    if (copy(new_start, back) != EXIT_SUCCESS)
        return;

    for ( ; head->next != new_start; head = head->next);

    head->next = NULL;
    node_free_all(new_start);
}
