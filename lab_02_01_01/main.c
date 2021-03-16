#include <stdio.h>

#define OK 0
#define INCORRECT_INPUT 10

#define ARRAY_SIZE 10
#define YES 1
#define NO 0


int input(int *array, int num_of_elem)
{
    int input_is_correct = YES;
    for (int i = 0; i < num_of_elem; i++)
    {
        int read_elements = scanf("%d", array + i);
        if (read_elements != 1)
        {
            input_is_correct = NO;
            break;
        }
    }
    return input_is_correct;
}

// function finds the product of all negative elements and them in into *product
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

int main(void)
{
    int number_of_elements;
    int corr_input = scanf("%d", &number_of_elements);
    if (corr_input != 1 || number_of_elements <= 0 || number_of_elements > ARRAY_SIZE)
        return INCORRECT_INPUT;

    int arr[ARRAY_SIZE];
    if (input(arr, number_of_elements) == NO)
        return INCORRECT_INPUT;
    
    // prod - final product
    int prod = 1;
    
    if (solve(arr, number_of_elements, &prod) == 0)
        return INCORRECT_INPUT;
        
    printf("%d", prod);
    return OK;
}
