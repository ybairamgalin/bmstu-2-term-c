#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define INPUT_ERROR 1

#define MAX_ROWS 10
#define MAX_COLUMNS 10
#define MIN_ROWS 2
#define MIN_COLUMNS 2

#define INPUT_SUCCESSFUL 1
#define INPUT_NOT_SUCCESSFUL 0

#define EXPECTED_ARGS 1

int matrix_input(int (*matrix)[MAX_COLUMNS], int *rows, int *columns)
{
    if (scanf("%d", rows) != EXPECTED_ARGS)
        return INPUT_NOT_SUCCESSFUL;

    if (*rows < MIN_ROWS || *rows > MAX_ROWS)
        return INPUT_NOT_SUCCESSFUL;

    if (scanf("%d", columns) != EXPECTED_ARGS)
        return INPUT_NOT_SUCCESSFUL;

    if (*columns < MIN_COLUMNS || *columns > MAX_COLUMNS)
        return INPUT_NOT_SUCCESSFUL;

    for (int i = 0; i < *rows; i++)
        for (int j = 0; j < *columns; j++)
            if (scanf("%d", &matrix[i][j]) != EXPECTED_ARGS)
                return INPUT_NOT_SUCCESSFUL;

    return INPUT_SUCCESSFUL;
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

void delete_row(int (*matrix)[MAX_COLUMNS], int *rows,
const int cols, const int row_to_delete)
{
    (*rows)--;

    for (int i = row_to_delete; i < *rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = matrix[i + 1][j];
}

void delete_column(int (*matrix)[MAX_COLUMNS], const int rows,
int *cols, const int col_to_delete)
{
    (*cols)--;

    for (int i = col_to_delete; i < *cols; i++)
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

void find_element(int (*const matrix)[MAX_COLUMNS], const int rows,
const int cols, int *row_elem, int *col_elem)
{
    int min_sum = sum_of_digits(matrix[0][0]);
    *row_elem = 0;
    *col_elem = 0;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (sum_of_digits(matrix[i][j]) < min_sum)
            {
                *row_elem = i;
                *col_elem = j;
                min_sum = sum_of_digits(matrix[i][j]);
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

    delete_row(array, &rows, columns, to_delete_row);

    delete_column(array, rows, &columns, to_delete_col);

    matrix_print(array, rows, columns);

    return OK;
}
