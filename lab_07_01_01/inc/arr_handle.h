#ifndef __ARR_HANDLE_H__
#define __ARR_HANDLE_H__

#define ERR_NULL_MEM_POINTER 4
#define ERR_KEY_NULL_POINTER 5
#define ERR_WRONG_POINTERS_VAL 6
#define ERR_NOT_ENOUGH_ELEMENTS 7
#define ERR_NO_MAX_MIN_VAL_IN_ARR 8

void mysort(void *ptr, size_t count, size_t size,
int (*comp)(const void *, const void *));
int int_cmp(const void *a, const void *b);
int get_mem(int **p_arr, const size_t sz);
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

#endif
