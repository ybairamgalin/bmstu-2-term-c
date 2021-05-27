#include <stdio.h>
#include "functions.h"

int main(void)
{
    int error = process(stdin);

    // printf("Error code: %d", error);

    return error;
}
