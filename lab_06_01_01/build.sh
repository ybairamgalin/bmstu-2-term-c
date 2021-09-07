#!/bin/bash
gcc main.c -std=c99 -Wall -Werror -Wpedantic -c;
gcc movie.c -std=c99 -Wall -Werror -Wpedantic -c;
gcc read_movies.c -std=c99 -Wall -Werror -Wpedantic -c;
gcc main.o movie.o read_movies.o -std=c99 -o main.exe;
