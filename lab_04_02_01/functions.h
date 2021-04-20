#pragma once

#define OK 0
#define INPUT_ERROR -1

#define MAX_WORDS 256

#define MAX_WORD_LNG_EXCEEDED -2

#define MAX_STR_SIZE 10 + 1
#define MAX_WORD_SIZE 16 + 1

#define WORD_IN_WORDS 1
#define WORD_NOT_IN 0

#define CHAR_END_OF_STR '\0'
#define STR_END_OF_STR "\0"

#define CHAR_END_OF_LINE '\n'

#define CHAR_END_OF_

#define CHAR_SPACE ' '
#define STR_SPACE " "

#define COMA ','
#define SEMICOLON ';'
#define COLON ':'
#define DASH '-'
#define POINT '.'
#define EXCLAMATION '!'
#define QUESTION '?'


int split(char (*words)[MAX_WORD_SIZE], char *str);
void swap_words(char *str_1, char *str_2);
void print_str_arr(char (*const words)[MAX_WORD_SIZE], const int num_of_words);
void sort_words(char (*words)[MAX_WORD_SIZE], const int num_of_words);