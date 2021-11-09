#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#include "movies.h"

movies_t *movies_create()
{
    movies_t *movies = malloc(sizeof(movies_t));

    if (movies == NULL)
        return NULL;

    movies->movies = malloc(sizeof(movie_t*) * START_CAPACITY);

    if (movies->movies == NULL)
    {
        free(movies);
        return NULL;
    }

    movies->capacity = START_CAPACITY;
    movies->cur_busy = 0;

    return movies;
}

static int movies_expand(movies_t *movies)
{
    int new_capacity = movies->capacity * EXPAND_TIMES;

    movies->movies = realloc(movies->movies,
        sizeof(movie_t) * movies->capacity * new_capacity);

    if (movies->movies == NULL)
        return EXIT_FAILURE;

    movies->capacity = new_capacity;

    return EXIT_SUCCESS;
}

int get_ins_pos(movies_t *movies, movie_t *movie, cmp_t cmp)
{
    for (int i = 0; i < movies->cur_busy; i++)
        if (cmp(movies->movies[i], movie) > 0)
            return i;

    return movies->cur_busy;
}

static void shift_right(movies_t *movies, const int from)
{
    for (int i = movies->cur_busy; i > from; i--)
        movies->movies[i] = movies->movies[i - 1];
}

static int insert_in_sorted(movies_t *movies, movie_t *movie,
const field_t field)
{
    int new_busy = movies->cur_busy + 1;

    if (new_busy > movies->capacity)
        if (movies_expand(movies) != EXIT_SUCCESS)
            return MEM_ERR;

    int ins_pos = get_ins_pos(movies, movie, field_to_cmp(field));
    shift_right(movies, ins_pos);
    movies->movies[ins_pos] = movie;
    movies->cur_busy = new_busy;

    return EXIT_SUCCESS;
}

int movies_read(const char *filename, movies_t *movies, field_t field)
{
    int error;
    FILE *file = fopen(filename, "r");
    movie_t *new = NULL;

    if (file == NULL)
        return NO_SUCH_FILE_ERR;

    while (1)
    {
        new = movie_create();

        if (new == NULL)
            return MEM_ERR;

        if ((error = movie_read(file, new)) != EXIT_SUCCESS)
            break;

        if (insert_in_sorted(movies, new, field) != EXIT_SUCCESS)
        {
            movie_free(new);
            fclose(file);
            return MEM_ERR;
        }
    }

    movie_free(new);
    fclose(file);

    if (error != NOTHING_TO_READ)
        return error;

    if (movies->cur_busy == 0)
        return FILE_FORMAT_ERR;

    return EXIT_SUCCESS;
}

void movies_print(movies_t *movies)
{
    for (int i = 0; i < movies->cur_busy; i++)
        movie_print(movies->movies[i]);
}

void movies_free(movies_t *movies)
{
    for (int i = 0; i < movies->cur_busy; i++)
        movie_free(movies->movies[i]);

    free(movies->movies);
    free(movies);
}

static int find_movie_index(movies_t *movies, field_t field, const char *value)
{
    if (field == year)
    {
        int year;

        if ((year = atoi(value)) == 0)
            return WRONG_FIND_VALUE_ERR;

        for (int i = 0; i < movies->cur_busy; i++)
            if (movies->movies[i]->year == year)
                return i;

        return FILM_NOT_FOUND_ERR;
    }

    if (field == title)
    {
        for (int i = 0; i < movies->cur_busy; i++)
            if (strcmp(movies->movies[i]->title, value) == 0)
                return i;

        return FILM_NOT_FOUND_ERR;
    }

    for (int i = 0; i < movies->cur_busy; i++)
        if (strcmp(movies->movies[i]->name, value) == 0)
            return i;

    return FILM_NOT_FOUND_ERR;
}

int movies_print_by_field(movies_t *movies, field_t field, const char *value)
{
    int index = find_movie_index(movies, field, value);

    if (index == WRONG_FIND_VALUE_ERR)
        return EXIT_FAILURE;

    if (index == FILM_NOT_FOUND_ERR)
        printf("Not found\n");
    else
        movie_print(movies->movies[index]);

    return EXIT_SUCCESS;
}
