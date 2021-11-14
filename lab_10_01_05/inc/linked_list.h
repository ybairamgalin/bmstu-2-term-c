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
void *pop_front(node_t **head);

node_t *find(node_t *head, const void *data,
int (*cmp)(const void*, const void*));
int copy(node_t *head, node_t **new_head);

node_t *sort(node_t *head, int (*cmp)(const void*, const void*));
void front_back_split(node_t *head, node_t **back);
node_t *sorted_merge(node_t **head_a, node_t **head_b,
int (*cmp)(const void*, const void*));

#endif
