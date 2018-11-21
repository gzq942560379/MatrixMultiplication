#ifndef console_utils_h
#define console_utils_h

void println();

void print_int_array(const int *arr,const  int len,const  char *arrar_name);

void print_float_array(const float *arr,const  int len,const  char *arrar_name);

void print_float_matrix(const float *arr,const  int row,const  int col,const char *matrix_name);

void print_double_array(const double *arr,const  int len,const  char *arrar_name);

void print_double_matrix(const double *arr,const  int row,const  int col,const  char *matrix_name);

#endif  // console_utils_h