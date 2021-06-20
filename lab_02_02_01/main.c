#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define OK 0
#define INCORRECT_TYPE 2
#define INCORRECT_VALUE 3
#define NO_PRIME_ELEMENTS_IN_ARRAY 4

#define ARRAY_SIZE 10
#define YES 1
#define NO 0

#define EXPECTED_ARGS 1

#define CORRECT 1
#define NOT_CORRECT 0


int input(int *array, const int num_of_elem)
{
    int input_is_correct = CORRECT;

    for (int i = 0; i < num_of_elem; i++)
    {
        if (scanf("%d", array + i) != EXPECTED_ARGS)
        {
            input_is_correct = NOT_CORRECT;
            break;
        }
    }

    return input_is_correct;
}

int is_prime(const int x)
{
    int x_is_prime = YES;
    
    // if the condition is completed for cycle won't be executed
    if (x <= 1)
        x_is_prime = NO;
    
    for (int i = 2; i <= (int)sqrt(x); i++)
    {
        if (x % i == 0)
        {
            x_is_prime = NO;
            break;
        }
    }

    return x_is_prime;
}

void print_array(int *array, const int number_of_elements)
{
    for (int i = 0; i < number_of_elements; i++)
        printf("%d ", *(array + i));
}

int copy_primes(int *from_array, int from_array_size, int *to_array)
{
    int to_array_size = 0;

    for (int i = 0; i < from_array_size; i++)
    {
        if (is_prime(*(from_array + i)) == YES)
        {
            *(to_array + to_array_size) = *(from_array + i);
            to_array_size++;
        }
    }

    return to_array_size;
}

int main(void)
{
    int number_of_elements;

    if (scanf("%d", &number_of_elements) != EXPECTED_ARGS)
        return INCORRECT_TYPE;

    if (number_of_elements <= 0 || number_of_elements > ARRAY_SIZE)
        return INCORRECT_VALUE;
    
    int arr[ARRAY_SIZE];

    if (input(arr, number_of_elements) == NO)
        return INCORRECT_TYPE;
    
    int result_array[ARRAY_SIZE];
    int count_new_array = copy_primes(arr, number_of_elements, result_array);
    
    // due to the task if no elements are found, return error
    if (count_new_array == 0)
        return NO_PRIME_ELEMENTS_IN_ARRAY;
    
    print_array(result_array, count_new_array);
    
    return OK;
}
