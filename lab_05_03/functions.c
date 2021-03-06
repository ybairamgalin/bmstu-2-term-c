#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "functions.h"

int create_file(const char *file_name)
{
    char full_file_name[64];
    strcpy(full_file_name, "files/");
    strcat(full_file_name, file_name);

    FILE *file;
    file = fopen(full_file_name, "wb");

    if (file == NULL)
        return COULD_NOT_CREATE_FILE;

    srand(time(NULL));

    for (int i = 0; i < NUMBER_OF_RANDOM_INT_NUMS; i++)
    {
        int number = rand() % 1000;
        fwrite(&number, sizeof(int), 1, file);
    }

    fclose(file);

    return OK;
}

int print_int_from_binary(const char *file_name)
{
    FILE *file;
    file = fopen(file_name, "rb");

    if (file == NULL)
    {
        printf("Error: no such file");

        return FILE_DOES_NOT_EXIST;
    }

    int number;

    if (fread(&number, sizeof(int), 1, file) == 1)
        printf("%d ", number);
    else
    {
        fclose(file);
        return EMPTY_FILE;
    }

    while (fread(&number, sizeof(int), 1, file) == 1)
        printf("%d ", number);

    fclose(file);

    return OK;
}

int get_number_by_pos(FILE *file, const int pos, int *num)
{
    fseek(file, pos * sizeof(int), SEEK_SET);
    size_t read = fread(num, sizeof(int), 1, file);

    if (read == 1)
        return OK;
    else
        return POS_ERROR;
}

int put_number_by_pos(FILE *file, const int pos, const int num)
{
    fseek(file, pos * sizeof(int), SEEK_SET);
    size_t put = fwrite(&num, sizeof(int), 1, file);

    if (put == 1)
        return OK;
    else
        return POS_ERROR;
}

void compare_and_swap(FILE *file, const int first, const int second)
{
    int num_1, num_2;

    get_number_by_pos(file, first, &num_1);
    get_number_by_pos(file, second, &num_2);

    if (num_1 > num_2)
    {
        // swap
        put_number_by_pos(file, second, num_1);
        put_number_by_pos(file, first, num_2);
    }
}

void bubble_sort_binary_file(FILE *file, size_t size)
{
    for (int i = 0; i < size / sizeof(int); i++)
        for (int j = i + 1; j < size / sizeof(int); j++)
            compare_and_swap(file, i, j);
}

int sort_numbers_in_file(const char *filename)
{
    FILE *file;
    file = fopen(filename, "rb");

    if (file == NULL)
    {
        printf("Error: no such file");

        return FILE_DOES_NOT_EXIST;
    }

    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    fseek(file, 0, SEEK_SET);

    if (size % sizeof(int) != 0)
    {
        printf("Error: file format");

        return INCORRECT_FILE_FORMAT;
    }

    if (size == 0)
    {
        printf("Error: file is empty");

        return EMPTY_FILE;
    }


    fclose(file);
    file = fopen(filename, "rb+");

    bubble_sort_binary_file(file, size);

    fclose(file);

    return OK;
}
