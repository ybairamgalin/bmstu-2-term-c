#include <stdio.h>
#include <string.h>
#include "my_strspn.h"

int main(void)
{
    char str1[MAX_STR_SIZE], str2[MAX_STR_SIZE];

    fgets(str1, sizeof(str1), stdin);
    fgets(str2, sizeof(str2), stdin);

    printf("my_strspn:\t%zu\n", my_strspn(str1, str2));
    printf("strspn:\t\t%zu\n", strspn(str1, str2));

    return OK;
}