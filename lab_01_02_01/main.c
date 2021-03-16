#include <stdio.h>
#include <math.h>

#define OK 0

// TO_RAD = PI / 180
#define TO_RAD 0.017453292519943


// function receives float x in degrees
// returns the equivalent value in degrees
float to_rad(float x)
{
    return x * TO_RAD;
}

int main(void)
{
    float base_a, base_b;
    float phi;
    scanf("%f%f%f", &base_a, &base_b, &phi);

    if (base_a < base_b)
    {
        float buf = base_a;
        base_a = base_b;
        base_b = buf;
    }

    phi = to_rad(phi);

    // first fond height, second square
    float height = tan(phi) * (base_a - base_b) / 2;
    float square = height * (base_a + base_b) / 2;

    printf("%f", square);

    return OK;
}
