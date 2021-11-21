#ifndef __MATRIX_H__
#define __MATRIX_H__

#define INPUT_ERR 1
#define VALUE_ERR 2

typedef struct {
    int **values;
    size_t rows;
    size_t cols;
} matrix_t;

matrix_t *matrix_alloc(const size_t rows, const size_t cols);
void matrix_free(matrix_t *matrix);

matrix_t *matrix_input();
matrix_t *matrix_copy(matrix_t *old);
void matrix_print(matrix_t *matrix);
void matrix_swap_cols(matrix_t *matrix, const size_t first,
const size_t second);

size_t matrix_contains_max_col(matrix_t *matrix);
size_t matrix_contains_min_col(matrix_t *matrix);

#endif
