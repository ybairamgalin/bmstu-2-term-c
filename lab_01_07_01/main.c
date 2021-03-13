//
//  main.c
//  lab01task07
//
//  Created by Yaroslav Bairamgalin on 27.02.2021.
//

#include <stdio.h>
#include <math.h>

#define INCORRECT_INPUT 10
#define OK 0

#define EXPECTED_ARGS 2

// function receives two parameters: double expected -
// the precise value, double measured - measured or
// approximated value
// function returns abs error of the given data
double abs_error(double expected, double measured)
{
    return fabs(expected - measured);
}

int main(void)
{
    double x;
    double eps;
    int corr_input = scanf("%lf%lf", &x, &eps);
    if (corr_input != EXPECTED_ARGS)
        return INCORRECT_INPUT;
    // due to the task
    if (eps <= 0 || eps > 1)
        return INCORRECT_INPUT;
    
    double precise_value = sin(x);
    double approx_value = x;
    double current = approx_value;
    int count = 1; // for managing the power of x
    
    while (fabs(precise_value - approx_value) > eps)
    {
        current = (current * (-1) * x * x) / ((count + 1) * (count + 2));
        approx_value += current;
        count += 2;
    }
    
    // errors
    double absolute_error = abs_error(precise_value, approx_value);
    double relative_error = absolute_error / precise_value;
    
    printf("%lf %lf %lf %lf", approx_value, precise_value, absolute_error, relative_error);

    return OK;
}
