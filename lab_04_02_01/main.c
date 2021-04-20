#include <stdio.h>
#include <string.h>
#include "functions.h"

int main(void)
{
    char str[MAX_STR_SIZE];
    char words[MAX_WORDS][MAX_WORD_SIZE];

    fgets(str, sizeof(str), stdin);

    int num_of_words = split(str, words);

    printf("num of words: %d\n", num_of_words);
    print_str_arr(words, num_of_words);

    return OK;
}