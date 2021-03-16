#include <stdio.h>

#define OK 0
#define INCORRECT_INPUT 10
#define VALUE_CANNOT_BE_DEFINED 20

#define YES 1
#define NO 0

#define ARRAY_SIZE 10


// function receives pointer to an array and number of elements in this array
// function returns 1, if input is correct
// 0, if input in not correct
int input(int *first, int *last)
{
    long num_of_elem = last - first;
    int input_is_correct = YES;
    for (int i = 0; i < num_of_elem; i++)
    {
        int read_elements = scanf("%d", first + i);
        if (read_elements != 1)
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
    {
        sum += *(a_first + i) * *(b_first + i);
    }

    return sum;
}


int main(void)
{
    int number_of_elements;
    int corr_input = scanf("%d", &number_of_elements);
    if (corr_input != 1 || number_of_elements <= 0 || number_of_elements > ARRAY_SIZE)
        return INCORRECT_INPUT;

    int input_array[ARRAY_SIZE];
    if (input(input_array, input_array + number_of_elements) == NO)
        return INCORRECT_INPUT;

    int neg_array[ARRAY_SIZE];
    int count_neg_elements = 0;

    for (int i = 0; i < number_of_elements; i++)
    {
        if (*(input_array + i) < 0)
        {
            *(neg_array + count_neg_elements) = *(input_array + i);
            count_neg_elements++;
        }
    }

    int pos_array[ARRAY_SIZE];
    int count_pos_elements = 0;

    for (int i = number_of_elements - 1; i >= 0; i--)
    {
        if (*(input_array + i) > 0)
        {
            *(pos_array + count_pos_elements) = *(input_array + i);
            count_pos_elements++;
        }
    }

    int iterate_to = (count_neg_elements > count_pos_elements) ? count_pos_elements : count_neg_elements;
    if (iterate_to == 0)
        return VALUE_CANNOT_BE_DEFINED;

    int sum = find_expected_sum(neg_array, neg_array + iterate_to, pos_array);
    printf("%d", sum);

    return OK;
}
