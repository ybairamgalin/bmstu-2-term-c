#include <stdio.h>

#define EXEC_OK 0

#define APARTMENTS_IN_PORCH 36
#define APARTMENTS_IN_FLOOR 4

int main()
{
    int apart_num;
    int porch;
    int floor;
    scanf("%d", &apart_num);

    // enumerate apartments, porches, floors from 0, then add 1 to each result
    apart_num--;
    porch = apart_num / APARTMENTS_IN_PORCH;
    floor = (apart_num - APARTMENTS_IN_PORCH * porch) / APARTMENTS_IN_FLOOR;

    porch++;
    floor++;

    printf("%d %d", porch, floor);
    return EXEC_OK;
}
