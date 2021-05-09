#include <stdio.h>
#include <string.h>
#include "functions.h"

void print_result(char (*dest_array)[MAX_WORD_SIZE], const int size)
{
    printf("Result:");

    for (int i = size - 1; i >= 0; i--)
        if (strcmp(dest_array[i], EMPTY_STRING) != WORDS_ARE_EQUAL)
            printf(" %s", dest_array[i]);

    printf("\n");
}

int modify_word(char *word, const int src, const int dest)
{
    int was_modified = NO;

    if (word[src] == word[dest])
    {
        was_modified = YES;

        for (int i = dest; word[i + 1] != CHAR_END_OF_STR; i++)
            word[i] = word[i + 1];
    }

    return was_modified;
}

void del_first_appear_letter(char *word)
{
    for (int i = 0; word[i] != CHAR_END_OF_STR; i++)
        for (int j = i + 1; word[j] != CHAR_END_OF_STR; j++)
            if (modify_word(word, i, j) == YES)
                j--;
}

void set_as_last_empty(char (*array)[MAX_WORD_SIZE], const int size)
{
    for (int i = 0; i < size; i++)
        if (strcmp(array[i], array[size - 1]) == WORDS_ARE_EQUAL)
            strncpy(array[i], EMPTY_STRING, MAX_WORD_SIZE);
}


int split_and_solve(char *string, char (*dest_array)[MAX_WORD_SIZE])
{
    char *word = strtok(string, SEPARATORS);
    int size = 0;

    while (word != NULL)
    {
        strncpy(dest_array[size], word, sizeof(dest_array[size]) - 1);
        word = strtok(NULL, SEPARATORS);
        size++;
    }

    return size;
}
