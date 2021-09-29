#ifndef __ARR_HANDLE_H__
#define __ARR_HANDLE_H__

void mysort(void *ptr, size_t count, size_t size,
int (*comp)(const void *, const void *));
int int_cmp(const void *a, const void *b);

#endif