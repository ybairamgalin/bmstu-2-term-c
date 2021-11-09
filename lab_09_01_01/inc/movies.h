#ifndef _MOVIES_H_
#define _MOVIES_H_

#define START_CAPACITY 16
#define EXPAND_TIMES 2

#include "movie.h"

typedef struct
{
    movie_t **movies;
    int cur_busy;
    int capacity;
} movies_t;

movies_t *movies_create();
int movies_read(const char *filename, movies_t *movies, field_t field);
void movies_print(movies_t *movies);
void movies_free(movies_t *movies);

#endif
