#include <stdio.h>
#include <string.h>
#include "my_regex.h"

//[+-]?([[:digit:]]+([.][[:digit:]]*)?([eE][+-]?[[:digit:]]+)?|[.][[:digit:]]+([eE][+-]?[[:digit:]]+)?)

int main(void)
{
    setbuf(stdout, NULL);

    char str[MAX_STR_SIZE];

    if (fgets(str, MAX_STR_SIZE, stdin) == NULL)
        return INPUT_ERROR;

    if (str[strlen(str) - 1] != CHAR_END_OF_LINE)
        return INPUT_ERROR;

    int result = is_exp_num(str);

    if (result == IS_NUM)
        printf("YES");
    else
        printf("NO");

    return OK;
}