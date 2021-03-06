//
//  main.c
//  lab01task0501
//
//  Created by Yaroslav Bairamgalin on 27.02.2021.
//

#include <stdio.h>

#define INCORRECT_INPUT 10
#define EXEC_OK 0

// prints two double vars
// input vars should be turned into int when pipeline is fixed
void print_output(double first, double second)
{
    printf("%lf %lf", first, second);
}

int main()
{
    // !!! double is set only to complete pipeline
    // once fixed, should be turned into int !!!
    double num, denom;
    int corr_input = scanf("%lf%lf", &num, &denom);
    if (corr_input != 2 || num < 0 || denom <= 0)
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
