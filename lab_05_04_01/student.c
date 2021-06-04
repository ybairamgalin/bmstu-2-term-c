#include <stdio.h>
#include <string.h>
#include "student.h"
#include "functions.h"

#define FILE_DOES_NOT_EXIST -1
#define FILE_SIZE_ERROR -2

#define EQUAL_STRINGS 0

void print_student(struct student student)
{
    printf("%s\n", student.surname);
    printf("%s\n", student.name);
    printf("%d %d %d %d\n", student.marks[0], student.marks[1],
    student.marks[2], student.marks[3]);
}

void print_file(FILE *file, size_t size)
{
    size_t num_of_students = size / sizeof(struct student);
    struct student student;
    fseek(file, 0, SEEK_SET);

    for (size_t i = 0; i < num_of_students; i++)
    {
        fread(&student, sizeof(struct student), 1, file);
        print_student(student);
    }
}

int students_cmp(struct student first, struct student second)
{
    int cmp = strcmp(first.surname, second.surname);

    if (cmp > 0)
        return 1;

    if (cmp < 0)
        return -1;

    if (cmp == EQUAL_STRINGS)
    {
        cmp = strcmp(first.name, second.name);

        if (cmp > 0)
            return 1;

        if (cmp < 0)
            return -1;
    }

    return EQUAL_STRINGS;
}

void bubble_sort_students(FILE *file, size_t size)
{
    size_t size_of_student = sizeof(struct student);
    size_t num_of_students = size / size_of_student;

    struct student first;
    struct student second;

    for (size_t i = 0; i < num_of_students; i++)
        for (size_t j = i + 1; j < num_of_students; j++)
        {
            fseek(file, size_of_student * i, SEEK_SET);
            fread(&first, size_of_student, 1, file);

            fseek(file, size_of_student * j, SEEK_SET);
            fread(&second, size_of_student, 1, file);

            if (students_cmp(first, second) > 0)
            {
                fseek(file, size_of_student * i, SEEK_SET);
                fwrite(&second, size_of_student, 1, file);

                fseek(file, size_of_student * j, SEEK_SET);
                fwrite(&first, size_of_student, 1, file);
            }
        }
}

int sort_by_surname(const char *filename)
{
    FILE *file;
    file = fopen(filename, "rb+");

    if (file == NULL)
        return FILE_DOES_NOT_EXIST;

    size_t file_sz;

    int rc = file_size(file, &file_sz);

    if (rc != 0 || file_sz % sizeof(struct student) || file_sz == 0)
        return FILE_SIZE_ERROR;

//    if ((file_sz / sizeof(struct student)) != 0)
//        return FILE_SIZE_ERROR;

    bubble_sort_students(file, file_sz);
    print_file(file, file_sz);

    return OK;
}

int delete_worst_students(const char *filename)
{
    return OK;
}

int print_students_by_surname(const char *filename)
{
    return OK;
}