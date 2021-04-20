#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include "functions.h"

int main(void)
{
    char str[MAX_STR_SIZE];
    char words[MAX_WORDS][MAX_WORD_SIZE];

    if (fgets(str, MAX_STR_SIZE, stdin) == NULL)
        return INPUT_ERROR;

    if (str[strlen(str) - 1] != CHAR_END_OF_LINE)
        return INPUT_ERROR;

    int number_of_words = split(words, str);

    if (number_of_words <= 0)
        return MAX_WORD_LNG_EXCEEDED;

    sort_words(words, number_of_words);
    print_str_arr(words, number_of_words);

    return OK;
}
