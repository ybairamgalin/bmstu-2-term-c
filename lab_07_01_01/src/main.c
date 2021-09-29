#include <stdio.h>
#include <stdlib.h>
#include "../inc/io_file.h"
#include "../inc/arr_handle.h"

int main(const int argc, const char *argv[])
{
    if (argc > MAX_COMMAND_LINE_ARGS || argc < MIN_COMMAND_LINE_ARGS)
        return ERR_COMMAND_LINE_ARGS_COUNT;

    int error;
    int nums_in_file;

    if ((error = get_number_of_int_in_file(argv[1], &nums_in_file)) !=
            EXIT_SUCCESS)
        return error;

    int *arr = NULL;

    if ((error = get_mem(&arr, nums_in_file)) != EXIT_SUCCESS)
        return error;

    read_nums_from_file(argv[1], arr, arr + nums_in_file);
    mysort(arr, nums_in_file, sizeof(int), int_cmp);
    put_int_arr_in_file(argv[2], arr, arr + nums_in_file);

    free(arr);

    return EXIT_SUCCESS;
}
