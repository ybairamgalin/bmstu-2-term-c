#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/io_file.h"
#include "../inc/arr_handle.h"

int main(const int argc, const char *argv[])
{
    if (argc > MAX_COMMAND_LINE_ARGS || argc < MIN_COMMAND_LINE_ARGS)
        return ERR_COMMAND_LINE_ARGS_COUNT;

    if (argc == MAX_COMMAND_LINE_ARGS && strcmp(argv[3], "f") != 0)
        return ERR_COMMAND_LINE_ARGS_CONTENT;

    int error;
    int *arr_start = NULL, *arr_end;

    if ((error = read_ints_file(argv[1], &arr_start, &arr_end)))
        return error;

    int *result_start = arr_start, *result_end = arr_end;
    int *new_arr_start = NULL, *new_arr_end = NULL;

    if (argc == MAX_COMMAND_LINE_ARGS && strcmp(argv[3], "f") == 0)
    {
        if ((error = key(arr_start, arr_end, &new_arr_start, &new_arr_end))
            != EXIT_SUCCESS)
        {
            free(arr_start);
            return error;
        }

        result_start = new_arr_start;
        result_end = new_arr_end;
    }

    mysort(result_start, result_end - result_start, sizeof(int), int_cmp);
    put_int_arr_in_file(argv[2], result_start, result_end);

    free(arr_start);
    free(new_arr_start);

    return EXIT_SUCCESS;
}
