#include <stdio.h>

#define MAX_ARRAY_SIZE 100
#define INCORRECT_TYPE 5



int main(void)
{
    int number_of_elements;
    int input_check = scanf("%d", &number_of_elements);

    if (input_check != 1)
        return INCORRECT_TYPE;


}