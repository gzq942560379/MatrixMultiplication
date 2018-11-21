add_executable(simple simple.c)
target_link_libraries(simple utils)

add_executable(pre_transpose pre_transpose.c)
target_link_libraries(pre_transpose utils)

add_executable(gemm0 gemm0.c)
target_link_libraries(gemm0 utils)

add_executable(gemm1 gemm1.c)
target_link_libraries(gemm1 utils)

add_executable(gemm_4_1_1 gemm_4_1_1.c)
target_link_libraries(gemm_4_1_1 utils)

add_executable(gemm_4_1_2 gemm_4_1_2.c)
target_link_libraries(gemm_4_1_2 utils)

add_executable(gemm_4_1_3 gemm_4_1_3.c)
target_link_libraries(gemm_4_1_3 utils)

add_executable(gemm_4_1_4 gemm_4_1_4.c)
target_link_libraries(gemm_4_1_4 utils)

add_executable(gemm_4_4_0 gemm_4_4_0.c)
target_link_libraries(gemm_4_4_0 utils)

add_executable(gemm_4_4_1 gemm_4_4_1.c)
target_link_libraries(gemm_4_4_1 utils)

add_executable(gemm_4_4_2 gemm_4_4_2.c)
target_link_libraries(gemm_4_4_2 utils)

add_executable(gemm_blocking_4_4_0 gemm_blocking_4_4_0.c)
target_link_libraries(gemm_blocking_4_4_0 utils)

add_executable(gemm_packing_4_4_0 gemm_packing_4_4_0.c)
target_link_libraries(gemm_packing_4_4_0 utils)

add_executable(gemm_packing_4_4_1 gemm_packing_4_4_1.c)
target_link_libraries(gemm_packing_4_4_1 utils)

add_executable(gemm_packing_4_4_2 gemm_packing_4_4_2.c)
target_link_libraries(gemm_packing_4_4_2 utils)

set(OpenBLAS_DIR /opt/OpenBLAS/lib/cmake/openblas)


add_executable(gemm_openblas gemm_openblas.c)
target_link_libraries(gemm_openblas utils ${OpenBLAS_LIBRARIES})



add_subdirectory(avx)
add_subdirectory(fma)