//  Created by Yaroslav Bairamgalin on 28.02.2021.
//

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define EXEC_OK 0
#define INCORRECT_INPUT 10


// function receives sum and returns sin value of this sum
double g_func(double x)
{
    double result = sin(x);
    return result;
}

int main()
{
    double element;

    int corr_input = scanf("%lf", &element);
    if (corr_input != 1)
        return INCORRECT_INPUT;
    if (element < 0)
        return INCORRECT_INPUT;

    double sum = 0;
    int count = 1;
    // until appears negative element
    while (true)
    {
        int corr_input = scanf("%lf", &element);
        if (corr_input != 1)
            return INCORRECT_INPUT;

        if (element >= 0)
            sum += sqrt(element / count);
        else
            break;
        
        count++;
    }

    double result = g_func(sum);
    printf("%lf", result);

    return EXEC_OK;
}


