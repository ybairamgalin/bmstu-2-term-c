#include <stdio.h>
#include <inttypes.h>
#include <sys/time.h>

#define OK 0
#define INCORRECT_TYPE 2
#define INCORRECT_VALUE 3

#define YES 1
#define NO 0

#define ARRAY_SIZE 10000
#define MAX_NUMBER_OF_CYCLES 10000

#define EXPECTED_ARGS_INPUT 1
#define EXPECTED_ARGS_MAIN 2

// function receives pointer to an array and number of elements in this array
// function returns 1, if input is correct
// 0, if input in not correct
int input(int *first, int *last)
{
    long num_of_elem = last - first;
    int input_is_correct = YES;

    for (int i = 0; i < num_of_elem; i++)
    {
        int read_elements = scanf("%d", first + i);

        if (read_elements != EXPECTED_ARGS_INPUT)
        {
            input_is_correct = NO;
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

int main(void) {
    int number_of_elements;
    int number_of_cycles;
    int corr_input = scanf("%d%d", &number_of_elements, &number_of_cycles);

    if (corr_input != EXPECTED_ARGS_MAIN)
        return INCORRECT_TYPE;

    if (number_of_elements <= 0 || number_of_elements > ARRAY_SIZE)
        return INCORRECT_VALUE;

    if (number_of_cycles <= 0 || number_of_cycles > MAX_NUMBER_OF_CYCLES)
        return INCORRECT_VALUE;

    int input_array[ARRAY_SIZE];

    if (input(input_array, input_array + number_of_elements) == NO)
        return INCORRECT_TYPE;

    struct timeval tv_start, tv_stop;
    // elapsed_time_N - время выполнения функции process_N,
    int64_t elapsed_time_1 = 0, elapsed_time_2 = 0, elapsed_time_3 = 0;

    // measure process_1
    gettimeofday(&tv_start, NULL);
    gettimeofday(&tv_stop, NULL);
    for (int i = 0; i < number_of_cycles; i++)
    {
        gettimeofday(&tv_start, NULL);
        process_1(input_array, number_of_elements);
        gettimeofday(&tv_stop, NULL);
        elapsed_time_1 += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL + (tv_stop.tv_usec - tv_start.tv_usec);
    }

    // measure process_2
    for (int i = 0; i < number_of_cycles; i++)
    {
        gettimeofday(&tv_start, NULL);
        process_2(input_array, number_of_elements);
        gettimeofday(&tv_stop, NULL);
        elapsed_time_2 += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL + (tv_stop.tv_usec - tv_start.tv_usec);
    }

    // measure process_2
    for (int i = 0; i < number_of_cycles; i++)
    {
        gettimeofday(&tv_start, NULL);
        process_3(input_array, number_of_elements);
        gettimeofday(&tv_stop, NULL);
        elapsed_time_3 += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL + (tv_stop.tv_usec - tv_start.tv_usec);
    }



    printf("%" PRId64 "\tmicroseconds (sec * (1e-6))\n", elapsed_time_1);
    printf("%" PRId64 "\tmicroseconds (sec * (1e-6))\n", elapsed_time_2);
    printf("%" PRId64 "\tmicroseconds (sec * (1e-6))\n", elapsed_time_3);

}