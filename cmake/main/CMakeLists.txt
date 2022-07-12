list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
find_package(Print REQUIRED)

set(Print_INCLUDE_DIR .)
include_directories("${Print_INCLUDE_DIR}")
add_executable(Test main.c)
target_link_libraries(Test ${Print_LIBRARIES})
