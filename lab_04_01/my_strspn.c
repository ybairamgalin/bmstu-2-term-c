#include <stdio.h>
#include "my_strspn.h"

size_t my_strspn(const char *string_1, const char *string_2)
{
    size_t count = 0;

    for (int i = 0; string_1[i] != END_OF_LINE; i++, count++)
    {
        const char *pStr;

        for (pStr = string_2; *pStr && *pStr != string_1[i]; pStr++);

        if (!*pStr)
            break;
    }

    return count;
}
