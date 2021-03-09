//
//  main.c
//  lab01task0501
//
//  Created by Yaroslav Bairamgalin on 27.02.2021.
//

#include <stdio.h>

#define INCORRECT_INPUT 5
#define EXEC_OK 0

// prints two double vars
void print_output(int first, int second)
{
    printf("%d %d", first, second);
}

int main()
{
    int num, denom;
    int corr_input = scanf("%d%d", &num, &denom);
    if (corr_input != 2 || num < 0 || denom < 0)
        return INCORRECT_INPUT;
    
    int quo = 0;
    // num finally equals rest
    while (num >= denom)
    {
        quo++;
        num -= denom;
    }
    
    print_output(quo, num);
    
    return EXEC_OK;
}
