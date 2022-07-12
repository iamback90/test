add_library(print STATIC IMPORTED)
find_library(PRINT_LIBRARY_PATH print HINTS "${CMAKE_CURRENT_LIST_DIR}/../../")
set_target_properties(print PROPERTIES IMPORTED_LOCATION "${PRINT_LIBRARY_PATH}")
