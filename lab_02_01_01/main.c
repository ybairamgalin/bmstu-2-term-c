#include <stdio.h>

#define EXEC_OK 0
#define INCORRECT_INPUT 10

#define ARRAY_SIZE 10
#define YES 1
#define NO 0

// function finds the product of all negative elements and puts in into *product
// if no such elements exist returns 0
// else returns 1
int solve(int *array, int arr_lng, int *product)
{
    int contains_odd = NO;
    for (int i = 0; i < arr_lng; i++)
    {
        // != to avoid problems with negative elements
        if (*(array + i) % 2 != 0)
        {
            *product *= *(array + i);
            contains_odd = YES;
        }
    }
    return contains_odd;
}

// function printa int number
void print_output(int number)
{
    printf("%d", number);
}

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
    }
    
    if (solve(arr, number_of_elements, &prod) == 0)
        return INCORRECT_INPUT;
        
    print_output(prod);
    return EXEC_OK;
}
