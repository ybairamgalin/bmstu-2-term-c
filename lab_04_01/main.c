#include <stdio.h>
#include <string.h>
#include "my_strspn.h"

int main(void)
{
    printf("my_strspn:\t%zu\n", my_strspn("this is a test", "ihst"));
    printf("strspn:\t\t%zu\n", strspn("this is a test", "ihst"));

    printf("my_strspn:\t%zu\n", my_strspn("this is test", "this is test"));
    printf("strspn:\t\t%zu\n", strspn("this is test", "this is test"));

    printf("my_strchr:\t%p\n", my_strchr("str1", '1'));
    printf("strchr:\t\t%p\n", strchr("str1", '1'));

    printf("my_strchr:\t%p\n", my_strchr("str2", '5'));
    printf("strchr:\t\t%p\n", strchr("str2", '5'));

    return OK;
}