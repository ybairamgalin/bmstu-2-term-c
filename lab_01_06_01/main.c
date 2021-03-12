//
//  main.c
//  lab01task05
//
//  Created by Yaroslav Bairamgalin on 27.02.2021.
//

#include <stdio.h>

#define EXEC_OK 0
#define INCORRECT_INPUT 10
#define EXPECTED_ARGS 6

#define EPS 1e-10

// function receives float x and returns its absolute value
float absolute_value(float x)
{
    if (x < 0)
        x = -x;
    return x;
}

int main()
{
    float x_a, y_a, x_b, y_b, x_c, y_c;
    float det, square;
    
    int corr_input = scanf("%f%f%f%f%f%f", &x_a, &y_a, &x_b, &y_b, &x_c, &y_c);
    if (corr_input != EXPECTED_ARGS)
        return INCORRECT_INPUT;
    
    // solve for signed square using det formula
    det = (x_a - x_c) * (y_b - y_c) - (x_b - x_c) * (y_a - y_c);
    square = det / 2;
    
    // using det formula determinant may and up being negative
    square = absolute_value(square);
    
    // check if the points are in the same line
    if (square < EPS)
        return INCORRECT_INPUT;
    
    printf("%f", square);
    return EXEC_OK;
}
