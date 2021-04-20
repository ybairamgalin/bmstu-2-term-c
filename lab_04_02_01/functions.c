#include <stdio.h>
#include <string.h>
#include "functions.h"

void print_str_arr(char (*const words)[MAX_WORD_SIZE], const int num_of_words)
{
    for (int i = 0; i < num_of_words; i++)
        printf("%s ", words[i]);

    printf("\n");
}

void cpy_substr(char *dest, const char *start, const char *stop)
{
    long size = stop - start;

    for (int i = 0; i < size; i++)
        dest[i] = start[i];

    dest[size] = CHAR_END_OF_LINE;
}

int split(char *str, char (*words)[MAX_WORD_SIZE])
{
    // insert space in order to track the last word
    int num_of_words = 0;
    str[strlen(str)] = CHAR_SPACE;
    strcat(str, STR_END_OF_LINE);

    for (int i = 0, j = 0; str[j] != CHAR_END_OF_LINE; j++)
        if (str[j] == CHAR_SPACE && j - i != 0)
        {
            cpy_substr(words[num_of_words++], str + i, str + j);
            i = ++j;
            continue;
        }

    return num_of_words;
}