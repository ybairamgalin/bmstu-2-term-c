#include <stdio.h>

#define EXEC_OK 0
#define INCORRECT_INPUT 10

#define ARRAY_SIZE 10

int main()
{
    int arr[ARRAY_SIZE];
    // prod - final product
    int prod = 1;
    int i = 0;
    while (scanf("%d", arr + i))
    {
        if (i % 2 == 1)
            prod *= arr[i];
        i++;
    }
    
    printf("%d", prod);

    return EXEC_OK;
}
