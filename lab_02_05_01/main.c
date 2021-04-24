#include <stdio.h>

#define OK 0
#define INCORRECT_TYPE 2
#define INCORRECT_VALUE 3

#define VALUE_CANNOT_BE_DEFINED 20

#define CORRECT 1
#define NOT_CORRECT 0

#define ARRAY_SIZE 10

#define EXPECTED_ARGS 1


int input(int *first, int *last)
{
    long num_of_elem = last - first;
    int input_is_correct = CORRECT;

    for (int i = 0; i < num_of_elem; i++)
    {
        if (scanf("%d", first + i) != EXPECTED_ARGS)
        {
            input_is_correct = NOT_CORRECT;
            break;
        }
    }

    return input_is_correct;
}

int find_expected_sum(int *a_first, int *a_last, int *b_first)
{
    long size = a_last - a_first;
    int sum = 0;

    for (int i = 0; i < size; i++)
        sum += *(a_first + i) * *(b_first + i);

    return sum;
}

int get_subarray_of_neg(int *array, const int number_of_elements,
int *subarray)
{
    int count = 0;

    for (int i = 0; i < number_of_elements; i++)
    {
        if (*(array + i) < 0)
        {
            *(subarray + count) = *(array + i);
            count++;
        }
    }

    return count;
}

int get_subarray_of_pos(int *array, const int number_of_elements,
int *subarray)
{
    int count = 0;

    for (int i = number_of_elements - 1; i >= 0; i--)
    {
        if (*(array + i) > 0)
        {
            *(subarray + count) = *(array + i);
            count++;
        }
    }

    return count;
}

int main(void)
{
    int size;
    int input_array[ARRAY_SIZE], neg_arr[ARRAY_SIZE], pos_arr[ARRAY_SIZE];

    if (scanf("%d", &size) != EXPECTED_ARGS)
        return INCORRECT_TYPE;

    if (size <= 0 || size > ARRAY_SIZE)
        return INCORRECT_VALUE;

    if (input(input_array, input_array + size) == NO)
        return INCORRECT_TYPE;

    int count_neg_elements = get_subarray_of_neg(input_array, size, neg_arr);
    int count_pos_elements = get_subarray_of_pos(input_array, size, pos_arr);

    int iter_to = (count_neg_elements > count_pos_elements) ?
        count_pos_elements : count_neg_elements;

    if (iter_to == 0)
        return VALUE_CANNOT_BE_DEFINED;

    int sum = find_expected_sum(neg_arr, neg_arr + iter_to, pos_arr);

    printf("%d", sum);

    return OK;
}
