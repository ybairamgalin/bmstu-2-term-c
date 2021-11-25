CC := gcc

OBJDIR := out
INCDIR := inc

CFLAGS := -std=c99 -Wall -Werror -I$(INCDIR)
DEBUGFLAGS := -g -fno-inline -fno-omit-frame-pointer
RELEASEFLAGS := -DNDEBUG -g0
CHECK_FLAGS := -lcheck -g3

OUTDIR := $(shell mkdir -p out)
OBJS := $(OBJDIR)/main.o $(OBJDIR)/linked_list.o
UNITOBJS := $(OBJDIR)/check_linked_list.o $(OBJDIR)/check_main.o $(OBJDIR)/linked_list.o

.PHONY : clean func_tests unit release debug

release : CFLAGS += $(RELEASEFLAGS)
release : lastrelease | app.exe

debug : CFLAGS += $(DEBUGFLAGS)
debug : lastdebug | app.exe

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

$(OBJDIR)/main.o : src/main.c inc/linked_list.h
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJDIR)/linked_list.o : src/linked_list.c inc/linked_list.h
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJDIR)/check_main.o : unit_tests/check_main.c inc/check_linked_list.h
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJDIR)/check_linked_list.o : unit_tests/check_linked_list.c inc/check_linked_list.h inc/linked_list.h
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	rm -rf *.exe
	rm -rf $(OBJDIR)/*.o
	rm -rf $(OBJDIR)/.*gcda
	rm -rf $(OBJDIR)/.*gcno
