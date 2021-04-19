#include <stdio.h>

#define OK 0
#define INPUT_ERROR 1

#define MAX_ROWS 10
#define MAX_COLUMNS 10

#define INPUT_SUCCESSFUL 1
#define INPUT_NOT_SUCCESSFUL 0

#define EXPECTED_ARGS 1

#define INT_MIN -2147483647

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

int max_element_in_row(const int *row, int cols)
{
    int max_elem = INT_MIN;

    for (int i = 0; i < cols; i++)
        max_elem = (max_elem < *(row + i)) ? *(row + i) : max_elem;

    return max_elem;
}

void array_print(const int *arr, const int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", *(arr + i));

    printf("\n");
}

void swap_rows(int *row_1, int *row_2, const int size)
{
    for (int i = 0; i < size; i++)
    {
        int buf = *(row_1 + i);
        *(row_1 + i) = *(row_2 + i);
        *(row_2 + i) = buf;
    }
}

void sort_rows(int (*matrix)[MAX_COLUMNS], const int rows,
const int cols)
{
    int max_elements[MAX_COLUMNS];

    for (int i = 0; i < rows; i++)
        max_elements[i] = max_element_in_row(matrix[i], cols);

    for (int i = 0; i < cols; i++)
        for (int j = 1; j < cols - i; j++)
            if (max_elements[j] > max_elements[j - 1])
            {
                int buf = max_elements[j];
                max_elements[j] = max_elements[j - 1];
                max_elements[j - 1] = buf;
                swap_rows(matrix[j], matrix[j - 1], cols);
            }
}

int main(void)
{
    int array[MAX_ROWS][MAX_COLUMNS];
    int rows, columns;

    if (matrix_input(array, &rows, &columns) == INPUT_NOT_SUCCESSFUL)
        return INPUT_ERROR;

    sort_rows(array, rows, columns);
    matrix_print(array, rows, columns);

    return OK;
}
