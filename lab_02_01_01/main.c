#include <stdio.h>

#define OK 0
#define INCORRECT_TYPE 2
#define INCORRECT_VALUE 3
#define NO_ODD_ELEMENTS_IN_ARRAY 4

#define ARRAY_SIZE 10
#define YES 1
#define NO 0


int input(int *array, const int num_of_elem)
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
int solve(int *array, const int arr_lng, int *product)
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

    if (corr_input != 1)
        return INCORRECT_TYPE;

    if (number_of_elements <= 0 || number_of_elements > ARRAY_SIZE)
        return INCORRECT_VALUE;

    int arr[ARRAY_SIZE];

    if (input(arr, number_of_elements) == NO)
        return INCORRECT_TYPE;
    
    // prod - final product
    int product = 1;
    
    if (solve(arr, number_of_elements, &product) == 0)
        return NO_ODD_ELEMENTS_IN_ARRAY;

    printf("%d", product);

    return OK;
}
