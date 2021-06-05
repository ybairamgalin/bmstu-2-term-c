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
            text_from_file.N = -1;
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