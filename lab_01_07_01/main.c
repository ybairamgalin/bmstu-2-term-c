//
//  main.c
//  lab01task07
//
//  Created by Yaroslav Bairamgalin on 27.02.2021.
//

#include <stdio.h>
#include <math.h>

int main()
{
    double x;
    double eps;
    int corr_input = scanf("%lf%lf", &x, &eps);
    if (corr_input < 2)
        return 10;
    // due to the task
    if (eps <= 0 || eps > 1)
        return 10;
    
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
    double absolute_error = fabs(precise_value - approx_value);
    double relative_error = absolute_error / precise_value;
    
    printf("%lf %lf %lf %lf", approx_value, precise_value, absolute_error, relative_error);

    return 0;
}
