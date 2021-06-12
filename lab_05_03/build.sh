gcc main.c -c -Wall -Werror -std=c99
gcc functions.c -c -Wall -Werror -std=c99
gcc main.o functions.o -o main.exe

