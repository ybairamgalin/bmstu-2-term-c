#include <stdio.h>
#include <strings.h>
#include "functions.h"

int main(void)
{
    FILE *file = fopen(IN_FILE_NAME, "r");

    if (file == NULL)
        return FILE_DOES_NOT_EXIST;

    struct text text = file_to_text(file);

    if (text.N == -1)
        return WORD_LNG_ERR;

    reverse_text(&text);
    put_in_file(text);
}