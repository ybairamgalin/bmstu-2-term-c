#ifndef __MATRIX_H__
#define __MATRIX_H__

#define INPUT_ERR 2
#define MEM_ERR 3

typedef struct {
    int **values;
    int rows;
    int cols;
} matrix_t;

int input_matrix(matrix_t *matrix);
void print_matrix(const matrix_t matrix);
void free_matrix(matrix_t *matrix);
void make_square_matrix(matrix_t *matrix);

#endif
