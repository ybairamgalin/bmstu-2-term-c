#include <stdio.h>

#define EXEC_OK 0
#define INCORRECT_INPUT 10

#define ARRAY_SIZE 10
#define YES 1
#define NO 0

// function receives pointer to an array and number of elements in this array
// function returns 1, if input is correct
// 0, if input in not correct
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


// the functions returns fib_i,, where i is the number of times, the function was previously called
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

int main()
{
    int number_of_elements;
    int corr_input = scanf("%d", &number_of_elements);
    if (corr_input != 1 || number_of_elements <= 0 || number_of_elements > ARRAY_SIZE)
        return INCORRECT_INPUT;

    int arr[ARRAY_SIZE];
    if (input(arr, number_of_elements) == NO)
        return INCORRECT_INPUT;

    // iterate to numberOfElements - 1, as the next element has to be changed
    // next - the element to be placed in the next position
    int next = arr[0];
    for (int i = 0; i < number_of_elements; i++)
    {
        int prev = next;
        if (arr[i] %  3 == 0 && i != number_of_elements - 1)
            next = get_next_fibonacci();
        else
            next = arr[i+1];
        arr[i] = prev;
    }

    for (int i = 0; i < number_of_elements; i++)
    {
        printf("%d ", arr[i]);
    }

    return EXEC_OK;
}
