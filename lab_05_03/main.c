#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "functions.h"

int main(const int argc, char **argv)
{
    if (argc != 3)
        return NOT_ENOUGH_COMMAND_LINE_ARGS;

    if (strcmp(argv[1], "c") == EQUAL_STR)
    {
        if (create_file(argv[2]) != OK)
            return COULD_NOT_CREATE_FILE;
    }
    else if (strcmp(argv[1], "p") == EQUAL_STR)
    {
        if (print_int_from_binary(argv[2]) != OK)
            return FILE_DOES_NOT_EXIST;
    }
    else if (strcmp(argv[1], "s") == EQUAL_STR)
    {
        if (sort_numbers_in_file(argv[2]) != OK)
            return FILE_DOES_NOT_EXIST;
    }
    else
        return UNKNOWN_COMMAND;

    return OK;
}
