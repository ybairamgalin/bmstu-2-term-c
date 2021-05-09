#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

int main(void)
{
    setbuf(stdout, NULL);

    char str[MAX_STR_SIZE];

    if (fgets(str, MAX_STR_SIZE, stdin) == NULL)
        return INPUT_ERROR;

    if (str[strlen(str) - 1] != CHAR_END_OF_LINE)
        return INPUT_ERROR;

    char result_arr[MAX_WORDS][MAX_WORD_SIZE];
    int arr_size = split_and_solve(str, result_arr);

    for (int i = 0; i < arr_size; i++)
        del_first_appear_letter(result_arr[i]);

    print_result(result_arr, arr_size);

    return OK;
}
