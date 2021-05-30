#include <stdio.h>
#include "functions.h"

int main(void)
{
    int first, second;
    int error = process(stdin, &first, &second);

    if (error == OK)
        printf("%d %d\n", first, second);

    printf("Error code: %d\n", error);

    return OK;
}