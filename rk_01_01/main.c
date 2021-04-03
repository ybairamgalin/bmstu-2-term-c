#include <stdio.h>

#define MAX_ARRAY_SIZE 20

#define OK 0
#define INCORRECT_TYPE 5
#define INCORRECT_VALUE 6

#define YES 1
#define NO 0

void fill_array_with_zeros(int *array)
{
    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
        *(array + i) = 0;
}

int input(int *array, int number_of_lines)
{
    int row, column, value;
    int input_is_correct = YES;

    for (int i = 0; i < number_of_lines; i++)
    {
        int corr_input = scanf("%d%d%d", &row, &column, &value);

        if (corr_input != 3)
        {
            input_is_correct = NO;
            break;
        }

        if (row < 0 || row > 1)
        {
            input_is_correct = NO;
            break;
        }

        if (column < 1 || column > (number_of_lines + 1))
        {
            input_is_correct = NO;
            break;
        }

        *(array + (column - 1)) = value;
    }

    return input_is_correct;
}


int main(void)
{
    int rows;
    int input_check = scanf("%d", &rows);

    if (input_check != 1)
        return INCORRECT_TYPE;

    // should not be a matrix
    if (rows < 0 || rows > 1)
        return INCORRECT_VALUE;

    int cols;
    input_check = scanf("%d", &cols);

    if (input_check != 1)
        return INCORRECT_TYPE;

    // should not be a matrix
    if (cols < 0 || cols > MAX_ARRAY_SIZE)
        return INCORRECT_VALUE;

    int number_of_non_zero_elements;
    input_check = scanf("%d", &number_of_non_zero_elements);

    if (input_check != 1)
        return INCORRECT_TYPE;

    if (number_of_non_zero_elements < 0 || number_of_non_zero_elements > MAX_ARRAY_SIZE)
        return INCORRECT_VALUE;

    int array[MAX_ARRAY_SIZE];
    fill_array_with_zeros(array);
    input_check = input(array, number_of_non_zero_elements);

    if (input_check == NO)
        return INCORRECT_TYPE;

    for (int i = 0 ; i < cols; i++)
        printf("%d ", array[i]);

    int elements_found[MAX_ARRAY_SIZE];
    int number_of_unique_elements = 0;

    for (int i = 0; i < cols; i++)
    {
        int element_exists = NO;

        for (int j = 0; j < number_of_unique_elements; j++)
        {
            if (array[i] == elements_found[j])
            {
                element_exists = YES;
                break;
            }
        }

        if (element_exists == NO)
        {
            elements_found[number_of_unique_elements] = array[i];
            number_of_unique_elements++;
        }

    }

    printf("%d", number_of_unique_elements);


    return OK;

}