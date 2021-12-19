CC := gcc

SRCDIR := src
OBJDIR := out
INCDIR := inc
TSTDIR := unit_tests

$(shell mkdir -p $(OBJDIR))

CFLAGS := -Wall -Werror -std=c99 -I$(INCDIR)
RLSFLAGS := -g -O3
DBGFLAGS := -DNDEBUG -O0

ULINKFLSGS := -lcheck

OBJS := $(OBJDIR)/main.o $(OBJDIR)/queue.o $(OBJDIR)/stack.o
UOBJS := $(OBJDIR)/check_main.o $(OBJDIR)/check_queue.o $(OBJDIR)/queue.o $(OBJDIR)/stack.o

.PHONY : release
release : CFLAGS += $(RLSFLAGS)
release : release.last | app.exe

.PHONY : debug
debug : CFLAGS += $(DBGFLAGS)
debug : debug.last | app.exe

.PHONY : unit
unit : unit_tests.exe
	./unit_tests.exe

app.exe : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

unit_tests.exe : $(UOBJS)
	$(CC) $(CFLAGS) $(ULINKFLSGS) -o $@ $(UOBJS)

$(OBJDIR)/check_main.o : $(TSTDIR)/check_main.c $(INCDIR)/check_queue.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/check_queue.o : $(TSTDIR)/check_queue.c $(INCDIR)/check_queue.h $(INCDIR)/queue.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(SRCDIR)/%.d
	$(CC) $(CFLAGS) -c -o $@ $<

$(SRCDIR)/%.d : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -MM -MF$(SRCDIR)/$*.d -MT$@ $<

-include $(SRCS:.c=.d)

release.last :
	rm -rf debug.last
	rm -rf app.exe $(OBJDIR)/*
	touch release.last

debug.last :
	rm -rf release.last
	rm -rf app.exe $(OBJDIR)/*
	touch debug.last

.PHONY : clean
clean :
	rm -rf *.last
	rm -rf app.exe $(OBJDIR)/*
