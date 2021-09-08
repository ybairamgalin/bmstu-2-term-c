#!/bin/bash
gcc main.c -std=c99 -Wpedantic -Wall -Werror -c
gcc read_movies.c -std=c99 -Wpedantic -Wall -Werror -c
gcc movie.c -std=c99 -Wpedantic -Wall -Werror -c
gcc insert_movie.c -std=c99 -Wpedantic -Wall -Werror -c
gcc *.o -Wall -Werror -Wpedantic -std=c99 -o main.exe