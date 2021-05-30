#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <sys/stat.h>

#define OK 0
#define NOT_ENOUGH_COMMAND_LINE_ARGS -1
#define COULD_NOT_CREATE_FILE -2
#define FILE_DOES_NOT_EXIST -3
#define POS_ERROR -4
#define UNKNOWN_COMMAND -5
#define EMPTY_FILE -6
#define INCORRECT_FILE_FORMAT -7

#define EQUAL_STR 0

#define NUMBER_OF_RANDOM_INT_NUMS 20

#define YES 1
#define NO 0

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

    struct stat st;
    stat(file_name, &st);

    if (st.st_size % sizeof(int) != 0)
    {
        printf("Error: file format");

        return INCORRECT_FILE_FORMAT;
    }

    for (size_t i = 0; i < st.st_size / sizeof(int); i++)
    {
        int number;
        size_t read = fread(&number, sizeof(int), 1, file);

        if (read == 1)
            printf("%d ", number);
        else
            break;
    }

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

void bubble_sort_binary_file(FILE *file)
{
    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    fseek(file, 0, SEEK_SET);

    for (int i = 0; i < size / sizeof(int); i++)
        for (int j = i + 1; j < size / sizeof(int); j++)
            compare_and_swap(file, i, j);
}

int sort_numbers_in_file(const char *filename)
{
    FILE *file;
    file = fopen(filename, "rb+");

    if (file == NULL)
        return FILE_DOES_NOT_EXIST;

    bubble_sort_binary_file(file);

    fclose(file);

    return OK;
}

int main(const int argc, char **argv)
{
    if (argc != 3)
        return NOT_ENOUGH_COMMAND_LINE_ARGS;

    if (strcmp(argv[1], "c") == EQUAL_STR)
    {
        if (create_file(argv[2]) != OK)
            return COULD_NOT_CREATE_FILE;
    }
    else if (strcmp(argv[1], "p") == EQUAL_STR)
    {
        if (print_int_from_binary(argv[2]) != OK)
            return FILE_DOES_NOT_EXIST;
    }
    else if (strcmp(argv[1], "s") == EQUAL_STR)
    {
        if (sort_numbers_in_file(argv[2]) != OK)
            return FILE_DOES_NOT_EXIST;
    }
    else
        return UNKNOWN_COMMAND;

    return OK;
}
