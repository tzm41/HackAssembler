cmake_minimum_required(VERSION 3.3)
project(HackAssembler)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Assembler.cpp Parser.cpp Parser.h Code.cpp Code.h SymbolTable.cpp SymbolTable.h)
add_executable(HackAssembler ${SOURCE_FILES})