#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my_string.h"

#define INPUT_LNG 128

#define INPUT_ERR 1
#define STRING_TOO_LONG_ERR 2
#define UNKNOWN_OPERATION_ERR 3
#define MEM_ERR 4

int input_string(char *dest)
{
    if (fgets(dest, INPUT_LNG, stdin) == NULL)
        return INPUT_ERR;

    if (dest[strlen(dest) - 1] != '\n')
        return STRING_TOO_LONG_ERR;

    dest[strlen(dest) - 1] = '\0';

    return EXIT_SUCCESS;
}

int handle_operation(const char *operation)
{
    int error;

    if (strcmp(operation, "out") == 0)
    {
        char str[INPUT_LNG];

        if ((error = input_string(str)) != EXIT_SUCCESS)
            return error;

        my_string_t *string = my_string_create(str);

        if (string == NULL)
            return MEM_ERR;

        my_string_print(string);
        my_string_free(string);
    }
    else if (strcmp(operation, "cat") == 0)
    {
        char first[INPUT_LNG];
        char second[INPUT_LNG];

        if ((error = input_string(first)) != EXIT_SUCCESS)
            return error;

        if ((error = input_string(second)) != EXIT_SUCCESS)
            return error;

        my_string_t *my_first = my_string_create(first);

        if (my_first == NULL)
            return MEM_ERR;

        my_string_t *my_second = my_string_create(second);

        if (my_second == NULL)
            return MEM_ERR;

        my_first = my_string_concat(my_first, my_second);
        my_string_print(my_first);
        my_string_free(my_first);
    }
    else if (strcmp(operation, "sps") == 0)
    {
        char str[INPUT_LNG];

        if ((error = input_string(str)) != EXIT_SUCCESS)
            return error;

        my_string_t *string = my_string_create(str);

        if (string == NULL)
            return MEM_ERR;

        string = my_string_del_spaces(string);
        my_string_print(string);
        my_string_free(string);
    }
    else if (strcmp(operation, "pos") == 0)
    {
        char str[INPUT_LNG];
        char substr[INPUT_LNG];

        if ((error = input_string(str)) != EXIT_SUCCESS)
            return error;

        if ((error = input_string(substr)) != EXIT_SUCCESS)
            return error;

        my_string_t *string = my_string_create(str);

        if (string == NULL)
            return MEM_ERR;

        int index = my_string_find(string, substr);
        my_string_free(string);

        printf("%d\n", index);
    }
    else
        return UNKNOWN_OPERATION_ERR;

    return EXIT_SUCCESS;
}

int main(void)
{
    int error;
    char operation[INPUT_LNG];

    if ((error = input_string(operation)) != EXIT_SUCCESS)
        return error;

    if ((error = handle_operation(operation)) != EXIT_SUCCESS)
        return error;

    return EXIT_SUCCESS;
}
