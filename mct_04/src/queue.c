#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void destruct_queue(my_queue_t *queue)
{
    if (!queue)
        return;

    free_all(queue->head);
    free_all(queue->tail);

    free(queue);
}

my_queue_t *enqueue(my_queue_t *queue, int value)
{
    if (!queue)
    {
        queue = malloc(sizeof(my_queue_t));

        if (!queue)
            return NULL;

        queue->head = NULL;
        queue->tail = NULL;
    }

    queue->head = push(queue->head, value);

    if (!queue->head)
        return NULL;

    return queue;
}

my_queue_t *dequeue(my_queue_t *queue, int *value)
{
    if (!queue)
        return NULL;

    int cur_val;

    if (!queue->tail)
        while (queue->head)
        {
            queue->head = pop(queue->head, &cur_val);
            queue->tail = push(queue->tail, cur_val);

            if (!queue->tail)
                return NULL;
        }

    queue->tail = pop(queue->tail, value);

    return queue;
}

int is_empty(my_queue_t *queue)
{
    if (!queue)
        return 1;

    if (!queue->head && !queue->tail)
        return 1;

    return 0;
}
