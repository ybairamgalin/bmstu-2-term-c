#pragma once

#define OK 0

#define MAX_WORDS 256

#define MAX_STR_SIZE 256
#define MAX_WORD_SIZE 16

#define CHAR_END_OF_LINE '\0'
#define STR_END_OF_LINE "\0"
#define CHAR_SPACE ' '

int split(const char *str, char (*const words)[MAX_WORD_SIZE]);