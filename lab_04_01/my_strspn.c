#include <stdio.h>
#include "my_strspn.h"

size_t my_strspn(const char *string_1, const char *string_2)
{
    size_t count = 0;

    for (int i = 0; string_1[i] == string_2[i] &&
            string_1[i] != END_OF_LINE &&
            string_2[i] != END_OF_LINE; i++)
        count++;

    return count;
}
