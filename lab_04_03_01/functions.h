#pragma once

#define OK 0
#define INPUT_ERROR -1

#define MAX_WORDS 256

#define MAX_WORD_LNG_EXCEEDED -2

#define MAX_STR_SIZE 256 + 1
#define MAX_WORD_SIZE 16 + 1

#define WORDS_ARE_EQUAL 0

#define SEPARATORS " ,;:-.?!\n"

#define CHAR_END_OF_STR '\0'
#define CHAR_END_OF_LINE '\n'

#define EMPTY_STRING ""

#define YES 1
#define NO 0


int split_and_solve(char *string, char (*dest_array)[MAX_WORD_SIZE]);
void print_result(char (*dest_array)[MAX_WORD_SIZE], const int size);
void set_as_last_empty(char (*array)[MAX_WORD_SIZE], const int size);
void del_first_appear_letter(char *word);