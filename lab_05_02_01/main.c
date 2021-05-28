#include <stdio.h>

#define NOT_ENOUGH_MAIN_ARGS -1

#define MAX_INT 2147483647

void find_max_min(FILE *file, int *max, int *min)
{
    int number;
    *max = -MAX_INT;
    *min = MAX_INT;

    while (fscanf(file, "%d", &number) != EOF)
    {
        if (number > *max)
            *max = number;

        if (number < *min)
            *min = number;
    }
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

int main(const int argc, char **argv)
{
    if (argc != 2)
        return NOT_ENOUGH_MAIN_ARGS;

    char *file_name = argv[1];

    FILE *file = fopen(file_name, "r");

    int max, min;
    find_max_min(file, &max, &min);
    int average = (max + min) / 2;
    fseek(file, 0, SEEK_SET);
    int result = greater_than_average_nums(file, average);

    printf("%d", result);

    fclose(file);
}