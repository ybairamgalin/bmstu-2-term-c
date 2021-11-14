#include <stdlib.h>
#include "my_string.h"

int main(void)
{
    char *str1 = "First";
    char *str2 = "Second";

    my_string_t *string1 = my_string_create(str1);
    my_string_t *string2 = my_string_create(str2);

    string1 = my_string_concat(string1, string2);

    my_string_print(string1);

    my_string_free(string1);
    my_string_free(string2);

    return EXIT_SUCCESS;
}
