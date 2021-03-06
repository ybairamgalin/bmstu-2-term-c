//  Created by Yaroslav Bairamgalin on 02.03.2021.
//

#include <stdio.h>

#define OK 0
#define INCORRECT_TYPE 10
#define INCORRECT_VALUE 5

#define EXPECTED_ARGS 4

#define MAX_BYTE_VALUE 255
#define BYTE_DIGITS 8
#define INT_DIGITS 32

// function receives 4 bytes and returns 4 bytes packed into a single var
// all vars type is unsigned long int
unsigned long int pack(const unsigned long int byte_1, const unsigned long int byte_2, const unsigned long int byte_3, const unsigned long int byte_4)
{
    return byte_1 | byte_2 | byte_3 | byte_4;
}


int main(void)
{
    unsigned long int byte_a, byte_b, byte_c, byte_d;
    unsigned long int corr_input = scanf("%lu%lu%lu%lu", &byte_a, &byte_b, &byte_c, &byte_d);

    if (corr_input != EXPECTED_ARGS)
    {
        printf("Error: input error");
        return INCORRECT_TYPE;
    }

    if (byte_a > MAX_BYTE_VALUE || byte_b > MAX_BYTE_VALUE || byte_c > MAX_BYTE_VALUE || byte_d > MAX_BYTE_VALUE)
    {
        printf("Error: input error");
        return INCORRECT_VALUE;
    }

    unsigned long int byte_a_left_24 = byte_a << BYTE_DIGITS * 3;
    unsigned long int byte_b_left_16 = byte_b << BYTE_DIGITS * 2;
    unsigned long int byte_c_left_8 = byte_c << BYTE_DIGITS;
    
    unsigned long int packed = pack(byte_a_left_24, byte_b_left_16, byte_c_left_8, byte_d);
    
    printf("Result: ");

    for (int i = INT_DIGITS - 1; i >= 0; i--)
        printf("%lu", (packed >> i) % 2);
    
    printf(" ");
    
    for (int i = EXPECTED_ARGS - 1; i >= 0; i--)
        printf("%lu ", (packed >> (i * BYTE_DIGITS)) % (MAX_BYTE_VALUE + 1));
    
    return OK;
}
