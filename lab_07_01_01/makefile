CC := gcc

OBJDIR := out
INCDIR := inc

CFLAGS := -std=c99 -Wall -Werror -I$(INCDIR)
DEBUGFLAGS := -g3
RELEASEFLAGS := -DNDEBUG -g0
CHECK_FLAGS := -lcheck

OUTDIR := $(shell mkdir -p out)
OBJS := $(OBJDIR)/main.o $(OBJDIR)/io_file.o $(OBJDIR)/arr_handle.o
UNITOBJS := $(OBJDIR)/check_main.o $(OBJDIR)/check_io_file.o $(OBJDIR)/check_arr_handle.o $(OBJDIR)/io_file.o $(OBJDIR)/arr_handle.o

.PHONY : clean func_tests unit release debug

release : CFLAGS += $(RELEASEFLAGS)
release : lastrelease | app.exe

debug : CFLAGS += $(DEBUGFLAGS)
debug : lastdebug | app.exe func_tests unit

lastdebug:
	touch lastdebug
	rm -rf app.exe $(OBJDIR)/*
	rm -rf lastrelease

lastrelease:
	touch lastrelease
	rm -rf app.exe $(OBJDIR)/*
	rm -rf lastdebug

unit : unit_tests.exe
	./unit_tests.exe

app.exe : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

unit_tests.exe : $(UNITOBJS)
	$(CC) $(CHECK_FLAGS) -o $@ $^

$(OBJDIR)/check_arr_handle.o : unit_tests/check_arr_handle.c inc/arr_handle.h inc/check_arr_handle.h
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJDIR)/check_main.o : unit_tests/check_main.c inc/check_io_file.h out_folder
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJDIR)/check_io_file.o : unit_tests/check_io_file.c inc/check_io_file.h inc/io_file.h
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJDIR)/main.o : src/main.c inc/io_file.h inc/arr_handle.h
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJDIR)/io_file.o : src/io_file.c inc/io_file.h
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJDIR)/arr_handle.o : src/arr_handle.c inc/arr_handle.h
	$(CC) $(CFLAGS) -o $@ -c $<

func_tests :
	python3 func_tests/run_tests.py

clean :
	rm -rf *.exe
	rm -rf $(OBJDIR)/*.o
	rm -rf $(OBJDIR)/.*gcda
	rm -rf $(OBJDIR)/.*gcno
