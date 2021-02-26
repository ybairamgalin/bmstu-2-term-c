#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846

int main()
{
    // declaration and input of vars
    printf("Hel");
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
    phi = phi * (M_PI / 180);

    // first fond height, sedond square
    float height = tan(phi) * (base_a - base_b) / 2;
    float square = height * (base_a + base_b) / 2;

    printf("%f", square);
}
