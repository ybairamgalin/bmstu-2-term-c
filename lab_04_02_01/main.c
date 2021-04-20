#include <stdio.h>
#include <string.h>
#include "functions.h"

int main(void)
{
    char str[MAX_STR_SIZE];
    char words[MAX_WORDS][MAX_WORD_SIZE];

    fgets(str, sizeof(str), stdin);

    int num_of_words = split(str, words);

    for (int i = 0; i < num_of_words; i++)
        printf("%s\n", words[i]);

    return OK;
}