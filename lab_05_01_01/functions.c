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

    while (fscanf(f, "%d", &number) != EOF)
    {
        if ((number > prev && prev > pre_prev) ||
            (number < prev && prev < pre_prev))
        {
            num_extremums++;
            continue;
        }
    }

    if (num_extremums == EXPECTED_EXTREMUMS)
        return OK;
    else
        return NOT_ENOUGH_EXTREMUMS;
}