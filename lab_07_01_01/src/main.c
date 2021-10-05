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

    int nums_in_file, error;
    int *arr = NULL;

    if ((error = get_number_of_int_in_file(argv[1], &nums_in_file)) !=
            EXIT_SUCCESS)
        return error;

    if ((error = get_mem(&arr, nums_in_file)) != EXIT_SUCCESS)
        return error;

    int *result_start = arr, *result_end = arr + nums_in_file;
    read_nums_from_file(argv[1], arr, arr + nums_in_file);

    if (argc == MAX_COMMAND_LINE_ARGS && strcmp(argv[3], "f") == 0)
        if ((error = filter_del_src(arr, arr + nums_in_file,
            &result_start, &result_end)) != EXIT_SUCCESS)
            return error;

    mysort(result_start, result_end - result_start, sizeof(int), int_cmp);
    put_int_arr_in_file(argv[2], result_start, result_end);
    free(result_start);

    return EXIT_SUCCESS;
}
