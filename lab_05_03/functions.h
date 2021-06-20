#pragma once

#define OK 0
#define NOT_ENOUGH_COMMAND_LINE_ARGS -1
#define COULD_NOT_CREATE_FILE -2
#define FILE_DOES_NOT_EXIST -3
#define POS_ERROR -4
#define UNKNOWN_COMMAND -5
#define EMPTY_FILE -6
#define INCORRECT_FILE_FORMAT -7

#define EQUAL_STR 0

#define NUMBER_OF_RANDOM_INT_NUMS 20

#define YES 1
#define NO 0

int create_file(const char *file_name);
int print_int_from_binary(const char *file_name);
int sort_numbers_in_file(const char *filename);
