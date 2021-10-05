CC := gcc

CFLAGS := -std=c99 -Wall -Werror
CHECK_FLAGS := -lcheck

OBJS := out/main.o out/io_file.o out/arr_handle.o

.PHONY : clean func_tests unit release debug

release : app.exe
debug : app.exe func_tests unit

unit : unit_tests.exe
	./unit_tests.exe

app.exe : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

unit_tests.exe : out/check_main.o out/check_io_file.o out/check_arr_handle.o out/io_file.o out/arr_handle.o
	$(CC) $(CHECK_FLAGS) -o $@ $^

out/check_arr_handle.o : unit_tests/check_arr_handle.c inc/arr_handle.h inc/check_arr_handle.h
	$(CC) $(CFLAGS) -o $@ -c $<

out/check_main.o : unit_tests/check_main.c inc/check_io_file.h
	$(CC) $(CFLAGS) -o $@ -c $<

out/check_io_file.o : unit_tests/check_io_file.c inc/check_io_file.h inc/io_file.h
	$(CC) $(CFLAGS) -o $@ -c $<

out/main.o : src/main.c inc/io_file.h inc/arr_handle.h
	$(CC) $(CFLAGS) -o $@ -c $<

out/io_file.o : src/io_file.c inc/io_file.h
	$(CC) $(CFLAGS) -o $@ -c $<

out/arr_handle.o : src/arr_handle.c inc/arr_handle.h
	$(CC) $(CFLAGS) -o $@ -c $<

func_tests :
	python3 func_tests/run_tests.py

clean :
	rm -rf *.exe
	rm -rf out/*.o
