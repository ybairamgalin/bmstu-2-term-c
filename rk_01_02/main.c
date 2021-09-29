#include <stdio.h>

#define OK 0

#define INCORRECT_TYPE 5
#define VALUE_CANNOT_BE_DEFINED 6

#define CORRECT 1
#define NOT_CORRECT 0

int input(int *number)
{

    int check = scanf("%d", number);

    if (check != 1)
        return NOT_CORRECT;

    // int this 2 cases number cannot be assign to an int var
    if (*number < 0)
        return NOT_CORRECT;

    if (*number % 10 == 0)
        return NOT_CORRECT;

    return CORRECT;
}

int reverse(int number)
{
    int reversed = 0;

    while (number != 0)
    {
        reversed *= 10;
        reversed += number % 10;
        number /= 10;
    }

    return reversed;
}

int main(void)
{
    int number;

    if (input(&number) == NOT_CORRECT)
        return INCORRECT_TYPE;

    int reversed_number = reverse(number);

    printf("%d", reversed_number);
}
