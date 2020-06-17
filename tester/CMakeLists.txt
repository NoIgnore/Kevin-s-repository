cmake_minimum_required(VERSION 3.10)
project(course_unit_test)

# Support at least c++14
set(CMAKE_CXX_STANDARD 14)

#############################################
# You can also add main function for your own purpose

#set(utils_source utils/md5.cpp utils/md5.h utils/db.cc utils/db.hh)

#add_executable(main_bin
#        ${utils_source}
#        main.cc)
#

#add_executable(main_bin implementation/unit_1.cc)


#############################################
# Unit tests
add_subdirectory(lib/catch2)

# enable CTest testing
enable_testing()

# Add a testing executable
add_executable(unit7_tests test/test_main.cc test/test_unit_7.cc)

set(test_executable unit7_tests)

set(OPENSSL_LIBRARY_OBJ ssl crypto)

foreach (bin IN LISTS test_executable)
    target_link_libraries(${bin} Catch2::Test ${OPENSSL_LIBRARY_OBJ})
endforeach ()

# set test output to cmake_binary_dir
set_target_properties(
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)

add_test(NAME unit_7 COMMAND unit7_tests)
