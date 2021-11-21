CC := gcc

CFLAGS := -std=c99 -Wall -Werror -Iinc

OBJDIR := out
OUTDIR := $(shell mkdir -p out)
RELEASEFLAGS := -DNDEBUG -g0

.PHONY : func unit release debug

release : CFLAGS += $(RELEASEFLAGS)
release : lastrelease | app.exe

debug : lastdebug | app.exe

unit : unit_tests.exe
	./unit_tests.exe

lastrelease:
	touch lastrelease
	rm -rf app.exe $(OBJDIR)/*
	rm -rf lastdebug

lastdebug:
	touch lastdebug
	rm -rf app.exe $(OBJDIR)/*
	rm -rf lastrelease

app.exe : out/main.o out/matrix.o
	$(CC) $(CFLAGS) -o $@ out/matrix.o out/main.o

unit_tests.exe : out/check_main.o out/matrix.o out/check_matrix.o
	$(CC) -lcheck -g3 -o $@  $^

out/main.o : src/main.c inc/matrix.h
	$(CC) $(CFLAGS) -o $@ -c $<

out/matrix.o : src/matrix.c inc/matrix.h
	$(CC) $(CFLAGS) -o $@ -c $<

out/check_main.o : unit_tests/check_main.c inc/check_matrix.h
	$(CC) $(CFLAGS) -o $@ -c $<

out/check_matrix.o : unit_tests/check_matrix.c inc/check_matrix.h
	$(CC) $(CFLAGS) -o $@ -c $<

func : debug
	python3 func_tests/run_tests.py
