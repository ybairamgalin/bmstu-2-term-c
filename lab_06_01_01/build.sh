gcc main.c -Wall -Werror -Wpedantic -c
gcc movie.c -Wall -Werror -Wpedantic -c
gcc main.o movie.o -o main.exe
