//
// Created by gzq on 18-10-11.
//

#ifndef MATRIXMULTIPLICATION_UTILS_H
#define MATRIXMULTIPLICATION_UTILS_H

#include <stdbool.h>

#define CROSS_BLOCK_LOW(id, p, n) ((id) * (n) / (p))
#define CROSS_BLOCK_HIGH(id, p, n) (CROSS_BLOCK_LOW((id) + 1, p, n) - 1)
#define CROSS_BLOCK_SIZE(id, p, n) (CROSS_BLOCK_LOW((id)+1,p,n)-(CROSS_BLOCK_LOW(id,p,n)))
#define CROSS_BLOCK_OWNER(index, p, n) (((p) * ((index) + 1) - 1) / (n))

bool check_error(const double *A, const double *B, const double *C, int a, int b, int c);

void get_mnk(int argc, char *const *argv, int *a, int *b, int *c);

void get_mnk_threadcount(int argc, char *const *argv, int *a, int *b, int *c, int *thread_count);

#endif //MATRIXMULTIPLICATION_UTILS_H
