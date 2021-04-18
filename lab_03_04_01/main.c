#include <stdio.h>

#define OK 0
#define INPUT_ERROR 1

#define MAX_ROWS 10
#define MAX_COLUMNS 10

#define INPUT_SUCCESSFUL 1
#define INPUT_NOT_SUCCESSFUL 0

#define EXPECTED_ARGS 1

int matrix_input(int (*matrix)[MAX_COLUMNS], int *rows, int *columns)
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

void swap(int *row_1, int *row_2, const int start, const int stop)
{
    for (int i = start; i < stop; i++)
    {
        int buf = *(row_1 + i);
        *(row_1 + i) = *(row_2 + i);
        *(row_2 + i) = buf;
    }
}

void swap_lines(int (*matrix)[MAX_COLUMNS], const int rows, const int cols)
{
    for (int i = 0; i < rows / 2; i++)
        swap(matrix[i], matrix[rows - 1 - i], i, cols - i);
}

int main(void)
{
    int array[MAX_ROWS][MAX_COLUMNS];
    int rows, columns;

    if (matrix_input(array, &rows, &columns) == INPUT_NOT_SUCCESSFUL)
        return INPUT_ERROR;

    swap_lines(array, rows, columns);
    matrix_print(array, rows, columns);
}
