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
//    int a, b, c;
//    get_mnk(argc, argv, &a, &b, &c);
//
//    float *mem = malloc((a * b + b * c + a * c) * sizeof(float));
//    const float *A = mem, *B = mem + a * b;
//    float *C = mem + a * b + b * c;
//    random_float_array(mem, a * b + b * c, 0, 10);
//
//    timer timer;
//    start(&timer);
//    for (int i = 0; i < a; ++i) {
//        for (int j = 0; j < c; ++j) {
//            C[i * c + j] = 0;
//            for (int k = 0; k < b; ++k) {
//                C[i * c + j] += A[i * b + k] * B[k * c + j];
//            }
//        }
//    }
//    end(&timer);
//    printf("%ld\n", milli_interval(&timer));
//    print_milli_interval(&timer);
    for (int i = 200; i <= 1500; i += 20) {
        printf("%d %d %d\n", i, i, i);
    }
    return 0;
}
/*


 */