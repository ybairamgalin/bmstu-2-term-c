#include <stdlib.h>
#include <stdio.h>
#include "check_my_string.h"

int main(void)
{
    int failed = run_check_my_string();

    printf("UNIT TESTING %s.\n",
           failed == 0 ? "\033[32mPASSED\033[0m": "\033[31mFAILED\033[0m");

    return failed;
}
