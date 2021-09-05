gcc main.c -Wall -Werror -Wpedantic -c
gcc movie.c -Wall -Werror -Wpedantic -c
gcc read_movies.c -Wall -Werror -Wpedantic -c
gcc main.o movie.o read_movies.o -o main.exe
