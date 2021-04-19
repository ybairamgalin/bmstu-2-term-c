#include <stdio.h>
#include "my_strspn.h"

int main(void)
{
    char str1[MAX_STR_SIZE], str2[MAX_STR_SIZE];

    fgets(str1, sizeof(str1), stdin);
    fgets(str2, sizeof(str2), stdin);

    printf("%zu", my_strspn(str1, str2));

    return OK;
}