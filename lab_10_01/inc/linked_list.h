#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

typedef struct node node_t;

struct node
{
    void *data;
    node_t *next;
};

node_t *node_create(void *data);
node_t *node_push_back(node_t *head, node_t *elem);
node_t *find(node_t *head, const void *data,
int (*cmp)(const void*, const void*));

#endif
