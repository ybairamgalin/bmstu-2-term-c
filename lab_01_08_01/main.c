//  Created by Yaroslav Bairamgalin on 02.03.2021.
//

#include <stdio.h>

#define EXEC_OK 0
#define INCORRECT_INPUT 10


int main()
{
    // input data check
    unsigned long int byte_a, byte_b, byte_c, byte_d;
    unsigned long int corr_input = scanf("%lu%lu%lu%lu", &byte_a, &byte_b, &byte_c, &byte_d);
    if (corr_input != 4)
        return INCORRECT_INPUT;
    if (byte_a > 255 || byte_b > 255 || byte_c > 255 || byte_d > 255)
        return INCORRECT_INPUT;
    
    //
    unsigned long int byte_a_left_24 = byte_a << 24;
    unsigned long int byte_b_left_16 = byte_b << 16;
    unsigned long int byte_c_left_8 = byte_c << 8;
    
    unsigned long int packed = byte_a_left_24 | byte_b_left_16 | byte_c_left_8 | byte_d;
    
    for (int i = 31; i >= 0; i--)
        printf("%lu", (packed >> i) % 2);
    
    printf("\n");
    
    for (int i = 3; i >= 0; i--)
        printf("%lu ", (packed >> (i * 8)) % 256);
    
    return EXEC_OK;
}
