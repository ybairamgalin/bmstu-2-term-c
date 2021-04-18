#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define OK 0
#define INPUT_ERROR 1

#define MAX_ROWS 10
#define MAX_COLUMNS 10

#define INPUT_SUCCESSFUL 1
#define INPUT_NOT_SUCCESSFUL 0

#define EXPECTED_ARGS 1

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

void matrix_print(const int matrix[MAX_ROWS][MAX_COLUMNS], const int rows,
const int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            printf("%d ", matrix[i][j]);

        printf("\n");
    }
}

void delete_row(int matrix[MAX_ROWS][MAX_COLUMNS], const int rows,
const int cols, const int row_to_delete)
{
    for (int i = row_to_delete; i < rows - 1; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = matrix[i + 1][j];
}

void delete_column(int matrix[MAX_ROWS][MAX_COLUMNS], const int rows,
const int cols, const int col_to_delete)
{
    for (int i = col_to_delete; i < cols - 1; i++)
        for (int j = 0; j < rows; j++)
            matrix[j][i] = matrix[j][i + 1];
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

void find_element(const int matrix[MAX_ROWS][MAX_COLUMNS], const int rows,
const int cols, int *x, int *y)
{
    int min_sum = INT_MAX;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (sum_of_digits(matrix[i][j]) < min_sum)
            {
                *x = i;
                *y = j;
                min_sum = matrix[i][j];
            }
        }
    }
}

int main(void)
{
    int array[MAX_ROWS][MAX_COLUMNS];
    int rows, columns;

    if (matrix_input(array, &rows, &columns) == INPUT_NOT_SUCCESSFUL)
        return INPUT_ERROR;

    int to_delete_row, to_delete_col;
    find_element(array, rows, columns, &to_delete_row, &to_delete_col);

    delete_row(array, rows, columns, to_delete_row);
    rows = rows - 1;

    delete_column(array, rows, columns, to_delete_col);
    columns = columns - 1;

    matrix_print(array, rows, columns);
}
