#include <stdio.h>

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
#define NOT_SQ_MATRIX_ERR -4

#define EXPECTED_ARGS 1

int matrix_input(int matrix[MAX_ROWS][MAX_COLUMNS], int *rows, int *columns)
{
    if (scanf("%d", rows) != EXPECTED_ARGS)
        return NUMBER_OF_ARGS_ERR;

    if (*rows < MIN_ROWS || *rows > MAX_ROWS)
        return NUMBER_OF_ROWS_ERR;

    if (scanf("%d", columns) != EXPECTED_ARGS)
        return NUMBER_OF_ARGS_ERR;

    if (*columns < MIN_ROWS || *columns > MAX_COLUMNS)
        return NUMBER_OF_COLS_ERR;

    if (*rows != *columns)
        return NOT_SQ_MATRIX_ERR;

    for (int i = 0; i < *rows; i++)
        for (int j = 0; j < *columns; j++)
            if (scanf("%d", &matrix[i][j]) != EXPECTED_ARGS)
                return NUMBER_OF_ARGS_ERR;

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

void swap_rows(int *row_1, int *row_2, const int start, const int stop)
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
        swap_rows(matrix[i], matrix[rows - 1 - i], i, cols - i);
}

int main(void)
{
    int array[MAX_ROWS][MAX_COLUMNS];
    int rows, columns;
    int err;

    if ((err = matrix_input(array, &rows, &columns)) != INPUT_SUCCESSFUL)
        return err;

    swap_lines(array, rows, columns);
    matrix_print(array, rows, columns);

    return OK;
}
