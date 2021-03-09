#include <stdio.h>

#define EXEC_OK 0
#define INCORRECT_INPUT 10

#define ARRAY_SIZE 10

int main()
{
    int arr[ARRAY_SIZE];
    
    int number_of_elements;
    int corr_input = scanf("%d", &number_of_elements);
    if (corr_input != 1 || number_of_elements < 0 || number_of_elements > ARRAY_SIZE)
        return INCORRECT_INPUT;
    
    // prod - final product
    int prod = 1;
    for (int i = 0; i < number_of_elements; i++)
    {
        corr_input = scanf("%d", arr + i);
        if (corr_input != 1)
            return INCORRECT_INPUT;
        if (i % 2 == 1)
            prod *= arr[i];
    }
 
    printf("%d", prod);

    return EXEC_OK;
}
