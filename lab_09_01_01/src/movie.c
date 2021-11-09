#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"

int title_cmp(const void *first, const void *second)
{
    movie_t *first_movie = (movie_t*)first;
    movie_t *second_movie = (movie_t*)second;

    return strcmp((*first_movie).title, (*second_movie).title);
}

int name_cmp(const void *first, const void *second)
{
    movie_t *first_movie = (movie_t*)first;
    movie_t *second_movie = (movie_t*)second;

    return strcmp((*first_movie).name, (*second_movie).name);
}

int year_cmp(const void *first, const void *second)
{
    movie_t *first_movie = (movie_t*)first;
    movie_t *second_movie = (movie_t*)second;

    if (first_movie->year > second_movie->year)
        return 1;

    if (first_movie->year < second_movie->year)
        return -1;

    return 0;
}

cmp_t field_to_cmp(const field_t field)
{
    if (field == title)
        return title_cmp;

    if (field == name)
        return name_cmp;

    return year_cmp;
}

int movie_set_title(movie_t *movie, const char *title)
{
    movie->title = realloc(movie->title, (strlen(title) + 1) * sizeof(char));

    if (movie->title == NULL)
        return EXIT_FAILURE;

    strcpy(movie->title, title);

    return EXIT_SUCCESS;
}

int movie_set_name(movie_t *movie, const char *name)
{
    movie->name = realloc(movie->name, (strlen(name) + 1) * sizeof(char));

    if (movie->name == NULL)
        return EXIT_FAILURE;

    strcpy(movie->name, name);

    return EXIT_SUCCESS;
}

int movie_set_year(movie_t *movie, const unsigned int year)
{
    movie->year = year;

    return EXIT_SUCCESS;
}

//static cmp_t cmp_by_field(field_t field)
//{
//    return title_cmp;
//}

static int read_title(FILE *file, movie_t *movie)
{
    char tmp[TMP_INPUT_SZ];

    if (fgets(tmp, sizeof(tmp), file) == NULL)
        return NOTHING_TO_READ;

    if (tmp[strlen(tmp) - 1] != '\n')
        return FILE_FORMAT_ERR;

    tmp[strlen(tmp) - 1] = '\0';

    if (tmp[strlen(tmp) - 1] == '\r')
        tmp[strlen(tmp) - 1] = '\0';

    if (strlen(tmp) == 0)
        return FILE_FORMAT_ERR;

    if (movie_set_title(movie, tmp) != EXIT_SUCCESS)
        return MEM_ERR;

    return EXIT_SUCCESS;
}

static int read_name(FILE *file, movie_t *movie)
{
    char tmp[TMP_INPUT_SZ];

    if (fgets(tmp, sizeof(tmp), file) == NULL)
        return FILE_FORMAT_ERR;

    if (tmp[strlen(tmp) - 1] != '\n')
        return FILE_FORMAT_ERR;

    tmp[strlen(tmp) - 1] = '\0';

    if (tmp[strlen(tmp) - 1] == '\r')
        tmp[strlen(tmp) - 1] = '\0';

//    printf("\n%s %lu\n", tmp, strlen(tmp));

    if (strlen(tmp) == 0)
        return FILE_FORMAT_ERR;

    if (movie_set_name(movie, tmp) != EXIT_SUCCESS)
        return MEM_ERR;

//    printf("%s ", movie->name);
//    printf("%lu\n", strlen(movie->name));

    return EXIT_SUCCESS;
}

static int read_year(FILE *file, movie_t *movie)
{
    char tmp[TMP_INPUT_SZ];

    if (fgets(tmp, sizeof(tmp), file) == NULL)
        return FILE_FORMAT_ERR;

    if (strchr(tmp, '.') != NULL || strchr(tmp, ',') != NULL)
        return FILE_FORMAT_ERR;

    int year;

    if ((year = atoi(tmp)) == 0)
        return FILE_FORMAT_ERR;

    if (year <= 0)
        return FILE_FORMAT_ERR;

    movie_set_year(movie, (unsigned int)year);

    return EXIT_SUCCESS;
}

movie_t *movie_create()
{
    movie_t *movie = malloc(sizeof(movie_t));

    if (movie == NULL)
        return NULL;

    movie->title = NULL;
    movie->name = NULL;
    movie->year = 0;

    return movie;
}

void movie_free(movie_t *movie)
{
    if (movie == NULL)
        return;

    free(movie->title);
    free(movie->name);
    free(movie);
}

int movie_read(FILE *file, movie_t *movie)
{
    int error;

    if (movie == NULL)
        return MEM_ERR;

    if ((error = read_title(file, movie)) != EXIT_SUCCESS)
        return error;

    if ((error = read_name(file, movie)) != EXIT_SUCCESS)
        return error;

    if ((error = read_year(file, movie)) != EXIT_SUCCESS)
        return error;

    return EXIT_SUCCESS;
}

void movie_print(const movie_t *movie)
{
    printf("%s\n%s\n%d\n", movie->title, movie->name, movie->year);
}

int str_to_field(field_t *field, const char *str)
{
    if (strcmp(str, "title") == 0)
        *field = title;
    else if (strcmp(str, "name") == 0)
        *field = name;
    else if (strcmp(str, "year") == 0)
        *field = year;
    else
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
