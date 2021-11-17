#ifndef _MY_STRING_H_
#define _MY_STRING_H_

#define NODE_LNG 4
#define SUBSTR_NOT_FOUND (-1)

typedef struct my_string my_string_t;

struct string_part
{
    char data[NODE_LNG];
    struct string_part *next;
};

typedef struct string_part string_part_t;

struct my_string
{
    string_part_t *head;
    string_part_t *tail;
};

my_string_t *my_string_create(const char *str);
void my_string_free(my_string_t *string);
void my_string_print(my_string_t *string);
my_string_t *my_string_concat(my_string_t *first, my_string_t *second);
my_string_t *my_string_del_spaces(my_string_t *string);
int my_string_find(const my_string_t *string, const char *substr);

#endif
