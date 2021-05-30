#include <stdio.h>
#include "functions.h"

int main(void)
{
    int first, second;
    int error;

    if ((error = process(stdin, &first, &second)) != OK)
        return error;

    return OK;
}