#include <stdio.h>
#include <math.h>

#define EXEC_OK 0

#define TO_RAD 0.017453292519943

int main()
{
    // declaration and input of vars
    float base_a, base_b;
    float phi;
    scanf("%f%f%f", &base_a, &base_b, &phi);

    // in order to make a > b
    if (base_a < base_b)
    {
        float buf = base_a;
        base_a = base_b;
        base_b = buf;
    }

    // convert phi to rad
    phi = phi * TO_RAD;

    // first fond height, second square
    float height = tan(phi) * (base_a - base_b) / 2;
    float square = height * (base_a + base_b) / 2;

    printf("%f", square);

    return EXEC_OK;
}
