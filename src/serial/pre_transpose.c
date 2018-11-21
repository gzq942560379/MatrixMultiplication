//
// Created by gzq on 18-10-11.
//
#include <stdio.h>
#include <stdlib.h>
#include <random_uitls.h>
#include <console_utils.h>
#include <utils.h>
#include <time_utils.h>


int main(int argc, char **argv) {
    int a, b, c;
    get_mnk(argc, argv, &a, &b, &c);

    timer timer;

    double *mem = malloc((a * b + b * c + a * c) * sizeof(double));
    const double *A = mem, *B = mem + a * b;
    double *C = mem + a * b + b * c;
    random_double_array(mem, a * b + b * c, 0, 10);

    start(&timer);
    double *tempB = malloc(c * b * sizeof(double));
    for (int i = 0; i < b; ++i) {
        for (int j = 0; j < c; ++j) {
            tempB[j * b + i] = B[i * c + j];
        }
    }
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < c; ++j) {
            C[i * c + j] = 0;
            for (int k = 0; k < b; ++k) {
                C[i * c + j] += A[i * b + k] * tempB[j * b + k];
            }
        }
    }
    free(tempB);
    end(&timer);
    printf("%ld\n", milli_interval(&timer));

//    print_milli_interval(&timer);
//    printf("rate : %lf\n", (double) time1 / time2);


//    check_error(A, B, C, a, b, c);
    free(mem);
    return 0;
}


