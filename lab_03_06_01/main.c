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
#define NOT_SQ_MATRIX_ERR -4

#define EXPECTED_ARGS 2

#define MIN(a, b) (a <= b) ? a : b

int input_dims(int *rows, int *columns)
{
    if (scanf("%d%d", rows, columns) != EXPECTED_ARGS)
        return NUMBER_OF_ARGS_ERR;

    if (*rows < MIN_ROWS || *rows > MAX_ROWS)
        return NUMBER_OF_ROWS_ERR;

    if (*columns < MIN_COLUMNS || *columns > MAX_COLUMNS)
        return NUMBER_OF_COLS_ERR;

    if (*rows != *columns)
        return NOT_SQ_MATRIX_ERR;


    return INPUT_SUCCESSFUL;
}

void matrix_print(int (*const matrix)[MAX_COLUMNS], const int rows,
const int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            printf("%d\t", matrix[i][j]);

        printf("\n");
    }
}

void fill_matrix_spiral(int (*matrix)[MAX_COLUMNS], const int rows, const int cols)
{
    int current = 1;
    int m_rows = 0, m_cols = 0;

    while (current <= rows * cols)
    {
        for (int i = m_rows, j = m_cols; j < cols - m_cols; j++)
            matrix[i][j] = current++;

        if (current > rows * cols)
            break;

        for (int i = m_rows + 1, j = cols - m_cols - 1; i < rows - m_rows; i++)
            matrix[i][j] = current++;

        if (current > rows * cols)
            break;

        for (int i = rows - m_rows - 1, j = cols - m_cols - 2; j >= m_cols; j--)
            matrix[i][j] = current++;

        if (current > rows * cols)
            break;

        for (int i = rows - m_rows - 2, j = m_cols; i > m_rows; i--)
            matrix[i][j] = current++;

        m_rows++;
        m_cols++;
    }
}

int main(void)
{
    int array[MAX_ROWS][MAX_COLUMNS] = { 0 };
    int rows, columns;
    int err;

    if ((err = input_dims(&rows, &columns)) != INPUT_SUCCESSFUL)
        return err;

    fill_matrix_spiral(array, rows, columns);
    matrix_print(array, rows, columns);

    return OK;
}
