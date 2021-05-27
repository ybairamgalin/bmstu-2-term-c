#include <stdio.h>
#include "functions.h"

int main(void)
{
    int first, second;
    int error = process(stdin, &first, &second);

    printf("Error code: %d\n", error);

    if (error == OK)
        printf("%d %d", first, second);

    return error;
}
