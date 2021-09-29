#include "stdio.h"
#include "stdlib.h"
#include "../inc/io_file.h"

int get_number_of_int_in_file(const char *filename, int *result)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
        return ERR_FILE_DOES_NOT_EXIST;

    char line[MAX_LINE_LNG];
    int number_of_elements = 0;

    while (fgets(line, sizeof(line), file) != NULL)
        number_of_elements++;

    if (number_of_elements == 0)
        return ERR_FILE_IS_EMPTY;

    *result = number_of_elements;
    fclose(file);

    return EXIT_SUCCESS;
}

int get_mem(int **pArr, const int sz)
{
    *pArr = malloc(sizeof(int) * sz);

    if (*pArr == NULL)
        return ERR_NULL_MEM_POINTER;

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

    for (int *i = arr_start; i < arr_end; i++)
        fprintf(file, "%d\n", *i);

    return EXIT_SUCCESS;
}
