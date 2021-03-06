//
// Created by gzq on 18-10-11.
//

/*
 * packing openmp 实现
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <random_uitls.h>
#include <console_utils.h>
#include <utils.h>
#include <time_utils.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

#define A(i, j) a[(i)*la+j]
#define B(i, j) b[(i)*lb+j]
#define C(i, j) c[(i)*lc+j]

#define min(a, b) (a)<(b)?(a):(b)

/* Block sizes */
#define ARB 256
#define ACB 32

int thread_count;

void gemm(int m, int k, int n, double *a, double *b, double *c, int la, int lb, int lc);

void AddDot_4_4(int k, double *a, double *b_r_l, double *c, int la, int lb, int lc);

void InnerKernel(int m, int k, int n, double *a, double *b, double *c, int la, int lb, int lc);

void PackMatrixA(int k, double *a, int la, double *a_to);

void PackMatrixB(int k, double *b, int lb, double *b_to);

int main(int argc, char **argv) {
    int m, k, n;
    get_mnk_threadcount(argc, argv, &m, &k, &n, &thread_count);
    double *mem = malloc((m * k + k * n + m * n) * sizeof(double));
    double *a = mem, *b = mem + m * k;
    double *c = mem + m * k + k * n;
    random_double_array(mem, m * k + k * n, 0, 10);
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

    free(mem);
    return 0;
}

void gemm(int m, int k, int n, double *a, double *b, double *c, int la, int lb, int lc) {
    int arb, acb;
    for (int i = 0; i < m; i += ARB) {
        arb = min(m - i, ARB);
        for (int j = 0; j < k; j += ACB) {
            acb = min(k - j, ACB);
            InnerKernel(arb, acb, n, &A(i, j), &B(j, 0), &C(i, 0), la, lb, lc);
        }
    }
}

typedef struct {
    double *a;
    double *b;
    double *c;
    int m;
    int n;
    int k;
    int la;
    int lb;
    int lc;
    int rank;
} pthread_param;

void parallel_kernel(pthread_param *param) {
    int rank = param->rank;
    int m = param->m;
    int k = param->k;
    int n = param->n;
    double *a = param->a;
    double *b = param->b;
    double *c = param->c;
    int la = param->la;
    int lb = param->lb;
    int lc = param->lc;
    assert(m % 4 == 0 && n % 4 == 0);
    int rr = m >> 2, cc = n >> 2;
    int local_low = CROSS_BLOCK_LOW(rank, thread_count, rr);
    int local_high = CROSS_BLOCK_HIGH(rank, thread_count, rr);
    int local_size = CROSS_BLOCK_SIZE(rank, thread_count, rr);
    double packedA[((local_size) << 2) * k], packedB[k * n];
    int start_i = local_low << 2, end_i = local_high << 2;
    for (int i = start_i; i <= end_i; i += 4) {
        PackMatrixA(k, &A(i, 0), la, &packedA[(i - start_i) * k]);
        for (int j = 0; j < n; j += 4) {
            if (i == start_i) PackMatrixB(k, &B(0, j), lb, &packedB[k * j]);
            AddDot_4_4(k, &packedA[(i - start_i) * k], &packedB[k * j], &C(i, j), la, lb, lc);
        }
    }
}

void InnerKernel(int m, int k, int n, double *a, double *b, double *c, int la, int lb, int lc) {
    pthread_t *threads = malloc(thread_count * sizeof(pthread_t));
    pthread_param *params = malloc(thread_count * sizeof(pthread_param));
    for (int i = 0; i < thread_count; i++) {
        params[i].rank = i;
        params[i].a = a;
        params[i].b = b;
        params[i].c = c;
        params[i].m = m;
        params[i].n = n;
        params[i].k = k;
        params[i].la = la;
        params[i].lb = lb;
        params[i].lc = lc;
        pthread_create(&threads[i], NULL, parallel_kernel, &params[i]);
    }
    for (int i = 0; i < thread_count; ++i) {
        pthread_join(threads[i], NULL);
    }
    free(threads);
    free(params);
}

void PackMatrixB(int k, double *b, int lb, double *b_to) {
    double *b_ptr;
    for (int i = 0; i < k; ++i) {
        b_ptr = &B(i, 0);
        *b_to++ = *b_ptr;
        *b_to++ = *(b_ptr + 1);
        *b_to++ = *(b_ptr + 2);
        *b_to++ = *(b_ptr + 3);
    }
}

void PackMatrixA(int k, double *a, int la, double *a_to) {
    double *a_0l_ptr, *a_1l_ptr, *a_2l_ptr, *a_3l_ptr;
    a_0l_ptr = &A(0, 0);
    a_1l_ptr = &A(1, 0);
    a_2l_ptr = &A(2, 0);
    a_3l_ptr = &A(3, 0);

    for (int j = 0; j < k; ++j) {
        *a_to++ = *a_0l_ptr++;
        *a_to++ = *a_1l_ptr++;
        *a_to++ = *a_2l_ptr++;
        *a_to++ = *a_3l_ptr++;
    }
}

void AddDot_4_4(int k, double *a, double *b, double *c, int la, int lb, int lc) {
    register double
            c_00_reg, c_01_reg, c_02_reg, c_03_reg,
            c_10_reg, c_11_reg, c_12_reg, c_13_reg,
            c_20_reg, c_21_reg, c_22_reg, c_23_reg,
            c_30_reg, c_31_reg, c_32_reg, c_33_reg,
            b_l0_reg,
            b_l1_reg,
            b_l2_reg,
            b_l3_reg,
            a_0l_reg,
            a_1l_reg,
            a_2l_reg,
            a_3l_reg;

    c_00_reg = 0.0, c_01_reg = 0.0, c_02_reg = 0.0, c_03_reg = 0.0;
    c_10_reg = 0.0, c_11_reg = 0.0, c_12_reg = 0.0, c_13_reg = 0.0;
    c_20_reg = 0.0, c_21_reg = 0.0, c_22_reg = 0.0, c_23_reg = 0.0;
    c_30_reg = 0.0, c_31_reg = 0.0, c_32_reg = 0.0, c_33_reg = 0.0;

    double *a_ptr = a;
    double *b_ptr = b;
    for (int l = 0; l < k; ++l) {
        b_l0_reg = *b_ptr;
        b_l1_reg = *(b_ptr + 1);
        b_l2_reg = *(b_ptr + 2);
        b_l3_reg = *(b_ptr + 3);
        b_ptr += 4;

        a_0l_reg = *a_ptr;
        a_1l_reg = *(a_ptr + 1);
        a_2l_reg = *(a_ptr + 2);
        a_3l_reg = *(a_ptr + 3);
        a_ptr += 4;

        c_00_reg += a_0l_reg * b_l0_reg;
        c_01_reg += a_0l_reg * b_l1_reg;
        c_02_reg += a_0l_reg * b_l2_reg;
        c_03_reg += a_0l_reg * b_l3_reg;

        c_10_reg += a_1l_reg * b_l0_reg;
        c_11_reg += a_1l_reg * b_l1_reg;
        c_12_reg += a_1l_reg * b_l2_reg;
        c_13_reg += a_1l_reg * b_l3_reg;

        c_20_reg += a_2l_reg * b_l0_reg;
        c_21_reg += a_2l_reg * b_l1_reg;
        c_22_reg += a_2l_reg * b_l2_reg;
        c_23_reg += a_2l_reg * b_l3_reg;

        c_30_reg += a_3l_reg * b_l0_reg;
        c_31_reg += a_3l_reg * b_l1_reg;
        c_32_reg += a_3l_reg * b_l2_reg;
        c_33_reg += a_3l_reg * b_l3_reg;
    }

    C(0, 0) += c_00_reg, C(0, 1) += c_01_reg, C(0, 2) += c_02_reg, C(0, 3) += c_03_reg;
    C(1, 0) += c_10_reg, C(1, 1) += c_11_reg, C(1, 2) += c_12_reg, C(1, 3) += c_13_reg;
    C(2, 0) += c_20_reg, C(2, 1) += c_21_reg, C(2, 2) += c_22_reg, C(2, 3) += c_23_reg;
    C(3, 0) += c_30_reg, C(3, 1) += c_31_reg, C(3, 2) += c_32_reg, C(3, 3) += c_33_reg;
}