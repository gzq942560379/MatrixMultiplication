//
// Created by gzq on 18-10-11.
//

/*
 * compute 4*4 a time  register
 * 3314
 * 2.65
 */
#include <stdio.h>
#include <stdlib.h>
#include <random_uitls.h>
#include <console_utils.h>
#include <utils.h>
#include <time_utils.h>
#include <string.h>

#define A(i, j) a[(i)*la+j]
#define B(i, j) b[(i)*lb+j]
#define C(i, j) c[(i)*lc+j]


void gemm(int m, int k, int n, double *a, double *b, double *c, int la, int lb, int lc);

void AddDot_4_4(int k, double *a, double *b_r_l, double *c, int la, int lb, int lc);

int main(int argc, char **argv) {
    int m, k, n;
    get_mnk(argc, argv, &m, &k, &n);
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
    for (int i = 0; i < m; i += 4) {
        for (int j = 0; j < n; j += 4) {
            AddDot_4_4(k, &A(i, 0), &B(0, j), &C(i, j), la, lb, lc);
        }
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

    for (int l = 0; l < k; ++l) {
        b_l0_reg = B(l, 0);
        b_l1_reg = B(l, 1);
        b_l2_reg = B(l, 2);
        b_l3_reg = B(l, 3);
        a_0l_reg = A(0, l);
        a_1l_reg = A(1, l);
        a_2l_reg = A(2, l);
        a_3l_reg = A(3, l);

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

    C(0, 0) = c_00_reg, C(0, 1) = c_01_reg, C(0, 2) = c_02_reg, C(0, 3) = c_03_reg;
    C(1, 0) = c_10_reg, C(1, 1) = c_11_reg, C(1, 2) = c_12_reg, C(1, 3) = c_13_reg;
    C(2, 0) = c_20_reg, C(2, 1) = c_21_reg, C(2, 2) = c_22_reg, C(2, 3) = c_23_reg;
    C(3, 0) = c_30_reg, C(3, 1) = c_31_reg, C(3, 2) = c_32_reg, C(3, 3) = c_33_reg;
}

