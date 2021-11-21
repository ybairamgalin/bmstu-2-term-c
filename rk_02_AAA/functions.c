#include <stdio.h>
#include <string.h>
#include "functions.h"

struct text file_to_text(FILE *file)
{
    struct text text_from_file;

    char str_from_file[MAX_STR_LNG];
    fgets(str_from_file, MAX_STR_LNG + 1, file);

    char *word = strtok(str_from_file, " \n\t");

    text_from_file.N = 0;

    while (word != NULL)
    {
        if (strlen(word) > MAX_WORD_LNG)
        {
            text_from_file.N = WORD_LNG_ERR;
            return text_from_file;
        }

        strcpy(text_from_file.words[text_from_file.N], word);
        text_from_file.N += 1;

        word = strtok(NULL, " \n\t");
    }

    return text_from_file;
}

void print_text(struct text text)
{
    for (int i = 0; i < text.N; i++)
        printf("%s\n", text.words[i]);
}

void reverse_word(char *dest, const char *src)
{
    size_t sz = strlen(src);

    for (size_t i = 0; i < sz; i++)
        dest[i] = src[sz - i - 1];

    dest[sz] = '\0';
}

void reverse_words_in_text(struct text *text)
{
    for (int i = 0, j = text->N - 1; i < j; i++, j--)
    {
        char buf[MAX_WORD_LNG + 1];

        strcpy(buf, text->words[i]);
        strcpy(text->words[i], text->words[j]);
        strcpy(text->words[j], buf);
    }
}

void reverse_text(struct  text *text)
{
    for (int i = 0; i < text->N; i++)
    {
        char new_word[MAX_WORD_LNG + 1];
        reverse_word(new_word, text->words[i]);

        strcpy(text->words[i], new_word);
    }

    reverse_words_in_text(text);
}

void put_in_file(struct text text)
{
    FILE *file;
    file = fopen(OUT_FILE_NAME, "w");

    for (int i = 0; i < text.N; i++)
        fprintf(file, "%s ", text.words[i]);

    fprintf(file, "\n");

    fclose(file);

}