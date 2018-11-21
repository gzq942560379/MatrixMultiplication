//
// Created by gzq on 18-10-21.
//

#include <console_utils.h>
#include <stdio.h>
#include <random_uitls.h>
#include <immintrin.h>
#include <malloc.h>
#include <time_utils.h>

//2500477
int main(int argc, char **argv) {
    int len = 100000000;
    float *A = memalign(32, len * sizeof(float));
    float *B = memalign(32, len * sizeof(float));
    random_float_array(A, len, 0, 10);
    random_float_array(B, len, 0, 10);

    float result = 0;
    __m256 result_v8, a_v8, b_v8;

    timer timer;
    start(&timer);
    result_v8 = _mm256_setzero_ps();
    int vl = len - 8, i = 0;
    for (i = 0; i < vl; i += 8) {
        a_v8 = _mm256_load_ps(A + i);
        b_v8 = _mm256_load_ps(B + i);
        result_v8 = _mm256_fmadd_ps(a_v8,b_v8,result_v8);
    }
    float tempR[8]__attribute__((aligned(32)));
    _mm256_store_ps(tempR, result_v8);
    result = tempR[0] + tempR[1] + tempR[2] + tempR[3] + tempR[4] + tempR[5] + tempR[6] + tempR[7];
    for (; i < len; ++i) {
        result += A[i] * B[i];
    }
    end(&timer);
    print_milli_interval(&timer);
    printf("result : %f\n", result);


    start(&timer);
    float result1 = 0;
    for (int i = 0; i < len; ++i) {
        result1 += A[i] * B[i];
    }
    end(&timer);
    print_milli_interval(&timer);
    printf("result : %f\n", result1);

    printf("diff : %f \n", result - result1 > 0 ? result - result1 : result1 - result);

    free(A);
    free(B);
    return 0;
}


