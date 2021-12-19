#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

my_stack_t *push(my_stack_t *stack, int value)
{
    my_stack_t *new_elem = malloc(sizeof(my_stack_t));

    if (!new_elem)
    {
        while (stack)
        {
            my_stack_t *old  = stack->prev;
            stack = stack->prev;
            free(old);
        }

        return NULL;
    }

    new_elem->prev = stack;
    new_elem->value = value;

    return new_elem;
}

my_stack_t *pop(my_stack_t *stack, int *value)
{
    if (!stack)
        return NULL;

    my_stack_t *old = stack;
    stack = stack->prev;

    if (value)
        *value = old->value;

    free(old);

    return stack;
}

void free_all(my_stack_t *stack)
{
    if (!stack)
        return;

    if (stack->prev)
        free_all(stack->prev);

    free(stack);
}
