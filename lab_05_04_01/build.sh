gcc -Wall -Werror -std=c99 main.c -c
gcc -Wall -Werror -std=c99 student.c -c
gcc -Wall -Werror -std=c99 functions.c -c
gcc -o main.exe main.o student.o functions.o
