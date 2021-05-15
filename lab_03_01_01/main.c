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

#define IS_SYMMETRICAL 1
#define IS_NOT_SYMMETRICAL 0

int matrix_input(int matrix[MAX_ROWS][MAX_COLUMNS], int *rows, int *columns)
{
    if (scanf("%d", rows) != EXPECTED_ARGS)
        return NUMBER_OF_ARGS_ERR;

    if (*rows < MIN_ROWS || *rows > MAX_ROWS)
        return NUMBER_OF_ROWS_ERR;

    if (scanf("%d", columns) != EXPECTED_ARGS)
        return NUMBER_OF_ARGS_ERR;

    if (*columns < MIN_COLUMNS || *columns > MAX_COLUMNS)
        return NUMBER_OF_COLS_ERR;

    for (int i = 0; i < *rows; i++)
        for (int j = 0; j < *columns; j++)
            if (scanf("%d", &matrix[i][j]) != EXPECTED_ARGS)
                return NUMBER_OF_ARGS_ERR;

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

int row_is_symmetrical(const int *row, const int size)
{
    int symmetry = IS_SYMMETRICAL;

    for (int i = 0, j = size - 1; i < j; i++, j--)
        if (*(row + i) != *(row + j))
        {
            symmetry = IS_NOT_SYMMETRICAL;
            break;
        }

    return symmetry;
}

void array_print(const int *arr, const int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", *(arr + i));

    printf("\n");
}

void solve_problem(int (*const array)[MAX_COLUMNS], const int rows, const int cols,
int *res_arr)
{
    for (int i = 0; i < rows; i++)
    {
        if (row_is_symmetrical(array[i], cols) == IS_SYMMETRICAL)
            *(res_arr + i) = IS_SYMMETRICAL;
        else
            *(res_arr + i) = IS_NOT_SYMMETRICAL;
    }
}

void fill_result_array(int (*const source)[MAX_COLUMNS], int *result,
const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)
    {
        if (row_is_symmetrical(source[i], cols) == IS_SYMMETRICAL)
            result[i] = IS_SYMMETRICAL;
        else
            result[i] = IS_NOT_SYMMETRICAL;
    }
}

int main(void)
{
    int array[MAX_ROWS][MAX_COLUMNS];
    int rows, columns;
    int err;

    if ((err = matrix_input(array, &rows, &columns)) != INPUT_SUCCESSFUL)
        return err;

    int result[MAX_ROWS];

    solve_problem(array, rows, columns, result);
    fill_result_array(array, result, rows, columns);

    array_print(result, rows);

    return OK;
}
