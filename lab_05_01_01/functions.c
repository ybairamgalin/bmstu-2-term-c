#include <stdio.h>
#include "functions.h"

int process(FILE *f)
{
    int number, prev, pre_prev;
    int num_extremums = 0;

    if (fscanf(f, "%d", &pre_prev) == EOF)
        return NOT_ENOUGH_ARGS;

    if (fscanf(f, "%d", &prev) == EOF)
        return NOT_ENOUGH_ARGS;

    int read_args;

    while ((read_args = fscanf(f, "%d", &number)) != EOF && read_args == 1)
    {
        if (pre_prev < prev && prev > number)
            num_extremums++;

        pre_prev = prev;
        prev = number;
    }

    if (num_extremums >= EXPECTED_EXTREMUMS)
        return OK;
    else
        return NOT_ENOUGH_EXTREMUMS;
}