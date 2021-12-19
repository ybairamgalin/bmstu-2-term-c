#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"

int main(void)
{
    my_queue_t *queue = enqueue(NULL, 5);
    queue = enqueue(queue, 4);
    queue = enqueue(queue, 3);
    queue = enqueue(queue, 2);
    queue = enqueue(queue, 1);
    queue = enqueue(queue, 0);

    int val;

    while (!is_empty(queue))
    {
        queue = dequeue(queue, &val);
        printf("val = %d\n", val);
    }

    destruct_queue(queue);
}
