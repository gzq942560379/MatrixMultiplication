SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mfma")

add_executable(vector_mul_fma vector_mul_fma.c)
target_link_libraries(vector_mul_fma utils)

add_executable(gemm_4_4_3 gemm_4_4_3_fma.c)
target_link_libraries(gemm_4_4_3 utils)