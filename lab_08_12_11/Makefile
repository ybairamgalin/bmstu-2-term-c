CC := gcc

OBJDIR := out
INCDIR := inc

CFLAGS := -std=c99 -Wall -Werror -I$(INCDIR)
DEBUGFLAGS := -g -fno-inline -fno-omit-frame-pointer -ggdb
RELEASEFLAGS := -DNDEBUG -g0
CHECK_FLAGS := -lcheck

OUTDIR := $(shell mkdir -p out)
OBJS := $(OBJDIR)/main.o $(OBJDIR)/matrix.o
UNITOBJS := $(OBJDIR)/check_matrix.o $(OBJDIR)/check_main.o $(OBJDIR)/matrix.o
CHECK_FLAGS := -lcheck -g3

.PHONY : clean func_tests unit release debug

release : CFLAGS += $(RELEASEFLAGS)
release : lastrelease | app.exe

debug : CFLAGS += $(DEBUGFLAGS)
debug : lastdebug | app.exe func_tests unit
unit : unit_tests.exe
	./unit_tests.exe

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

$(OBJDIR)/main.o : src/main.c inc/matrix.h
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJDIR)/matrix.o : src/matrix.c inc/matrix.h
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJDIR)/check_main.o : unit_tests/check_main.c inc/check_matrix.h
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJDIR)/check_matrix.o : unit_tests/check_matrix.c inc/check_matrix.h inc/matrix.h
	$(CC) $(CFLAGS) -o $@ -c $<


func_tests :
	python3 func_tests/run_tests.py

clean :
	rm -rf *.exe
	rm -rf $(OBJDIR)/*.o
	rm -rf $(OBJDIR)/.*gcda
	rm -rf $(OBJDIR)/.*gcno
