#ifndef __MATRIX_H__
#define __MATRIX_H__

typedef struct {
    int **values;
    int rows;
    int cols;
} matrix_t;

int create_matrix(matrix_t *matrix, const int rows, const int cols);
void free_matrix(matrix_t *matrix);

int input_multiple_matrix(matrix_t *matrix, size_t *sz);
int input_matrix(matrix_t *matrix);

#endif
