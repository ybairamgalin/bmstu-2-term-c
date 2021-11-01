CC := gcc

CFLAGS := -std=c99 -Wall -Werror -Wpedantic -Iinc

RELEASEFLAGS := -DNDEBUG -g0

release : CFLAGS += $(RELEASEFLAGS)
release : lastrelease | app.exe

debug : lastdebug | app.exe

lastrelease:
	touch release
	rm -rf app.exe obj/*
	rm -rf debug

lastdebug:
	touch debug
	rm -rf app.exe obj/*
	rm -rf release

app.exe : out/main.o out/matrix.o
	$(CC) $(CFLAGS) -o $@ out/matrix.o out/main.o

out/main.o: src/main.c inc/matrix.h
	$(CC) $(CFLAGS) -o $@ -c $<

out/matrix.o: src/matrix.c inc/matrix.h
	$(CC) $(CFLAGS) -o $@ -c $<

