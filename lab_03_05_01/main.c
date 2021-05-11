#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define INPUT_ERROR 1

#define MAX_ROWS 10
#define MAX_COLUMNS 10
#define MIN_ROWS 1
#define MIN_COLUMNS 1

#define INPUT_SUCCESSFUL 0
#define NUMBER_OF_ARGS_ERR -1
#define NUMBER_OF_ROWS_ERR -2
#define NUMBER_OF_COLS_ERR -3

#define EXPECTED_ARGS 1

#define NO_ELEMENTS_SUM_GT_TEN -1

#define MAX_POSSIBLE_SUM 10
#define CYCLE_MARGIN 3


int matrix_input(int matrix[MAX_ROWS][MAX_COLUMNS], int *rows, int *columns)
{
    if (scanf("%d", rows) != EXPECTED_ARGS)
        return NUMBER_OF_ARGS_ERR;

    if (*rows <= 0 || *rows > MAX_ROWS)
        return NUMBER_OF_ROWS_ERR;

    if (scanf("%d", columns) != EXPECTED_ARGS)
        return NUMBER_OF_ARGS_ERR;

    if (*columns <= 0 || *columns > MAX_COLUMNS)
        return NUMBER_OF_COLS_ERR;

    for (int i = 0; i < *rows; i++)
        for (int j = 0; j < *columns; j++)
            if (scanf("%d", &matrix[i][j]) != EXPECTED_ARGS)
                return NUMBER_OF_ARGS_ERR;

    return INPUT_SUCCESSFUL;
}

int sum_of_digits(int num)
{
    int sum = 0;
    num = abs(num);

    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

void matrix_print(int (*const matrix)[MAX_COLUMNS], const int rows,
const int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            printf("%d ", matrix[i][j]);

        printf("\n");
    }
}

int get_array(int (*const matrix)[MAX_COLUMNS], const int rows, const int cols,
int *array)
{
    int arr_size = 0;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (sum_of_digits(matrix[i][j]) > MAX_POSSIBLE_SUM)
                array[arr_size++] = matrix[i][j];

    return arr_size;
}

void move_left(int *array, const int size, const int times)
{
    for (int i = 0; i < times; i++)
    {
        int buf = *array;

        for (int j = 0; j < size; j++)
            *(array + j) = *(array + ((j + 1) % size));

        *(array + size - 1) = buf;
    }
}

void array_print(const int *arr, const int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", *(arr + i));

    printf("\n");
}

void fill_matrix_with_arr(int (*matrix)[MAX_COLUMNS], const int rows,
const int cols, const int *arr)
{
    int count = 0;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = (sum_of_digits(matrix[i][j]) > MAX_POSSIBLE_SUM) ?
                arr[count] : matrix[i][j];
            if (sum_of_digits(matrix[i][j]) > MAX_POSSIBLE_SUM)
                count++;
        }
}

int main(void)
{
    int matrix[MAX_ROWS][MAX_COLUMNS];
    int rows, columns;
    int err;

    if ((err = matrix_input(matrix, &rows, &columns)) != INPUT_SUCCESSFUL)
        return err;

    int array[MAX_ROWS * MAX_COLUMNS];
    int arr_size = get_array(matrix, rows, columns, array);

    if (arr_size == 0)
        return NO_ELEMENTS_SUM_GT_TEN;

    move_left(array, arr_size, CYCLE_MARGIN);
    fill_matrix_with_arr(matrix, rows, columns, array);

    matrix_print(matrix, rows, columns);

    return OK;
}
