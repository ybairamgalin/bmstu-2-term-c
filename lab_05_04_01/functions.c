#include <stdio.h>
#include "functions.h"

int file_size(FILE *f, size_t *size)
{
    long sz;

    if (fseek(f, 0L, SEEK_END))
        return 1;

    sz = ftell(f);

    if (sz < 0)
        return 1;

    *size = sz;

    return fseek(f, 0L, SEEK_SET);
}