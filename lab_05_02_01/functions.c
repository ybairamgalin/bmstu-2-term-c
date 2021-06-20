#include "functions.h"

int find_max_min(FILE *file, int *max, int *min)
{
    int number;
    *max = -MAX_INT;
    *min = MAX_INT;

    int number_exists = NO;

    while (fscanf(file, "%d", &number) == EXPECTED_ARGS)
    {
        number_exists = YES;

        if (number > *max)
            *max = number;

        if (number < *min)
            *min = number;
    }

    return number_exists;
}

int greater_than_average_nums(FILE *file, const int average)
{
    int numbers_greater_than_average = 0;
    int number;

    while (fscanf(file, "%d", &number) != EOF)
        if (number > average)
            numbers_greater_than_average++;

    return numbers_greater_than_average;
}