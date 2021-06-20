//
//  main.c
//  lab01task0501
//
//  Created by Yaroslav Bairamgalin on 27.02.2021.
//

#include <stdio.h>

#define OK 0
#define INCORRECT_TYPE 10
#define INCORRECT_VALUE 5

#define EXPECTED_ARGS 2


// function puts in quo and num the whole part and the rest of
// division of num by denom
void integer_division(int *quo, int *num, const int denom)
{
    // num finally equals rest
    while (*num >= denom)
    {
        (*quo)++;
        *num -= denom;
    }
}

int main(void)
{
    int num, denom;
    int corr_input = scanf("%d%d", &num, &denom);

    if (corr_input != EXPECTED_ARGS)
        return INCORRECT_TYPE;

    if (num <= 0 || denom <= 0)
        return INCORRECT_VALUE;
    
    int quo = 0;
    integer_division(&quo, &num, denom);

    printf("%d %d", quo, num);
    
    return OK;
}
