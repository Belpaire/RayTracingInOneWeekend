# CMakeList.txt : CMake project for RaytracingOneWeekend, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (RaytracingOneWeekend "RaytracingOneWeekend.cpp" "RaytracingOneWeekend.h" "ray.h")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
target_compile_options(RaytracingOneWeekend PRIVATE -Wall -Wextra -Wno-c++98-compat)
# TODO: Add tests and install targets if needed.
