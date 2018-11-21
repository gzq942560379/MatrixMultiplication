//
// Created by gzq on 18-10-11.
//
#include <stdio.h>
#include <random_uitls.h>
#include <console_utils.h>
#include <utils.h>
#include <time_utils.h>
#include <immintrin.h>
#include <malloc.h>

int main(int argc, char **argv) {
    int a, b, c;
    get_mnk(argc, argv, &a, &b, &c);
    int vb = (b + 7) & ~0x7;
    float *A = memalign(32, a * vb * sizeof(float));
    float *B = malloc(b * c * sizeof(float));
    float *C = malloc(a * c * sizeof(float));
    random_float_array(B, b * c, 0, 10);
    for (int i = 0; i < a; i++) {
        random_float_array(A+i*vb,b,0,10);
        for (int j = b ; j < vb; j++) {
            A[i * vb + j] = 0;
        }
    }
    long time1, time2;
    timer timer;
    start(&timer);
    float *tempB = memalign(32, c * vb * sizeof(float));
    for (int i = 0; i < b; ++i) {
        for (int j = 0; j < c; ++j) {
            tempB[j * vb + i] = B[i * c + j];
        }
    }
    for (int i = 0; i < c; i++) {
        for (int j = b; j < vb; j++) {
            tempB[i * vb + j] = 0;
        }
    }
    end(&timer);
    time1 = milli_interval(&timer);
    print_milli_interval(&timer);
//    print_float_matrix(tempB, c, vb, "tB");
    // avx
    __m256 result_v8, a_v8, b_v8;
    float tempR[8]__attribute__((aligned(32)));
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < c; ++j) {
            result_v8 = _mm256_setzero_ps();
            for (int k = 0; k < vb; k += 8) {
                a_v8 = _mm256_load_ps(A + i * vb + k);
                b_v8 = _mm256_load_ps(tempB + j * vb + k);
                a_v8 = _mm256_mul_ps(a_v8, b_v8);
                result_v8 = _mm256_add_ps(result_v8, a_v8);
            }
            _mm256_store_ps(tempR, result_v8);
            C[i * c + j] = tempR[0] + tempR[1] + tempR[2] + tempR[3] + tempR[4] + tempR[5] + tempR[6] + tempR[7];
        }
    }
    free(tempB);
    end(&timer);
    time2 = milli_interval(&timer);
    print_milli_interval(&timer);
    printf("rate : %lf\n", (double) time1 / time2);
//    print_float_matrix(A, a, vb, "A");
//    print_float_matrix(B, b, c, "B");
//    print_float_matrix(C, a, c, "C");
    free(A);
    free(B);
    free(C);
    return 0;
}


