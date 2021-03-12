#include <stdio.h>

#define EXEC_OK 0

int main()
{
    // declaration and input of vars
    float volume_1, volume_2, volume_out;
    float temp_1, temp_2, temp_out;
    scanf("%f%f%f%f", &volume_1, &temp_1, &volume_2, &temp_2);

    // solve the problem using physics formula
    volume_out = volume_1 + volume_2;
    temp_out = (volume_1 * temp_1 + volume_2 * temp_2) / volume_out;

    printf("%f %f", volume_out, temp_out);
    return EXEC_OK;
}
