CFLAGS := -std=c99 -Wall -Werror -Wpedantic
CHECK_FLAGS := -lcheck


release : app.exe
debug : app.exe func_tests

unit : unit_tests.exe
	./unit_tests.exe

app.exe : out/main.o out/io_file.o out/arr_handle.o
	gcc $(CFLAGS) -o app.exe out/main.o out/io_file.o out/arr_handle.o

unit_tests.exe : out/arr_handle.o out/check_arr_handle.o out/check_main.o
	gcc $(CHECK_FLAGS) -o unit_tests.exe out/arr_handle.o out/check_arr_handle.o out/check_main.o

out/check_main.o : unit_tests/check_main.c inc/check_arr_handle.h
	gcc -o $(CFLAGS) out/check_main.o -c unit_tests/check_main.c

out/check_arr_handle.o : unit_tests/check_arr_handle.c inc/arr_handle.h
	gcc -o $(CFLAGS) out/check_arr_handle.o -c unit_tests/check_arr_handle.c

out/main.o : src/main.c inc/io_file.h inc/arr_handle.h
	gcc $(CFLAGS) -o out/main.o -c src/main.c

out/io_file.o : src/io_file.c inc/io_file.h
	gcc $(CFLAGS) -o out/io_file.o -c src/io_file.c

out/arr_handle.o : src/arr_handle.c inc/arr_handle.h
	gcc $(CFLAGS) -o out/arr_handle.o -c src/arr_handle.c

.PHONY : func_tests

func_tests :
	python3 func_tests/run_tests.py

.PHONY : clean

clean :
	rm -rf *.exe
	rm -rf out/*.o
