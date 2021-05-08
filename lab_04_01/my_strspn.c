#include <stdio.h>
#include "my_strspn.h"

size_t my_strspn(const char *string_1, const char *string_2)
{
    size_t count = 0;

    for (int i = 0; string_1[i] != END_OF_LINE; i++, count++)
    {
        const char *p_str;

        for (p_str = string_2; *p_str && *p_str != string_1[i]; p_str++);

        if (!*p_str)
            break;
    }

    return count;
}
