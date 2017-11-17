cmake_minimum_required(VERSION 3.6)
project(a1cmpt225)

set(CPPFLAGS = -std=c++11 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g)

set(SOURCE_FILES WICPS.cpp Patient.cpp Patient.h List.cpp List.h)
add_executable(a1cmpt225 ${SOURCE_FILES})