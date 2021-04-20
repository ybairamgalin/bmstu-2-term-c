#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include "functions.h"

int main(void)
{
    char str[MAX_STR_SIZE];
    char words[MAX_WORDS][MAX_WORD_SIZE];

    if (fgets(str, sizeof(str), stdin) == NULL)
        return INPUT_ERROR;

    int number_of_words = split(words, str);
    sort_words(words, number_of_words);
    print_str_arr(words, number_of_words);

    return OK;
}
