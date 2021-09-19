#ifndef _READ_MOVIES_H_
#define _READ_MOVIES_H_

int read_movies_from_file(const char *filename, movie_t *films,
int *num_of_films, const sort_by_t field, const int max_films);

#endif
