cmake_minimum_required(VERSION 3.4)
project(fiberpass)

set(LLVM_HOME /home/happy/Source/build_llvm )

#if (NOT DEFINED ENV{LLVM_HOME})
#    message(FATAL_ERROR "$LLVM_HOME is not defined")
#endif ()
#if (NOT DEFINED ENV{LLVM_DIR})
#    set(ENV{LLVM_DIR} $ENV{LLVM_HOME}/lib/cmake/llvm)
#endif ()

set(LLVM_DIR ${LLVM_HOME}/lib/cmake/llvm)

MESSAGE( STATUS "LLVM_HOME = ${LLVM_HOME}")
MESSAGE( STATUS "LLVM_DIR = ${LLVM_DIR}")

find_package(LLVM REQUIRED CONFIG)
add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_INCLUDE_DIRS})
link_directories(${LLVM_LIBRARY_DIRS})
MESSAGE(${LLVM_LIBRARY_DIRS})
MESSAGE(${LLVM_INCLUDE_DIRS})

add_subdirectory(src)  # Use your pass name here.
#MESSAGE(${PROJECT_SOURCE_DIR})
#set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/build)

