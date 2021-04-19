#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define INPUT_ERROR 1

#define MAX_ROWS 10
#define MAX_COLUMNS 10

#define INPUT_SUCCESSFUL 1
#define INPUT_NOT_SUCCESSFUL 0

#define EXPECTED_ARGS 1

#define MIN(a, b) a <= b ? a : b

int input(int *rows, int *columns)
{
    if (scanf("%d", rows) != EXPECTED_ARGS)
        return INPUT_NOT_SUCCESSFUL;

    if (*rows <= 0 || *rows > MAX_ROWS)
        return INPUT_NOT_SUCCESSFUL;

    if (scanf("%d", columns) != EXPECTED_ARGS)
        return INPUT_NOT_SUCCESSFUL;

    if (*columns <= 0 || *columns > MAX_COLUMNS)
        return INPUT_NOT_SUCCESSFUL;

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

void fill_matrix(int (*matrix)[MAX_COLUMNS], const int rows, const int cols)
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
    int array[MAX_ROWS][MAX_COLUMNS] = {0};
    int rows, columns;

    if (input(&rows, &columns) == INPUT_NOT_SUCCESSFUL)
        return INPUT_ERROR;

    fill_matrix(array, rows, columns);
    matrix_print(array, rows, columns);
}
