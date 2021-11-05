#ifndef __MATRIX_H__
#define __MATRIX_H__

#define INPUT_ERR 2
#define MEM_ERR 3
#define NO_SUCH_FILE_ERR 4
#define FILE_FORMAT_ERR 5

#define MAX(a, b) (a >= b) ? a : b
#define SIGN_TERM -1

typedef struct {
    int **values;
    int rows;
    int cols;
} matrix_t;

int input_matrix(matrix_t *matrix);
void print_matrix(const matrix_t matrix);
void free_matrix(matrix_t *matrix);
void make_square_matrix(matrix_t *matrix);
int expand_matrix(matrix_t *matrix, const int new_sz);
matrix_t multiply_matrix(const matrix_t first, const matrix_t second);
int input_powers(int *p, int *q);
matrix_t pow_matrix(const matrix_t matrix, const int pow);
long long matrix_det(const matrix_t matrix, long long *result);
int read_matrix_from_file(const char *filename, matrix_t *matrix);
int save_num_to_file(const char *filename, const long long num);
int save_matrix_to_file(const char *filename, const matrix_t matrix);
matrix_t add_matrix(const matrix_t first, const matrix_t second);

#endif
