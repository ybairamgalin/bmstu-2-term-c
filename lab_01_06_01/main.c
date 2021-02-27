//
//  main.c
//  lab01task05
//
//  Created by Yaroslav Bairamgalin on 27.02.2021.
//

#include <stdio.h>

#define EPS 1e-10


int main()
{
    float x_a, y_a, x_b, y_b, x_c, y_c;
    float det, square;
    
    int corr_input = scanf("%f%f%f%f%f%f", &x_a, &y_a, &x_b, &y_b, &x_c, &y_c);
    if (corr_input < 6)
        return 10;
    
    // solve for signed square using det formula
    det = (x_a - x_c) * (y_b - y_c) - (x_b - x_c) * (y_a - y_c);
    square = det / 2;
    
    // check if the points are in the same line
    if (det < EPS)
        return 10;
    
    // using det formula determinant may and up being negative
    if (square < 0)
        square = -square;
    
    printf("%f", square);
    return 0;
}
