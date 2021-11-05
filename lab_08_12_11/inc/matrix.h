#ifndef __MATRIX_H__
#define __MATRIX_H__

#define INPUT_ERR 2
#define MEM_ERR 3
#define NO_SUCH_FILE_ERR 4
#define FILE_FORMAT_ERR 5
#define INVALID_ARGS 6
#define WRONG_DIMS 7

typedef struct
{
    double **values;
    int rows;
    int cols;
} matrix_t;

int create_matrix(matrix_t *matrix, const int rows, const int cols);
void free_matrix(matrix_t *matrix);

matrix_t multiply_matrix(const matrix_t first, const matrix_t second);
matrix_t add_matrix(const matrix_t first, const matrix_t second);
int matrix_det(const matrix_t matrix, double *result);

int read_matrix_from_file(const char *filename, matrix_t *matrix);

int add_matrices_from_file(const char *filename_1, const char *filename_2,
const char *dest_file);
int multiply_matrices_from_file(const char *filename_1, const char *filename_2,
const char *dest_file);
int det_matrix_from_file(const char *filename, const char *dest_file);

#endif
