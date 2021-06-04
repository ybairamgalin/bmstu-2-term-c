#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "student.h"
#include "functions.h"

#define FILE_DOES_NOT_EXIST -1
#define FILE_SIZE_ERROR -2
#define NO_STUDENTS_FOUND -3

#define MAX_STUDENTS 100

#define EQUAL_STRINGS 0

void find_average_student_mark(FILE *file, size_t size, float *average)
{
    size_t num_of_students = size / sizeof(struct student);
    struct student student;
    fseek(file, 0, SEEK_SET);

    for (size_t i = 0; i < num_of_students; i++)
    {
        fseek(file, sizeof(struct student) * i, SEEK_SET);
        fread(&student, sizeof(struct student), 1, file);
        float sum = 0;

        for (size_t j = 0; j < NUM_OF_SUBJECTS; j++)
            sum += student.marks[j];

        average[i] = sum / (float)NUM_OF_SUBJECTS;
    }
}

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

void del_nth_student(FILE *file, const int number_of_students, const int pos)
{
    struct student student;

    for (int i = pos; i < number_of_students - 1; i++)
    {
        fseek(file, (i + 1) * sizeof(struct student), SEEK_SET);
        fread(&student, sizeof(struct student), 1, file);

        fseek(file, i * sizeof(struct student), SEEK_SET);
        fwrite(&student, sizeof(struct student), 1, file);
    }

    fseek(file, 0, SEEK_SET);
    ftruncate(fileno(file), sizeof(struct student) * (number_of_students - 1));
}

void delete_with_low_average(FILE *file, size_t sz, float *avg_arr,
const float common_average)
{
    int number_of_students = sz / sizeof(struct student);
    int current = 0;

    while (current < number_of_students)
    {
        if (avg_arr[current] < common_average)
        {
            del_nth_student(file, number_of_students, current);
            del_arr_elem(avg_arr, number_of_students--, current);
        }
        else
            current++;
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

    bubble_sort_students(file, file_sz);
    print_file(file, file_sz);

    return OK;
}

int delete_worst_students(const char *filename)
{
    FILE *file;
    file = fopen(filename, "rb+");

    if (file == NULL)
        return FILE_DOES_NOT_EXIST;

    size_t file_sz;

    int rc = file_size(file, &file_sz);

    if (rc != 0 || file_sz % sizeof(struct student) || file_sz == 0)
        return FILE_SIZE_ERROR;

    float average[MAX_STUDENTS];
    find_average_student_mark(file, file_sz, average);
    float common_average = find_average(average,
        file_sz / sizeof(struct student));
    delete_with_low_average(file, file_sz, average, common_average);

    fclose(file);

    return OK;
}

int str_begins_with(const char *src, const char *cmp)
{
    size_t len_src = strlen(src);
    size_t len_cmp = strlen(cmp);

    if (len_src < len_cmp)
        return 0;

    for (size_t i = 0; i < len_cmp; i++)
        if (cmp[i] != src[i])
            return 0;

    return 1;
}

int cpy_students_to_file_by_surname(FILE *src, const size_t src_sz, FILE *dest,
const char *substr)
{
    const int number_of_students = src_sz / sizeof(struct student);
    struct student student;
    int written = 0;

    fseek(src, 0, SEEK_SET);
    fseek(dest, 0, SEEK_SET);

    for (int i = 0; i < number_of_students; i++)
    {
        fread(&student, sizeof(struct student), 1, src);

        if (str_begins_with(student.surname, substr))
        {
            fwrite(&student, sizeof(struct student), 1, dest);
            written++;
        }
    }

    return written;
}

int print_students_by_surname(const char *src_file, const char *dest_file,
const char *substr)
{
    FILE *src, *dest;
    src = fopen(src_file, "rb");
    dest = fopen(dest_file, "wb");

    if (src == NULL)
        return FILE_DOES_NOT_EXIST;

    size_t file_sz;

    int rc = file_size(src, &file_sz);

    if (rc != 0 || file_sz % sizeof(struct student) || file_sz == 0)
        return FILE_SIZE_ERROR;

    if (cpy_students_to_file_by_surname(src, file_sz, dest, substr) == 0)
        return NO_STUDENTS_FOUND;

    return OK;
}