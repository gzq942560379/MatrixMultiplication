//
// Created by gzq on 18-10-11.
//

/*
 * compute 4*1 a time
 * register
 * 4378
 * 2.53
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


void gemm(int m, int k, int n, const double *a, const double *b, double *c, int la, int lb, int lc);

void AddDot_4_1(int k, const double *a, const double *b, double *c, int la, int lb, int lc);

int main(int argc, char **argv) {
    int m, k, n;
    get_mnk(argc, argv, &m, &k, &n);
    double *mem = malloc((m * k + k * n + m * n) * sizeof(double));
    const double *a = mem, *b = mem + m * k;
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


void gemm(int m, int k, int n, const double *a, const double *b, double *c, int la, int lb, int lc) {
    for (int i = 0; i < m; i += 4) {
        for (int j = 0; j < n; ++j) {
            AddDot_4_1(k, &A(i, 0), &B(0, j), &C(i, j), la, lb, lc);
        }
    }
}

void AddDot_4_1(int k, const double *a, const double *b, double *c, int la, int lb, int lc) {
    register double
            c_0_0_reg, c_1_0_reg, c_2_0_reg, c_3_0_reg,
            b_l_0_reg;
    c_0_0_reg = 0;
    c_1_0_reg = 0;
    c_2_0_reg = 0;
    c_3_0_reg = 0;
    for (int l = 0; l < k; ++l) {
        b_l_0_reg = B(l, 0);
        c_0_0_reg += A(0, l) * b_l_0_reg;
        c_1_0_reg += A(1, l) * b_l_0_reg;
        c_2_0_reg += A(2, l) * b_l_0_reg;
        c_3_0_reg += A(3, l) * b_l_0_reg;
    }
    C(0, 0) += c_0_0_reg;
    C(1, 0) += c_1_0_reg;
    C(2, 0) += c_2_0_reg;
    C(3, 0) += c_3_0_reg;
}

