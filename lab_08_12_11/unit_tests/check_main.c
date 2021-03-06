#include <stdio.h>
#include "check_matrix.h"

int main(void)
{
    int failed = run_check_matrix();

    printf("UNIT TESTING %s.\n",
       failed == 0 ? "\033[32mPASSED\033[0m": "\033[31mFAILED\033[0m");

    return failed;
}
