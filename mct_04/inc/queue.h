#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "stack.h"

typedef struct
{
    my_stack_t *head;
    my_stack_t *tail;
} my_queue_t;

my_queue_t *enqueue(my_queue_t *queue, int value);
my_queue_t *dequeue(my_queue_t *queue, int *value);
int is_empty(my_queue_t *queue);
void destruct_queue(my_queue_t *queue);

#endif
