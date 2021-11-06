#include <stdlib.h>
#include <stdio.h>
#include "check_movie.h"

int main(void)
{
    int failed = run_check_movie();

    printf("UNIT TESTING %s.\n",
           failed == 0 ? "\033[32mPASSED\033[0m": "\033[31mFAILED\033[0m");

    return failed;
}
