#pragma once

#define OK 0
#define ERR_COMMAND_LINE_ARGS_COUNT 1
#define ERR_NO_SUCH_FILE 2
#define ERR_FILE_STRUCT 3
#define ERR_NOTHING_TO_READ 4
#define ERR_FILE_IS_EMPTY 5
#define ERR_COMMAND_LINE_ARGS_CONTENT 6

#define MIN_COMMAND_LINE_ARGS 3
#define MAX_COMMAND_LINE_ARGS 4
#define MAX_FIlMS 100

#define MAX_TITLE_LNG 26
#define MAX_NAME_LNG 26
#define MAX_YEAR_LNG 5

typedef struct
{
    char title[MAX_TITLE_LNG + 1];
    char name[MAX_NAME_LNG + 1];
    unsigned int year;
} movie;

typedef enum
{
    title,
    name,
    year,
    err
} sort_by;

sort_by set_field_from_str(const char *str);
int read_movies_from_file(const char *filename, movie *films,
                          int *num_of_films, const sort_by field);
void print_movies(const movie *films, const int sz);
