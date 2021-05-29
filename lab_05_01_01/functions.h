#pragma once

#include <stdio.h>

#define OK 0
#define NOT_ENOUGH_ARGS -1
#define NOT_ENOUGH_MAXIMUMS -3

#define EXPECTED_MAXIMUMS 2

int process(FILE *f, int *first_max, int *second_max);