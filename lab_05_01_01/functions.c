#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

#define EXPECTED_ARGS 1

#define YES 1
#define NO 0

void swap_values(int *first, int *second)
{
    int buf = *first;
    *first = *second;
    *second = buf;
}

int process(FILE *f, int *first_max, int *second_max)
{
    if (f == NULL)
        return FILE_DOES_NOT_EXIST;

    if (fscanf(f, "%d", first_max) != EXPECTED_ARGS)
        return NOT_ENOUGH_ARGS;

    if (fscanf(f, "%d", second_max) != EXPECTED_ARGS)
        return NOT_ENOUGH_ARGS;

    if (*second_max > *first_max)
        swap_values(first_max, second_max);

    int number;

    while (fscanf(f, "%d", &number) == EXPECTED_ARGS)
    {
        if (number > *first_max)
        {
            *second_max = *first_max;
            *first_max = number;
        }
        else if (number > *second_max)
            *second_max = number;
    }

    return OK;
}