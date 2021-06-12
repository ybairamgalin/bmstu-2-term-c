#include <stdio.h>
#include <string.h>
#include "functions.h"

void print_str_arr(char (*const words)[MAX_WORD_SIZE], const int num_of_words)
{
    printf("Result: ");

    for (int i = 0; i < num_of_words; i++)
        printf("%s ", words[i]);
}

int my_strcmp(const char *str_1, const char *str_2)
{
    for (; *str_1 == *str_2; str_1++, str_2++)
        if (*str_1 == CHAR_END_OF_STR)
            return WORDS_ARE_EQUAL;

    return *(char *)str_2 - *(char *)str_1;
}

void swap_words(char *str_1, char *str_2)
{
    for (int i = 0; str_1[i] != CHAR_END_OF_STR &&
        str_2[i] != CHAR_END_OF_STR; i++)
    {
        char buf = str_1[i];
        str_1[i] = str_2[i];
        str_2[i] = buf;
    }

    int lng_1 = strlen(str_1);
    int lng_2 = strlen(str_2);

    if (strlen(str_1) > strlen(str_2))
        for (int i = lng_2; i < lng_1; i++)
            str_2[i] = str_1[i];
    else
        for (int i = lng_1; i < lng_2; i++)
            str_1[i] = str_2[i];

    str_1[lng_2] = CHAR_END_OF_STR;
    str_2[lng_1] = CHAR_END_OF_STR;
}

void sort_words(char (*words)[MAX_WORD_SIZE], const int num_of_words)
{
    for (int i = 0; i < num_of_words - 1; i++)
        for (int j = 0; i < num_of_words - j - 1; j++)
            if (my_strcmp(words[j], words[j + 1]) < 0)
                swap_words(words[j], words[j + 1]);
}

void cpy_word(char *dest, const char *src, int lng)
{
    for (int i = 0; i < lng; i++)
        dest[i] = src[i];

    dest[lng] = CHAR_END_OF_STR;
}

void delete_punctuation(char *str)
{
    for (int i = 0; str[i] != CHAR_END_OF_STR; i++)
        if (str[i] == COMA || str[i] == SEMICOLON || str[i] == COLON ||
            str[i] == DASH || str[i] == POINT || str[i] == EXCLAMATION ||
            str[i] == QUESTION || str[i] == CHAR_END_OF_LINE)
            str[i] = CHAR_SPACE;

    strcat(str, STR_SPACE);
}

int word_is_in_words(char (*const words)[MAX_WORD_SIZE],
const int number_of_words, const char *word)
{
    for (int i = 0; i < number_of_words; i++)
        if (my_strcmp(words[i], word) == WORDS_ARE_EQUAL)
            return WORD_IN_WORDS;

    return WORD_NOT_IN;
}

int split(char (*words)[MAX_WORD_SIZE], char *str)
{
    int number_of_words = 0;
    delete_punctuation(str);

    for (int i = 0, j = 0; j < strlen(str); j++)
    {
        if (str[i] == CHAR_SPACE)
        {
            i++;
            continue;;
        }

        if (str[j] == CHAR_SPACE)
        {
            if (j - i > MAX_WORD_SIZE)
                return MAX_WORD_LNG_EXCEEDED;

            char word[MAX_WORD_SIZE];
            cpy_word(word, str + i, j - i);

            if (word_is_in_words(words, number_of_words, word) == WORD_NOT_IN)
                cpy_word(words[number_of_words++], str + i, j - i);

            i = j;
        }
    }

    return number_of_words;
}