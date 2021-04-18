#include <stdio.h>

#define OK 0
#define INPUT_ERROR 1

#define MAX_ROWS 10
#define MAX_COLUMNS 10

#define INPUT_SUCCESSFUL 1
#define INPUT_NOT_SUCCESSFUL 0

#define EXPECTED_ARGS 1

#define IS_SYMMETRICAL 1
#define IS_NOT_SYMMETRICAL 0

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

void matrix_print(int matrix[MAX_ROWS][MAX_COLUMNS], const int rows,
const int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            printf("%d ", matrix[i][j]);

        printf("\n");
    }
}

int row_is_symmetrical(const int *row, const int size)
{
    int symmetry = IS_SYMMETRICAL;

    for (int i = 0, j = size - 1; i < j; i++, j--)
    {
        if (*(row + i) != *(row + j))
        {
            symmetry = IS_NOT_SYMMETRICAL;
            break;
        }
    }

    return symmetry;
}

void array_print(const int *arr, const int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", *(arr + i));

    printf("\n");
}

int main(void)
{
    int array[MAX_ROWS][MAX_COLUMNS];
    int rows, columns;

    if (matrix_input(array, &rows, &columns) == INPUT_NOT_SUCCESSFUL)
        return INPUT_ERROR;

    int result[MAX_ROWS];

    for (int i = 0; i < rows; i++)
    {
        if (row_is_symmetrical(array[i], columns) == IS_SYMMETRICAL)
            result[i] = IS_SYMMETRICAL;
        else
            result[i] = IS_NOT_SYMMETRICAL;
    }

    array_print(result, rows);
}
