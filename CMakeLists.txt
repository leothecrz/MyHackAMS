cmake_minimum_required(VERSION 3.0.0)
project(VersionTwoAssembler VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(VersionTwoAssembler Helper.cpp HackCoder.cpp HackParser.cpp main.cpp)
target_include_directories( VersionTwoAssembler
    PRIVATE
    include/
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
