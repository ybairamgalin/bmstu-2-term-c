#include <stdio.h>

#define OK 0
#define INPUT_ERROR 1

#define MAX_STR_SIZE 256

#define END_OF_LINE '\0'

size_t my_strspn(const char *string_1, const char *string_2)
{
    size_t count = 0;

    for (int i = 0; string_1[i] == string_2[i] &&
            string_1[i] != END_OF_LINE && string_2[i] != END_OF_LINE; i++)
        count++;

    return count;
}

int main(void)
{
    char str1[MAX_STR_SIZE], str2[MAX_STR_SIZE];

    fgets(str1, sizeof(str1), stdin);
    fgets(str2, sizeof(str2), stdin);

    printf("%zu", my_strspn(str1, str2));
}