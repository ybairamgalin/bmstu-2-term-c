#ifndef _MOVIE_H_
#define _MOVIE_H_

#define MEM_ERR -1
#define NO_SUCH_FILE_ERR 2
#define FILE_FORMAT_ERR 3
#define NOTHING_TO_READ 4
#define FIELD_ERR 5

#define TMP_INPUT_SZ 128

#include <stdio.h>

typedef int(*cmp_t)(const void*, const void*);

typedef struct
{
    char *title;
    char *name;
    unsigned int year;
} movie_t;

typedef enum
{
    title,
    name,
    year
} field_t;

int str_to_field(field_t *field, const char *str);
cmp_t field_to_cmp(const field_t field);

movie_t *movie_create();
void movie_free(movie_t *movie);

int movie_read(FILE *file, movie_t *movie);
void movie_print(const movie_t *movie);

int movie_set_title(movie_t *movie, const char *title);
int movie_set_name(movie_t *movie, const char *name);
int movie_set_year(movie_t *movie, const unsigned int year);



#endif
