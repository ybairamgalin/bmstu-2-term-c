#include <stdio.h>

#define EXEC_OK 0

int main()
{
    int apart_num;
    int porch;
    int floor;
    scanf("%d", &apart_num);

    // enumerate apartments, porches, floors from 0, then add 1 to each result
    apart_num--;
    porch = apart_num / 36;
    floor = (apart_num - 36 * porch) / 4;

    porch++;
    floor++;

    printf("%d %d", porch, floor);
    return EXEC_OK;
}
