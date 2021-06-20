gcc -std=c99 -Wall -Werror -c main.c
gcc -std=c99 -Wall -Werror -c my_regex.c
gcc -o main.exe main.o my_regex.o
