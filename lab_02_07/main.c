// Copy of task4 from ../lab_02_04_01/main.c

#include <stdio.h>

#define OK 0
#define INCORRECT_INPUT 10
#define REACHED_MAX_ARRAY_SIZE 100

#define ARRAY_SIZE 1000

// function receives pointer to an array and scans the user input
// returns number of elements that were scanned
int input(int *array)
{
    int number_of_elements = 0;

    while (number_of_elements != (ARRAY_SIZE) && scanf("%d", array + number_of_elements) == 1)
        number_of_elements++;

    int check_element;
    int added_new = scanf("%d", &check_element);
    number_of_elements = number_of_elements + added_new;

    return number_of_elements;
}

// function receives pointer to an array and sorts it
// sort method - bubble sort
void sort(int *array, int number_of_elements)
{
    for (int i = 0; i < number_of_elements; i++)
    {
        for (int j = 1; j < number_of_elements - i; j++)
        {
            if (*(array + j - 1) > *(array + j))
            {
                int buf = *(array + j - 1);
                *(array + j - 1) = *(array + j);
                *(array + j) = buf;
            }
        }
    }
}

int main(void)
{
    int arr[ARRAY_SIZE];
    int number_of_input_elements = input(arr);
    int number_of_elements = (number_of_input_elements <= ARRAY_SIZE) ? number_of_input_elements : number_of_input_elements - 1;

    if (number_of_elements == 0)
        return INCORRECT_INPUT;

    sort(arr, number_of_elements);

    for (int i = 0; i < number_of_elements; i++)
        printf("%d ", arr[i]);

    if (number_of_input_elements > ARRAY_SIZE)
        return REACHED_MAX_ARRAY_SIZE;

    return OK;
}
