#include <stdio.h>

#define EXEC_OK 0
#define INCORRECT_INPUT 10

#define ARRAY_SIZE 10
#define YES 1
#define NO 0

int main()
{
    int arr[ARRAY_SIZE];
    
    int number_of_elements;
    int corr_input = scanf("%d", &number_of_elements);
    if (corr_input != 1 || number_of_elements < 0 || number_of_elements > ARRAY_SIZE)
        return INCORRECT_INPUT;
    int CONTAINS_ODD = NO;
    
    // prod - final product
    int prod = 1;
    for (int i = 0; i < number_of_elements; i++)
    {
        corr_input = scanf("%d", arr + i);
        if (corr_input != 1)
            return INCORRECT_INPUT;
        // != to avoid problems with negative elements
        if (arr[i] % 2 != 0)
        {
            prod *= arr[i];
            CONTAINS_ODD = YES;
        }
    }
    
    if (CONTAINS_ODD == NO)
        return INCORRECT_INPUT;
 
    printf("%d", prod);

    return EXEC_OK;
}
