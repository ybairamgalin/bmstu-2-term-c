#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my_string.h"

void my_string_free(my_string_t *string)
{
    node_free_all(string->string_head);
    free(string->data);
    free(string);
}

static int end_of_line_in_node(const char *node)
{
    for (int i = 0; i < NODE_LNG; i++)
        if (node[i] == '\0')
            return 1;

    return 0;
}

my_string_t *my_string_create(const char *str)
{
    my_string_t *string = malloc(sizeof(my_string_t));

    if (string == NULL)
        return NULL;

    string->data_sz = sizeof(char) * strlen(str) + 1;
    string->string_head = NULL;
    string->data = malloc(string->data_sz);

    if (string->data == NULL)
    {
        free(string);
        return NULL;
    }

    memcpy(string->data, str, string->data_sz);
    int cur_part = 0;

    do {
        node_t *new = node_create(string->data + cur_part * NODE_LNG);

        if (new == NULL)
        {
            my_string_free(string);
            return NULL;
        }

        string->string_head = node_push_back(string->string_head, new);
    } while (!end_of_line_in_node(string->data + (cur_part++) * NODE_LNG));

    return string;
}

void my_string_print(my_string_t *string)
{
    node_t *head = string->string_head;

    for ( ; head; head = head->next)
        for (int i = 0; i < NODE_LNG; i++)
            if (*((char*)head->data + i) == '\0')
                return;
            else
                printf("%c", *((char*)head->data + i));
}

my_string_t *my_string_concat(my_string_t *dest, const my_string_t *src)
{
    dest->data = realloc(dest->data, dest->data_sz + src->data_sz);

    if (dest->data == NULL) // todo add free
        return NULL;

    memcpy(dest->data + dest->data_sz, src->data - 1, src->data_sz);
    node_t *head = dest->string_head;

    for ( ; head->next; head = head->next);
    int cur_part = 0;



    do {
        node_t *new = node_create(dest->data + dest->data_sz - 1
                + cur_part * NODE_LNG);

        if (new == NULL)
        {
            my_string_free(dest);
            return NULL;
        }

        dest->string_head = node_push_back(dest->string_head, new);
    } while (!end_of_line_in_node(dest->data + dest->data_sz - 1 +
                (cur_part++) * NODE_LNG));

    dest->data_sz = dest->data_sz + src->data_sz - 1;

    return dest;
}
