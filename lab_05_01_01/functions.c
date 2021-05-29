#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

#define EXPECTED_ARGS 1

#define YES 1
#define NO 0

int process(FILE *f, int *first_max, int *second_max)
{
    if (f == NULL)
        return FILE_DOES_NOT_EXIST;

    int pre_prev_number, prev_number, number;

    if (fscanf(f, "%d", &pre_prev_number) != 1)
        return NOT_ENOUGH_ARGS;

    if (fscanf(f, "%d", &prev_number) != 1)
        return NOT_ENOUGH_ARGS;

    int number_os_maximums = 0;

    while (fscanf(f, "%d", &number) == 1)
    {
        if (prev_number > pre_prev_number && prev_number > number)
        {
            if (number_os_maximums++ == 0)
                *first_max = prev_number;
            else
            {
                number_os_maximums++;
                *second_max = prev_number;
                break;
            }
        }

        pre_prev_number = prev_number;
        prev_number = number;
    }

    if (number_os_maximums < EXPECTED_MAXIMUMS)
        return NOT_ENOUGH_MAXIMUMS;

    return OK;
}