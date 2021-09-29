#ifndef __IO_FILE_H__
#define __IO_FILE_H__

#define MIN_COMMAND_LINE_ARGS 3
#define MAX_COMMAND_LINE_ARGS 4

#define MAX_LINE_LNG 20

#define ERR_FILE_DOES_NOT_EXIST 1
#define ERR_COMMAND_LINE_ARGS_COUNT 2
#define ERR_FILE_IS_EMPTY 3

int get_number_of_int_in_file(const char *filename, int *result);
int read_nums_from_file(const char *filename, int *dest_start, int *dest_end);
int put_int_arr_in_file(const char *filename, int *arr_start,
int *arr_end);

#endif