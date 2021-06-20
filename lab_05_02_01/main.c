#include <stdio.h>
#include "functions.h"

int main(const int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Error: not enough command line arguments\n");

        return NOT_ENOUGH_MAIN_ARGS;
    }

    char *file_name = argv[1];

    FILE *file;

    if ((file = fopen(file_name, "r")) == NULL)
    {
        printf("Error: file does not exist\n");

        return FILE_CANNOT_BE_OPENED;
    }

    int max, min;

    if (find_max_min(file, &max, &min) == NO)
    {
        printf("Error: no integers in file\n");

        return NO_INTEGERS_IN_FILE;
    }

    fseek(file, 0, SEEK_SET);
    int average = (max + min) / 2;
    int result = greater_than_average_nums(file, average);

    printf("%d", result);

    fclose(file);

    return OK;
}