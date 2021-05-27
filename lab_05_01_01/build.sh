gcc -std=c99 -Wall -Werror -c main.c
gcc -std=c99 -Wall -Werror -c functions.c
gcc main.o functions.o -o main.exe
