#include <stdio.h>
#include <stdlib.h>
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

int movies_push_back(movies_t *movies, movie_t *new)
{
    int new_busy = movies->cur_busy + 1;

    if (new_busy > movies->capacity)
        if (movies_expand(movies) != EXIT_SUCCESS)
            return MEM_ERR;

    movies->movies[(movies->cur_busy)++] = new;
    movies->cur_busy = new_busy;

    return EXIT_SUCCESS;
}

int movies_read(const char *filename, movies_t *movies, field_t field)
{
    int error;
    FILE *file = fopen(filename, "r");

    if (file == NULL)
        return NO_SUCH_FILE_ERR;

    while (1)
    {
        movie_t *new = movie_create();

        if ((error = movie_read(file, new)) != EXIT_SUCCESS)
            break;

        if (movies_push_back(movies, new) != EXIT_SUCCESS)
        {
            fclose(file);
            return MEM_ERR;
        }
    }

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
