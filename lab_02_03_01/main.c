#include <stdio.h>

#define OK 0
#define INCORRECT_TYPE 2
#define INCORRECT_VALUE 3

#define ARRAY_SIZE 21
#define BORDER_VALUE -1000000

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

// the functions returns fib_i,, where i is the number of times
// the function was previously called
int get_next_fibonacci()
{
    static int fib_first = 0;
    static int fib_second = 1;
    static int count = 0;

    if (count == 0)
    {
        count++;
        return fib_first;
    }

    if (count == 1)
    {
        count++;
        return fib_second;
    }

    int result = fib_first + fib_second;
    fib_first = fib_second;
    fib_second = result;

    return result;
}

void print_array(int *array, const int number_of_elements)
{
    for (int i = 0; i < number_of_elements; i++)
        printf("%d ", *(array + i));
}

void insert_fibonacci(int *array, int *number_of_elements)
{
    int count = 0;

    while (*(array + count) != BORDER_VALUE)
    {
        if (*(array + count) % 3 == 0)
        {
            // move elements 1 forward
            for (int i = ARRAY_SIZE - 1; i > count + 1; i--)
                *(array + i) = *(array + (i - 1));

            *(array + count + 1) = get_next_fibonacci();
            (*number_of_elements)++;
            count += 2;
        }
        else
            count++;
    }
}

int main(void)
{
    int number_of_elements;

    if (scanf("%d", &number_of_elements) != EXPECTED_ARGS)
        return INCORRECT_TYPE;

    if (number_of_elements <= 0 || number_of_elements > ARRAY_SIZE)
        return INCORRECT_VALUE;

    int arr[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++)
        arr[i] = BORDER_VALUE;

    if (input(arr, number_of_elements) == NO)
        return INCORRECT_TYPE;

    insert_fibonacci(arr, &number_of_elements);

    print_array(arr, number_of_elements);

    return OK;
}
