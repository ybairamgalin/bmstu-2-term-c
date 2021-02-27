//
//  main.c
//  lab01task0502
//
//  Created by Yaroslav Bairamgalin on 27.02.2021.
//

#include <stdio.h>

int main()
{
    int num, denom;
    int corr_input = scanf("%d%d", &num, &denom);
    if (corr_input < 2)
        return 10;
    if (num < 0 || denom <= 0)
        return 10;
    
    int quo = 0;
    // num here finally equals rest
    while (num >= denom)
    {
        quo++;
        num -= denom;
    }
    
    printf("%d %d", quo, num);
}
