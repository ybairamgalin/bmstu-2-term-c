CFLAGS := -std=c99 -Wall -Werror -Wpedantic

app.exe : out/main.o out/read_file.o
	gcc $(CFLAGS)  -o app.exe out/main.o out/read_file.o

out/main.o : src/main.c inc/read_file.h
	gcc $(CFLAGS) -o out/main.o -c src/main.c

out/read_file.o : src/read_file.c inc/read_file.h
	gcc $(CFLAGS) -o out/read_file.o -c src/read_file.c