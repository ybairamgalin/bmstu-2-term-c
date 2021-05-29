#include <stdio.h>

#define _USE_MATH_DEFINES
#include <math.h>

#define OK 0

#define TO_RAD(degrees) degrees * M_PI / 180


// function receives float x in degrees
// returns the equivalent value in rad
float trapezoid_area(const float base_a, const float base_b, const float height)
{
    return height * (base_a + base_b) / 2;
}

int main(void)
{
    float base_a, base_b;
    float phi;
    scanf("%f%f%f", &base_a, &base_b, &phi);

    phi = TO_RAD(phi);

    float height = tan(phi) * fabsf(base_a - base_b) / 2;
    float square = trapezoid_area(base_a, base_b, height);

    printf("%f", square);

    return OK;
}
