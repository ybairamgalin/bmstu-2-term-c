CFLAGS := -std=c99 -Wall -Werror -Wpedantic

app.exe : out/main.o out/io_file.o out/arr_handle.o
	gcc $(CFLAGS) -o app.exe out/main.o out/io_file.o out/arr_handle.o

out/main.o : src/main.c inc/io_file.h inc/arr_handle.h
	gcc $(CFLAGS) -o out/main.o -c src/main.c

out/io_file.o : src/io_file.c inc/io_file.h
	gcc $(CFLAGS) -o out/io_file.o -c src/io_file.c

out/arr_handle.o : src/arr_handle.c inc/arr_handle.h
	gcc $(CFLAGS) -o out/arr_handle.o -c src/arr_handle.c
