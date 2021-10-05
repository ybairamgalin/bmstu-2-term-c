#include "stdio.h"
#include "stdlib.h"
#include "../inc/io_file.h"

int get_number_of_int_in_file(const char *filename, int *result)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
        return ERR_FILE_DOES_NOT_EXIST;

    int num;
    int number_of_elements = 0;

    while (fscanf(file, "%d", &num) == 1)
        number_of_elements++;

    if (number_of_elements == 0)
        return ERR_FILE_IS_EMPTY;

    *result = number_of_elements;
    fclose(file);

    return EXIT_SUCCESS;
}

int read_nums_from_file(const char *filename, int *dest_start, int *dest_end)
{
    FILE *file = fopen(filename, "r");

    for (size_t i = 0; dest_start + i != dest_end; i++)
        fscanf(file, "%d", dest_start + i);

    return EXIT_SUCCESS;
}

int put_int_arr_in_file(const char *filename, int *arr_start,
int *arr_end)
{
    FILE *file = fopen(filename, "w");

    if (file == NULL)
        return EXIT_FAILURE;

    fprintf(file, "%d", *arr_start);

    for (int *i = arr_start + 1; i < arr_end; i++)
        fprintf(file, " %d", *i);

    fprintf(file, "\n");
    fclose(file);

    return EXIT_SUCCESS;
}

int read_ints_file(const char *filename, int **start, int **end)
{
    int error;
    int nums_in_file;

    if ((error = get_number_of_int_in_file(filename, &nums_in_file)) !=
        EXIT_SUCCESS)
        return error;

    *start = malloc(nums_in_file * sizeof(int));

    if (*start == NULL)
        return ERR_MEMORY;

    *end = *start + nums_in_file;
    read_nums_from_file(filename, *start, *end);

    return EXIT_SUCCESS;
}
