CC := gcc

OBJDIR := out
INCDIR := inc

CFLAGS := -std=c99 -Wall -Werror -I$(INCDIR)
DEBUGFLAGS := -g -fno-inline -fno-omit-frame-pointer
RELEASEFLAGS := -DNDEBUG -g0
CHECK_FLAGS := -lcheck

OUTDIR := $(shell mkdir -p out)
OBJS := $(OBJDIR)/main.o $(OBJDIR)/movie.o $(OBJDIR)/movies.o
UNITOBJS := $(OBJDIR)/check_movie.o $(OBJDIR)/check_main.o $(OBJDIR)/movie.o
CHECK_FLAGS := -lcheck -g3

.PHONY : clean func_tests unit release debug

release : CFLAGS += $(RELEASEFLAGS)
release : lastrelease | app.exe

debug : CFLAGS += $(DEBUGFLAGS)
debug : lastdebug | app.exe func_tests unit
unit : unit_tests.exe

lastdebug:
	touch lastdebug
	rm -rf app.exe $(OBJDIR)/*
	rm -rf lastrelease

lastrelease:
	touch lastrelease
	rm -rf app.exe $(OBJDIR)/*
	rm -rf lastdebug

app.exe : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

unit_tests.exe : $(UNITOBJS)
	$(CC) $(CHECK_FLAGS) -o $@  $^

$(OBJDIR)/main.o : src/main.c inc/movie.h
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJDIR)/movie.o : src/movie.c inc/movie.h
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJDIR)/movies.o : src/movies.c inc/movies.h
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJDIR)/check_main.o : unit_tests/check_main.c inc/check_movie.h
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJDIR)/check_movie.o : unit_tests/check_movie.c inc/check_movie.h inc/movie.h
	$(CC) $(CFLAGS) -o $@ -c $<

func_tests :
	python3 func_tests/run_tests.py

clean :
	rm -rf *.exe
	rm -rf $(OBJDIR)/*.o
	rm -rf $(OBJDIR)/.*gcda
	rm -rf $(OBJDIR)/.*gcno

