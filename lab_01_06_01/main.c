//
//  main.c
//  lab01task05
//
//  Created by Yaroslav Bairamgalin on 27.02.2021.
//

#include <stdio.h>
#include <math.h>

#define OK 0
#define INCORRECT_INPUT 10
#define EXPECTED_ARGS 6

#define EPS 1e-10


// function elements of 2x2 matrix and returns its determinant
float det_2x2(int m11, int m12, int m21, int m22)
{
    return m11 * m22 - m21 * m12;
}

int main(void)
{
    float x_a, y_a, x_b, y_b, x_c, y_c;
    float det, square;
    
    int corr_input = scanf("%f%f%f%f%f%f", &x_a, &y_a, &x_b, &y_b, &x_c, &y_c);
    if (corr_input != EXPECTED_ARGS)
        return INCORRECT_INPUT;
    
    // solve for signed square using det formula
    det = det_2x2(x_a - x_c, y_a - y_c, x_b - x_c, y_b - y_c);
    square = fabs(det / 2);
    
    // check if the points are in the same line
    if (square < EPS)
        return INCORRECT_INPUT;
    
    printf("%f", square);
    return OK;
}
