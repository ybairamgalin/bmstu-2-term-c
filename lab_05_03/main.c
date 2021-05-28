#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <sys/stat.h>

#define OK 0
#define NOT_ENOUGH_COMMAND_LINE_ARGS -1
#define COULD_NOT_CREATE_FILE -2
#define FILE_DOES_NOT_EXIST -3

#define EQUAL_STR 0

#define NUMBER_OF_RANDOM_INT_NUMS 20


int create_file(char *file_name)
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

int read_int_from_binary(char *file_name)
{
    FILE *file;
    file = fopen(file_name, "rb");

    if (file == NULL)
        return FILE_DOES_NOT_EXIST;

    struct stat st;
    stat(file_name, &st);

    for (size_t i = 0; i < st.st_size / sizeof(int); i++)
    {
        int number;
        size_t read = fread(&number, sizeof(int), 1, file);

        if (read == 1)
            printf("%d ", number);
        else
            break;
    }

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
        if (read_int_from_binary(argv[2]) != OK)
            return FILE_DOES_NOT_EXIST;
    }
    else if (strcmp(argv[1], "s") == EQUAL_STR)
    {

    }

    return OK;
}