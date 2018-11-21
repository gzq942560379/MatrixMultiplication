#include "console_utils.h"
#include <stdio.h>
#include <console_utils.h>


void println() { printf("\n"); }

void print_int_array(const int* arr,const  int len,const  char* arrar_name) {
  if (arrar_name != NULL) {
    printf("%s : \n", arrar_name);
  }
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  println();
}

void print_double_array(const double* arr,const  int len,const  char* arrar_name) {
  if (arrar_name != NULL) {
    printf("%s : \n", arrar_name);
  }
  for (int i = 0; i < len; i++) {
    printf("%lf ", arr[i]);
  }
  println();
}

void print_double_matrix(const double* arr,const  int row,const  int col, const char* matrix_name) {
  if (matrix_name != NULL) {
    printf("%s : \n", matrix_name);
  }
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      printf("%lf ", arr[i * col + j]);
    }
    println();
  }
}

void print_float_array(const float *arr, const int len, const char *arrar_name) {
  if (arrar_name != NULL) {
    printf("%s : \n", arrar_name);
  }
  for (int i = 0; i < len; i++) {
    printf("%f ", arr[i]);
  }
  println();
}

void print_float_matrix(const float *arr,const  int row,const  int col,const  char *matrix_name){
  if (matrix_name != NULL) {
    printf("%s : \n", matrix_name);
  }
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      printf("%f ", arr[i * col + j]);
    }
    println();
  }
}
