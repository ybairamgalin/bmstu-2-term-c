#include <stdio.h>

#define EXEC_OK 0
#define INCORRECT_INPUT 10

#define ARRAY_SIZE 10
#define CONTAINS 1
#define DOES_NOT_CONTAIN 0

int main()
{
    int arr[ARRAY_SIZE];
    
    int number_of_elements;
    int corr_input = scanf("%d", &number_of_elements);
    if (corr_input != 1 || number_of_elements < 0 || number_of_elements > ARRAY_SIZE)
        return INCORRECT_INPUT;
    
    // prod - final product
    int prod = 1;
    // 0 - false; 1 - true
    int array_contains_even = DOES_NOT_CONTAIN;
    for (int i = 0; i < number_of_elements; i++)
    {
        corr_input = scanf("%d", arr + i);
        if (corr_input != 1)
            return INCORRECT_INPUT;
        // != to avoid problems with negative elements
        if (arr[i] % 2 != 0)
            array_contains_even = CONTAINS;
            prod *= arr[i];
    }
    
    if (array_contains_even == DOES_NOT_CONTAIN)
        return INCORRECT_INPUT;
 
    printf("%d", prod);

    return EXEC_OK;
}
