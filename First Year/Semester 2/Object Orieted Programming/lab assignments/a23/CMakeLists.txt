cmake_minimum_required(VERSION 3.24)
project(a2_clion_well C)

set(CMAKE_C_STANDARD 11)

add_executable(a2_clion_well main.c Domain.h Domain.c Repository.h Repository.c Services.h Services.c Ui.c)
