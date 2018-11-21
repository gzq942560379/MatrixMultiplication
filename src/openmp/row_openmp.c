//
// Created by gzq on 18-10-21.
//
#include <stdio.h>
#include <stdlib.h>
#include <random_uitls.h>
#include <console_utils.h>
#include <utils.h>
#include <time_utils.h>
#include <omp.h>

int main(int argc, char **argv) {
    int a, b, c, thread_count;
    get_mnk_threadcount(argc, argv, &a, &b, &c, &thread_count);

    float *mem = malloc((a * b + b * c + a * c) * sizeof(float));
    const float *A = mem, *B = mem + a * b;
    float *C = mem + a * b + b * c;
    random_float_array(mem, a * b + b * c, 0, 10);

    timer timer;
    start(&timer);

#pragma omp parallel for num_threads(thread_count) default(none) shared(A,B,C,a,b,c)
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < c; ++j) {
            C[i * c + j] = 0;
            for (int k = 0; k < b; ++k) {
                C[i * c + j] += A[i * b + k] * B[k * c + j];
            }
        }
    }

    end(&timer);
    print_milli_interval(&timer);

//    print_float_matrix(A, a, b, "A");
//    print_float_matrix(B, b, c, "B");
//    print_float_matrix(C, a, c, "C");


    free(mem);
    return 0;
}


