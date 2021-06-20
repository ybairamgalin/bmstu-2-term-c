#pragma once
#include <stdio.h>

#define OK 0
#define NOT_ENOUGH_MAIN_ARGS -1
#define NO_INTEGERS_IN_FILE -2
#define FILE_CANNOT_BE_OPENED -3

#define EXPECTED_ARGS 1
#define MAX_INT 2147483647

#define YES 1
#define NO 0

int find_max_min(FILE *file, int *max, int *min);
int greater_than_average_nums(FILE *file, const int average);
