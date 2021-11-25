#include <stdlib.h>
#include "check_matrix.h"

int main()
{
    int failed = 0;
    failed += run_check_matrix();

    return failed;
}
