cmake_minimum_required(VERSION 3.0)
project(fopProject C)
set(CMAKE_C_STANDARD 99)

file(GLOB_RECURSE SOURCE "src/*.c" "src/*.h")
add_executable(fopProject "${SOURCE}" src/view.c src/view.h src/main.c src/structs.h src/physics.c src/physics.h)

include_directories("/usr/include/SDL2")
target_link_libraries(fopProject m SDL2 SDL2_gfx)
