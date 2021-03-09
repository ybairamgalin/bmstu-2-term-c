#include <stdio.h>

#define EXEC_OK 0
#define INCORRECT_INPUT 10

#define ARRAY_SIZE 10

int main()
{
    int arr[ARRAY_SIZE];
    // prod - final product
    int prod = 1;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        int corr_input = scanf("%d", arr + i);
        if (corr_input != 1)
            return INCORRECT_INPUT;
        
        if (i % 2 == 1)
            prod *= arr[i];
    }
    
    printf("%d", prod);

    return EXEC_OK;
}
