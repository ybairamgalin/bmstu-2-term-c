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


int main(void)
{
    int number_of_elements;
    int corr_input = scanf("%d", &number_of_elements);
    if (corr_input != 1 || number_of_elements <= 0 || number_of_elements > ARRAY_SIZE)
        return INCORRECT_INPUT;

    int input_array[ARRAY_SIZE];
    if (input(input_array, number_of_elements) == NO)
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

    int sum = 0;

    for (int i = 0; i < iterate_to; i++)
        sum += *(pos_array + i) * *(neg_array + i);

    printf("%d", sum);

    return OK;
}
