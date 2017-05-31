cmake_minimum_required(VERSION 3.6)
project(ft_printf)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

set(SOURCE_FILES libft/libft.h ft_printf.c ft_printf.h vp_treads.c  vp_spec.c vp_spec_extra.c vp_extra_function.c)
add_executable(ft_printf ${SOURCE_FILES})
target_link_libraries(ft_printf ${CMAKE_SOURCE_DIR}/libft/libft.a)