//
// Created by gzq on 18-10-11.
//


#include <stdlib.h>
#include <stdio.h>
#include <random_uitls.h>
#include "utils.h"

bool check_error(const double *A, const double *B, const double *C, int a, int b, int c) {
    double CC;
    if ((a * b * c) < 10000) {
        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < c; ++j) {
                CC = 0;
                for (int k = 0; k < b; ++k) {
                    CC += A[i * b + k] * B[k * c + j];
                }
                if (abs(CC - C[i * c + j]) > 0.1) {
                    printf("error!!! at (%d,%d) should be %lf but %lf\n", i, j, CC, C[i * c + j]);
                    return false;
                }
            }
        }
    } else {  //抽样检查
        int *indexs = malloc(1000 * 2 * sizeof(int));
        for (int i = 0; i < 1000; ++i) {
            indexs[i * 2 + 0] = randint(0, a);
            indexs[i * 2 + 1] = randint(0, c);
        }
        for (int p = 0; p < 1000; ++p) {
            int i = indexs[p * 2 + 0], j = indexs[p * 2 + 1];
            CC = 0;
            for (int k = 0; k < b; ++k) {
                CC += A[i * b + k] * B[k * c + j];
            }
            if (abs(CC - C[i * c + j]) > 0.1) {
                printf("error!!! at (%d,%d) should be %lf but %lf\n", i, j, CC, C[i * c + j]);
                return false;
            }
        }
    }
    printf("successful!!!\n");
    return true;
}

void get_mnk(int argc, char *const *argv, int *a, int *b, int *c) {
    if (argc < 4) {
        (*a) = 4;
        (*b) = 4;
        (*c) = 4;
    } else {
        (*a) = atoi(argv[1]);
        (*b) = atoi(argv[2]);
        (*c) = atoi(argv[3]);
    }
}

void get_mnk_threadcount(int argc, char *const *argv, int *a, int *b, int *c, int *thread_count) {
    if (argc < 4) {
        (*a) = 4;
        (*b) = 4;
        (*c) = 4;
        *thread_count = 1;
    } else if (argc == 5) {
        (*a) = atoi(argv[1]);
        (*b) = atoi(argv[2]);
        (*c) = atoi(argv[3]);
        *thread_count = atoi(argv[4]);
    } else if (argc == 4) {
        (*a) = atoi(argv[1]);
        (*b) = atoi(argv[2]);
        (*c) = atoi(argv[3]);
        *thread_count = 4;
    }
}
