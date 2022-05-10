cmake_minimum_required(VERSION 2.8.12)

project(UniBot)

set(CMAKE_BUILD_TYPE Release)

set(CMAKE_C_FLAGS "-std=c99 -fdump-rtl-expand")

set(SOURCE_FILES
  knowledgebase.h
  knowledgebase.c
  stringhandling.h
  stringhandling.c
)

add_executable(UniBot main.c main.h ${SOURCE_FILES})

add_executable(unit_tests unit_tests.c unity.c ${SOURCE_FILES})
