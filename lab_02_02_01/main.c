#include <stdio.h>
#include <stdlib.h>

#define EXEC_OK 0
#define INCORRECT_INPUT 10

#define ARRAY_SIZE 10
#define YES 1
#define NO 0


// function receives pointer to an array and number of elements in this array
// function returns 1, if input is correct
// 0, if input in not correct
int input(long long int *array, int num_of_elem)
{
    int input_is_correct = YES;
    for (int i = 0; i < num_of_elem; i++)
    {
        int read_elements = scanf("%lld", array + i);
        if (read_elements != 1)
        {
            input_is_correct = NO;
            break;
        }
    }
    return input_is_correct;
}

// function receives int x and returns 1 if:
// 1. x <= 1, 2. x is prime;
// otherwise function returns 0
int is_prime(long long int x)
{
    int x_is_prime = YES;
    
    // if the condition is completed for cycle won't be executed
    if (x <= 1)
        x_is_prime = NO;
    
    for (int i = 2; i < x / 2 + 1; i++)
    {
        if (x % i == 0)
        {
            x_is_prime = NO;
            break;
        }
    }
    return x_is_prime;
}

///------------------------------------------------------------

int main()
{
    int number_of_elements;
    int corr_input = scanf("%d", &number_of_elements);
    if (corr_input != 1 || number_of_elements <= 0 || number_of_elements > ARRAY_SIZE)
        return INCORRECT_INPUT;
    
    long long int arr[ARRAY_SIZE];
    if (input(arr, number_of_elements) == NO)
        return INCORRECT_INPUT;
    
    long long int result_array[ARRAY_SIZE];
    int count_new_array = 0;
    for (int i = 0; i < number_of_elements; i++)
    {
        if (is_prime(arr[i]) == YES)
        {
            result_array[count_new_array] = arr[i];
            count_new_array++;
        }
    }
    
    // due to the task if no elements are found, return error
    if (count_new_array == 0)
        return INCORRECT_INPUT;
    
    for (int i = 0; i < count_new_array; i++)
    {
        printf("%lld ", result_array[i]);
    }
    
    return EXEC_OK;
}
