#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

#define EXPECTED_ARGS 1

#define YES 1
#define NO 0

int is_maximum(int a, int b, int c)
{
    if (b > a && b > c)
        return YES;

    return NO;
}

int process(FILE *f, int *a, int *b)
{
    int first, second, third;
    int count_maximums = 0;

    if (fscanf(f, "%d", &first) != EXPECTED_ARGS)
        return NOT_ENOUGH_ARGS;

    if (fscanf(f, "%d", &second) != EXPECTED_ARGS)
        return NOT_ENOUGH_ARGS;

    int check = fscanf(f, "%d", &third);

    while (check == EXPECTED_ARGS)
    {
        if (is_maximum(first, second, third))
        {
            if (count_maximums++ == 0)
                *a = second;
            else
            {
                *b = second;
                break;
            }
        }

        first = second;
        second = third;
        check = fscanf(f, "%d", &third);
    }

    if (count_maximums != EXPECTED_EXTREMUMS)
        return NOT_ENOUGH_EXTREMUMS;
    else
        return OK;
}