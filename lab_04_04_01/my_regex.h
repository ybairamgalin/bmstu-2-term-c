#pragma once

#define OK 0
#define INPUT_ERROR -1
#define REGEX_COMPILATION_FAILURE -11

#define CHAR_END_OF_LINE '\n'
#define CHAR_SPACE ' '
#define CHAR_END_OF_STR '\0'
#define CHAR_PLUS '+'
#define CHAR_MINUS '-'
#define CHAR_POINT '.'
#define CHAR_LOWER_E 'e'
#define CHAR_UPPER_E 'E'

#define MAX_STR_SIZE 256 + 1

#define IS_NUM 1
#define IS_NOT_NUM 0

#define MATCH 0

int is_exp_num(const char *str);
