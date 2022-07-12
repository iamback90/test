cmake_minimum_required(VERSION 2.8)
project(Print)

add_library(Print Print.hpp Print.cpp)
install(FILES Print.h DESTINATION include)
install(TARGETS print DESTINATION lib)
install(FILES PrintConfig.cmake DESTINATION lib/cmake/Print)
