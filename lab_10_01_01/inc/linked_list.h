#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

typedef struct node node_t;

struct node
{
    void *data;
    node_t *next;
};

node_t *node_create(void *data);
void node_free(node_t *node);
void node_free_all(node_t *head);

node_t *node_push_back(node_t *head, node_t *elem);
node_t *find(node_t *head, const void *data,
int (*cmp)(const void*, const void*));
void *pop_front(node_t **head);

#endif
