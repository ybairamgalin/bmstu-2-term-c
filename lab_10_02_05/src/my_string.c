#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my_string.h"

static void string_part_free_all(string_part_t *part)
{
    if (part == NULL)
        return;

    string_part_t *cur = part;

    if (cur->next)
        string_part_free_all(cur->next);

    free(cur);
}

static string_part_t *string_part_create(const char *arr)
{
    string_part_t *part = malloc(sizeof(string_part_t));

    if (part == NULL)
        return NULL;

    for (size_t i = 0; i < NODE_LNG; i++)
        if (arr[i] == '\0')
        {
            for (size_t j = i; j < NODE_LNG; j++)
                part->data[j] = '\0';
            break;
        }
        else
            part->data[i] = arr[i];

    part->next = NULL;

    return part;
}

void my_string_free(my_string_t *string)
{
    string_part_free_all(string->head);
    free(string);
}

static my_string_t *string_part_push_back(my_string_t *string, string_part_t *new)
{
    if (string == NULL)
        return NULL;

    if (string->head == NULL)
    {
        string->head = new;
        string->tail = new;
        return string;
    }

    if (string->tail == NULL)
        return NULL;

    string->tail->next = new;

    for (; string->tail->next; string->tail = string->tail->next);

    return string;
}

my_string_t *my_string_create(const char *str)
{
    my_string_t *string = malloc(sizeof(my_string_t));

    if (string == NULL)
        return NULL;

    string->head = NULL;
    string->tail = NULL;
    size_t lng = strlen(str) + 1;

    for (size_t i = 0; i < lng; i += NODE_LNG)
    {
        string_part_t *part = string_part_create(str + i);

        if (part == NULL)
        {
            my_string_free(string);
            return NULL;
        }

        string = string_part_push_back(string, part);
    }

    return string;
}

my_string_t *my_string_concat(my_string_t *first, my_string_t *second)
{
    first->tail->next = second->head;
    first->tail = second->tail;
    free(second);

    return first;
}

my_string_t *my_string_del_spaces(my_string_t *string)
{
    string_part_t *head = string->head;

    for (; head; head = head->next)
    {
        for (size_t i = 0; i < NODE_LNG - 1; i++)
            if (head->data[i] == ' ' && head->data[i + 1] == ' ')
                head->data[i] = '\0';

        if (head->next)
            if (head->data[NODE_LNG - 1] == ' ' && head->next->data[0] == ' ')
                head->data[NODE_LNG - 1] = '\0';
    }

    return string;
}

int starts_with(string_part_t *part, size_t index, const char *substr)
{
    size_t sub_len = strlen(substr);

    for (size_t i = 0; i < sub_len; i++)
    {
        char cur = part->data[index];

        if (cur == '\0' || cur == substr[i])
        {
            if (index < NODE_LNG - 1)
            {
                index++;
                continue;
            }

            if (part->next)
            {
                index = 0;
                part = part->next;
                continue;
            }

            return 0;
        }

        return 0;
    }

    return 1;
}

int my_string_find(const my_string_t *string, const char *substr)
{
    int str_index = 0;
    size_t sub_len = strlen(substr);

    if (sub_len == 0)
        return SUBSTR_NOT_FOUND;

    string_part_t *part = string->head;

    for (; part; part = part->next)
        for (size_t i = 0; i < NODE_LNG; i++)
        {
            if (starts_with(part, i, substr))
                return str_index;

            str_index++;
        }

    return SUBSTR_NOT_FOUND;
}

void my_string_print(my_string_t *string)
{
    string_part_t *head = string->head;

    for (; head; head = head->next)
        for (size_t i = 0; i < NODE_LNG; i++)
            if (head->data[i] != '\0')
                printf("%c", head->data[i]);

    printf("\n");
}
