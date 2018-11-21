//
// Created by gzq on 18-10-11.
//

/*
 * compute 4*4 a time  avx
 * 6836
 * 0.48 变慢了 。。。
 */
#include <stdio.h>
#include <stdlib.h>
#include <random_uitls.h>
#include <console_utils.h>
#include <utils.h>
#include <time_utils.h>
#include <string.h>
#include <assert.h>
#include <malloc.h>
#include <immintrin.h>

#define A(i, j) a[(i)*la+j]
#define B(i, j) b[(i)*lb+j]
#define C(i, j) c[(i)*lc+j]

typedef union {
    __m256d v;
    double d[4];
} v4df_t;

void gemm(int m, int k, int n, double *a, double *b, double *c, int la, int lb, int lc);

void AddDot_4_4(int k, double *a, double *b_r_l, double *c, int la, int lb, int lc);

int main(int argc, char **argv) {
    int m, k, n;
    get_mnk(argc, argv, &m, &k, &n);
    assert(k % 4 == 0 && n % 4 == 0);
    double *a = memalign(32, m * k * sizeof(double));
    double *b = memalign(32, k * n * sizeof(double));
    double *c = memalign(32, m * n * sizeof(double));
    random_double_array(a, m * k, 0, 10);
    random_double_array(b, k * n, 0, 10);
    memset(c, 0, m * n * sizeof(double));
    int la = k, lb = n, lc = n;
    timer timer;
    start(&timer);
    gemm(m, k, n, a, b, c, la, lb, lc);
    end(&timer);
    printf("%ld\n", milli_interval(&timer));
    print_milli_interval(&timer);
//    print_double_matrix(a,m,k,"a");
//    print_double_matrix(b,k,n,"b");
//    print_double_matrix(c,m,n,"c");
//    check_error(a, b, c, m, k, n);
    free(a);
    free(b);
    return 0;
}

void gemm(int m, int k, int n, double *a, double *b, double *c, int la, int lb, int lc) {
    for (int i = 0; i < m; i += 4) {
        for (int j = 0; j < n; j += 4) {
            AddDot_4_4(k, &A(i, 0), &B(0, j), &C(i, j), la, lb, lc);
        }
    }
}

void AddDot_4_4(int k, double *a, double *b, double *c, int la, int lb, int lc) {

    v4df_t
            c_r_0, c_r_1, c_r_2, c_r_3,
            a_0l_4, a_1l_4, a_2l_4, a_3l_4,
            t_0, t_1, t_2, t_3,
            b_r_l;
    c_r_0.v = _mm256_setzero_pd();
    c_r_1.v = _mm256_setzero_pd();
    c_r_2.v = _mm256_setzero_pd();
    c_r_3.v = _mm256_setzero_pd();
    for (int l = 0; l < k; ++l) {
        b_r_l.v = _mm256_load_pd(&B(l, 0));

        a_0l_4.v = _mm256_set1_pd(A(0, l));
        a_1l_4.v = _mm256_set1_pd(A(1, l));
        a_2l_4.v = _mm256_set1_pd(A(2, l));
        a_3l_4.v = _mm256_set1_pd(A(3, l));

        t_0.v = _mm256_mul_pd(a_0l_4.v, b_r_l.v);
        t_1.v = _mm256_mul_pd(a_1l_4.v, b_r_l.v);
        t_2.v = _mm256_mul_pd(a_2l_4.v, b_r_l.v);
        t_3.v = _mm256_mul_pd(a_3l_4.v, b_r_l.v);

        c_r_0.v = _mm256_add_pd(t_0.v, c_r_0.v);
        c_r_1.v = _mm256_add_pd(t_1.v, c_r_1.v);
        c_r_2.v = _mm256_add_pd(t_2.v, c_r_2.v);
        c_r_3.v = _mm256_add_pd(t_3.v, c_r_3.v);
    }
    C(0, 0) = c_r_0.d[0], C(0, 1) = c_r_0.d[1], C(0, 2) = c_r_0.d[2], C(0, 3) = c_r_0.d[3];
    C(1, 0) = c_r_1.d[0], C(1, 1) = c_r_1.d[1], C(1, 2) = c_r_1.d[2], C(1, 3) = c_r_1.d[3];
    C(2, 0) = c_r_2.d[0], C(2, 1) = c_r_2.d[1], C(2, 2) = c_r_2.d[2], C(2, 3) = c_r_2.d[3];
    C(3, 0) = c_r_3.d[0], C(3, 1) = c_r_3.d[1], C(3, 2) = c_r_3.d[2], C(3, 3) = c_r_3.d[3];
}

