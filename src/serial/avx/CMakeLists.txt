SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mavx")

add_executable(vector_mul_avx vector_mul_avx.c)
target_link_libraries(vector_mul_avx utils)

add_executable(pre_transpose_avx pre_transpose_avx.c)
target_link_libraries(pre_transpose_avx utils)

add_executable(gemm_4_4_3_avx gemm_4_4_3_avx.c)
target_link_libraries(gemm_4_4_3_avx utils)