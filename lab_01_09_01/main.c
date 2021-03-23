//  Created by Yaroslav Bairamgalin on 28.02.2021.
//

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define OK 0
#define INCORRECT_TYPE 10
#define INCORRECT_VALUE 5

#define EXPECTED_ARGS 1

// function receives sum and returns sin value of this sum
double g_term(double x, int count)
{
    return sqrt(x / count);
}

int main(void)
{
    double element;

    int corr_input = scanf("%lf", &element);

    if (corr_input != EXPECTED_ARGS)
        return INCORRECT_TYPE;

    if (element < 0)
        return INCORRECT_VALUE;

    double sum = sqrt(element);
    
    // set count = 2 as the first element has already been given
    int count = 2;
    
    // until appears negative element
    while (true)
    {
        int corr_input = scanf("%lf", &element);

        if (corr_input != 1)
            return INCORRECT_TYPE;

        if (element >= 0)
            sum += g_term(element, count);
        else
            break;
        count++;
    }

    double result = sin(sum);
    printf("%lf", result);

    return OK;
}


