#include <stdio.h>
#include <string.h>
#include "student.h"

int main(const int argc, const char **argv)
{
    int error;

    if (argc == 3 && strcmp(argv[1], "sb") == EQUAL_STR)
    {
        if ((error = sort_by_surname(argv[2])) != OK)
            return error;
    }
    else if (argc == 3 && strcmp(argv[1], "db") == EQUAL_STR)
    {
        if ((error = delete_worst_students(argv[2])) != OK)
            return error;
    }
    else if (argc == 5 && strcmp(argv[1], "fb") == EQUAL_STR)
    {
        if ((error = print_students_by_surname(argv[2],
        argv[3], argv[4])) != OK)
            return error;
    }
    else
        return WRONG_COMMAND_LINE_ARG;

    return OK;
}
