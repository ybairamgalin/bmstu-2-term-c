#ifndef _MOVIE_H_
#define _MOVIE_H_

#define OK 0
#define ERR_COMMAND_LINE_ARGS_COUNT 1
#define ERR_NO_SUCH_FILE 2
#define ERR_FILE_STRUCT_YEAR 3
#define ERR_NOTHING_TO_READ 4
#define ERR_FILE_IS_EMPTY 5
#define ERR_COMMAND_LINE_ARGS_CONTENT 6
#define ERR_UNKNOWN 7
#define ERR_MAX_STRING_LNG 8
#define ERR_EMPTY_STRING 9
#define ERR_FILE_STRUCT_NAME 10
#define ERR_KEY_CANNOT_BE_READ 11
#define ERR_TOO_MANY_FILMS 12
#define ERR_FIELD_IS_WRONG 13
#define ERR_MOVIE_NOT_FOUND -1

#define MIN_COMMAND_LINE_ARGS 3
#define MAX_COMMAND_LINE_ARGS 4
#define MAX_FILMS 15
#define MAX_TITLE_LNG 26
#define MAX_NAME_LNG 26
#define MAX_YEAR_LNG 5

typedef struct
{
    char title[MAX_TITLE_LNG + 1];
    char name[MAX_NAME_LNG + 1];
    unsigned int year;
} movie_t;

typedef enum
{
    title,
    name,
    year,
    err
} sort_by_t;

sort_by_t set_field_from_str(const char *str);
int read_movies_from_file(const char *filename, movie_t *films,
int *num_of_films, const sort_by_t field, const int max_films);
void print_movies(const movie_t *films, const int sz);
int print_movie_by_key(const movie_t *films, const int num_of_films,
const sort_by_t field, const char *key);

#endif
