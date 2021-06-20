#include <stdio.h>
#include <inttypes.h>
#include <sys/time.h>

#define OK 0
#define INCORRECT_TYPE 2
#define INCORRECT_VALUE 3

#define CORRECT 1
#define NOT_CORRECT 0

#define ARRAY_SIZE 10000
#define MAX_NUMBER_OF_CYCLES 10000

#define EXPECTED_ARGS_INPUT 1
#define EXPECTED_ARGS_MAIN 2


int input(int *first, int *last)
{
    long num_of_elem = last - first;
    int input_is_correct = CORRECT;

    for (int i = 0; i < num_of_elem; i++)
    {
        if (scanf("%d", first + i) != EXPECTED_ARGS_INPUT)
        {
            input_is_correct = NOT_CORRECT;
            break;
        }
    }

    return input_is_correct;
}

int process_1(int arr[], int number_of_elements)
{
    int sum = 0;
    int i = 0, j = number_of_elements - 1;

    while (i < number_of_elements && j >= 0)
    {
        if (arr[i] > 0)
        {
            i++;
            continue;
        }

        if (arr[j] < 0)
        {
            j--;
            continue;
        }

        sum += arr[i] * arr[j];
        i++;
        j--;
    }

    return sum;
}

int process_2(int arr[], int number_of_elements)
{
    int sum = 0;
    int i = 0, j = number_of_elements - 1;

    while (i < number_of_elements && j >= 0)
    {
        if (*(arr + i) > 0)
        {
            i++;
            continue;
        }

        if (*(arr + j) < 0)
        {
            j--;
            continue;
        }

        sum += *(arr + i) * *(arr + j);
        i++;
        j--;
    }

    return sum;
}

int process_3(int *arr, int number_of_elements)
{
    int sum = 0;
    int i = 0, j = number_of_elements - 1;

    while (i < number_of_elements && j >= 0)
    {
        if (*(arr + i) > 0)
        {
            i++;
            continue;
        }

        if (*(arr + j) < 0)
        {
            j--;
            continue;
        }

        sum += *(arr + i) * *(arr + j);
        i++;
        j--;
    }

    return sum;
}

void measure_time(int *array, int number_of_elements,
int (*process)(int *arr, int num), int number_of_cycles)
{
    struct timeval tv_start, tv_stop;
    int64_t elapsed_time = 0;
    gettimeofday(&tv_start, NULL);
    gettimeofday(&tv_stop, NULL);

    for (int i = 0; i < number_of_cycles; i++)
    {
        gettimeofday(&tv_start, NULL);
        process(array, number_of_elements);
        gettimeofday(&tv_stop, NULL);
        elapsed_time += (tv_stop.tv_sec - tv_start.tv_sec) *
                1000000LL + (tv_stop.tv_usec - tv_start.tv_usec);
    }

    printf("%" PRId64 "\tmicroseconds (sec * (1e-6))\n", elapsed_time);
}

int main(void) {
    int number_of_elements, cycles;

    if (scanf("%d%d", &number_of_elements, &cycles) != EXPECTED_ARGS_MAIN)
        return INCORRECT_TYPE;

    if (number_of_elements <= 0 || number_of_elements > ARRAY_SIZE)
        return INCORRECT_VALUE;

    if (cycles <= 0 || cycles > MAX_NUMBER_OF_CYCLES)
        return INCORRECT_VALUE;

    int input_array[ARRAY_SIZE];

    if (input(input_array, input_array + number_of_elements) == NO)
        return INCORRECT_TYPE;

    measure_time(input_array, number_of_elements, process_1, cycles);
    measure_time(input_array, number_of_elements, process_2, cycles);
    measure_time(input_array, number_of_elements, process_3, cycles);
}