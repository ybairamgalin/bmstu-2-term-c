#include <stdio.h>

#define OK 0
#define INCORRECT_TYPE 2
#define INCORRECT_VALUE 3

#define VALUE_CANNOT_BE_DEFINED 20

#define YES 1
#define NO 0

#define ARRAY_SIZE 10

#define EXPECTED_ARGS 1


// function receives pointer to an array and number of elements in this array
// function returns 1, if input is correct
// 0, if input in not correct
int input(int *first, int *last)
{
    long num_of_elem = last - first;
    int input_is_correct = YES;

    for (int i = 0; i < num_of_elem; i++)
    {
        if (scanf("%d", first + i) != EXPECTED_ARGS)
        {
            input_is_correct = NO;
            break;
        }
    }

    return input_is_correct;
}

// function receives pointer to the first and last+1 element of an array and one more pointer to an array
// it is expected that in b_array exist elements to (a_last - a_first)
// function returns sum of product of respective elements of 2 given arrays
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

int get_subarray_of_pos(int *array, int number_of_elements, int *subarray)
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
    int number_of_elements;
    int input_array[ARRAY_SIZE];
    int neg_array[ARRAY_SIZE];
    int pos_array[ARRAY_SIZE];

    if (scanf("%d", &number_of_elements) != EXPECTED_ARGS)
        return INCORRECT_TYPE;

    if (number_of_elements <= 0 || number_of_elements > ARRAY_SIZE)
        return INCORRECT_VALUE;

    if (input(input_array, input_array + number_of_elements) == NO)
        return INCORRECT_TYPE;

    int count_neg_elements = get_subarray_of_neg(input_array, number_of_elements, neg_array);
    int count_pos_elements = get_subarray_of_pos(input_array, number_of_elements, pos_array);

    int iterate_to = (count_neg_elements > count_pos_elements) ? count_pos_elements : count_neg_elements;

    if (iterate_to == 0)
        return VALUE_CANNOT_BE_DEFINED;

    int sum = find_expected_sum(neg_array, neg_array + iterate_to, pos_array);

    printf("%d", sum);

    return OK;
}
