#ifndef _MY_STRING_H_
#define _MY_STRING_H_

#include "linked_list.h"

#define NODE_LNG 4

typedef struct my_string my_string_t;

struct my_string
{
    node_t *string_head;
    size_t data_sz;
    void *data;
};

my_string_t *my_string_create(const char *str);
void my_string_free(my_string_t *string);
void my_string_print(my_string_t *string);
my_string_t *my_string_concat(my_string_t *dest, const my_string_t *src);

#endif
