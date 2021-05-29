#include "functions.h"

int main(void)
{
    int first = 10;
    int second = 10;
    int error = process(stdin, &first, &second);

    printf("Error code: %d\n", error);

    if (error == OK)
        printf("%d %d", first, second);
    return error;
}