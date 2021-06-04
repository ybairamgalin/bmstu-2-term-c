#pragma once

#define OK 0

#define MAX_SURNAME_SIZE 25
#define MAX_NAME_SIZE 10
#define NUM_OF_SUBJECTS 4

struct student
{
    char surname[MAX_SURNAME_SIZE + 1];
    char name[MAX_NAME_SIZE + 1];
    int marks[NUM_OF_SUBJECTS];
};

int print_students_by_surname(const char *src_file, const char *dest_file,
    const char *substr);
int delete_worst_students(const char *filename);
int sort_by_surname(const char *filename);
