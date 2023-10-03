cmake_minimum_required(VERSION 3.0.0)
project(MyHackAsm VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(MyHackAsm HackInToBin.cpp HackParser.cpp main.cpp)

target_include_directories( MyHackAsm
    PRIVATE
    include/
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
