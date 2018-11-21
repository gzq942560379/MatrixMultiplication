//
// Created by gzq on 18-10-26.
//

#include <cblas.h>
#include <stdio.h>
#include <utils.h>
#include <stdlib.h>
#include <random_uitls.h>
#include <string.h>
#include <time_utils.h>

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

    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, m, n, k, 1, a, la, b, lb, 0, c, lc);

    end(&timer);
    printf("%ld\n", milli_interval(&timer));
    print_milli_interval(&timer);
//    print_double_matrix(a,m,k,"a");
//    print_double_matrix(b,k,n,"b");
//    print_double_matrix(c,m,n,"a");
//    check_error(a, b, c, m, k, n);

    free(mem);
    return 0;
}