#pragma once

#include <stdio.h>

#define OK 0
#define NOT_ENOUGH_ARGS -1

#define EXPECTED_MAXIMUMS 2
#define NOT_ENOUGH_MAXIMUMS -3

int process(FILE *f, int *a, int *b);