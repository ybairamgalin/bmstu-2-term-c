//
//  main.c
//  lab01task07
//
//  Created by Yaroslav Bairamgalin on 27.02.2021.
//

#include <stdio.h>
#include <math.h>

#define OK 0
#define INCORRECT_TYPE 10
#define EPS_IS_TOO_LOW 9
#define INCORRECT_VALUE 5
#define DIVISION_BY_ZERO 3

#define EXPECTED_ARGS 2

#define MAX_CYCLES 1000

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
        return INCORRECT_TYPE;
    // due to the task
    if (eps <= 0 || eps > 1)
        return INCORRECT_VALUE;
    
    double precise_value = sin(x);
    double approx_value = x;
    double current = approx_value;
    int count = 1; // for managing the power of x
    
    while (fabs(precise_value - approx_value) > eps && count <= MAX_CYCLES)
    {
        current *= - (x * x) / ((count + 1) * (count + 2));
        approx_value += current;
        count += 2;
    }

    if (count >= MAX_CYCLES)
        return EPS_IS_TOO_LOW;
    
    // errors
    double absolute_error = abs_error(precise_value, approx_value);

    if (precise_value == 0)
        return DIVISION_BY_ZERO;
    double relative_error = absolute_error / precise_value;

    printf("%lf %lf %lf %lf", approx_value, precise_value, absolute_error, relative_error);

    return OK;
}
