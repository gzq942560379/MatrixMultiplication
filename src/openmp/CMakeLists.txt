find_package(OpenMP)
if (OPENMP_FOUND)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif ()

add_executable(row_openmp row_openmp.c)
target_link_libraries(row_openmp utils)

add_executable(gemm_packing_4_4_openmp_0 gemm_packing_4_4_openmp_0.c)
target_link_libraries(gemm_packing_4_4_openmp_0 utils)

add_executable(gemm_packing_4_4_openmp_1 gemm_packing_4_4_openmp_1.c)
target_link_libraries(gemm_packing_4_4_openmp_1 utils)


