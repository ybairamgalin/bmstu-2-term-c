#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define INPUT_ERROR 1

#define MAX_ROWS 10
#define MAX_COLUMNS 10

#define INPUT_SUCCESSFUL 1
#define INPUT_NOT_SUCCESSFUL 0

#define EXPECTED_ARGS 1

#define NO_ELEMENTS_SUM_GT_10 -1

#define CYCLE_MARGIN 3

int matrix_input(int matrix[MAX_ROWS][MAX_COLUMNS], int *rows, int *columns)
{
    if (scanf("%d", rows) != EXPECTED_ARGS)
        return INPUT_NOT_SUCCESSFUL;

    if (*rows <= 0 || *rows > MAX_ROWS)
        return INPUT_NOT_SUCCESSFUL;

    if (scanf("%d", columns) != EXPECTED_ARGS)
        return INPUT_NOT_SUCCESSFUL;

    if (*columns <= 0 || *columns > MAX_COLUMNS)
        return INPUT_NOT_SUCCESSFUL;

    for (int i = 0; i < *rows; i++)
        for (int j = 0; j < *columns; j++)
            if (scanf("%d", &matrix[i][j]) != EXPECTED_ARGS)
                return INPUT_NOT_SUCCESSFUL;

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
            if (sum_of_digits(matrix[i][j]) > 10)
            {
                array[arr_size] = matrix[i][j];
                arr_size++;
            }

    return arr_size;
}

void move_3_left(int *array, const int size)
{
    for (int i = 0; i < CYCLE_MARGIN; i++)
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
            matrix[i][j] = sum_of_digits(matrix[i][j]) > 10 ?
                arr[count] : matrix[i][j];
            count += sum_of_digits(matrix[i][j]) > 10 ? 1 : 0;
        }
}

int main(void)
{
    int matrix[MAX_ROWS][MAX_COLUMNS];
    int rows, columns;

    if (matrix_input(matrix, &rows, &columns) == INPUT_NOT_SUCCESSFUL)
        return INPUT_ERROR;

    int array[MAX_ROWS * MAX_COLUMNS];
    int arr_size = get_array(matrix, rows, columns, array);

    if (arr_size == 0)
        return NO_ELEMENTS_SUM_GT_10;

    move_3_left(array, arr_size);
    fill_matrix_with_arr(matrix, rows, columns, array);

    matrix_print(matrix, rows, columns);

    return OK;
}
