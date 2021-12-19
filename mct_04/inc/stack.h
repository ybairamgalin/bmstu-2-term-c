#ifndef __STACK_H__
#define __STACK_H__

struct my_stack
{
    int value;
    struct my_stack *prev;
};

typedef struct my_stack my_stack_t;

my_stack_t *push(my_stack_t *stack, int value);
my_stack_t *pop(my_stack_t *stack, int *value);
void free_all(my_stack_t *stack);

#endif
