cmake_minimum_required(VERSION 3.10)
project(get_rdf_from_heif)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_BUILD_TYPE Debug)


# Set the ${HOME_DIR} variable to the user's home directory.
# CMake doesn't expand ~ to the home directory.
execute_process(COMMAND echo $ENV{HOME}
                OUTPUT_VARIABLE HOME_DIR
                OUTPUT_STRIP_TRAILING_WHITESPACE)

###### Include libheif build from source ######
set(LIBHEIF_DIR ${HOME_DIR}/repos/libheif)
set(LIBHEIF_BUILD_DIR ${LIBHEIF_DIR}/out/build/develop)
include_directories(
    ${LIBHEIF_DIR}/libheif/api
    ${LIBHEIF_BUILD_DIR}
    src/
)

add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(get_rdf_from_heif PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(${PROJECT_NAME} PRIVATE -g -O0) # ensure symbols, disable opts for easier stepping

target_link_libraries( ${PROJECT_NAME} 
    ${LIBHEIF_BUILD_DIR}/libheif/libheif.so
)