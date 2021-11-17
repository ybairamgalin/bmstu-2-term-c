#pragma once

#define OK 0
#define FILE_DOES_NOT_EXIST -1
#define WORD_LNG_ERR -2

#define IN_FILE_NAME "in.txt"
#define OUT_FILE_NAME "out.txt"

#define MAX_STR_LNG 1000
#define MAX_WORD_LNG 10
#define MAX_WORDS 100

struct text
{
    int N;
    char words[MAX_WORDS][MAX_WORD_LNG + 1];
};


void print_text(struct text text);
struct text file_to_text(FILE *file);
void reverse_text(struct  text *text);
void put_in_file(struct text text);
