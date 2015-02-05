option(Singleton_build_tests "Build all of Singleton's tests." OFF)

project(Singleton CXX)
cmake_minimum_required(VERSION 2.8)

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-Wall -std=c++0x")
    set(CMAKE_CXX_FLAGS_DEBUG "-ggdb3 -O0")
    set(CMAKE_CXX_FLAGS_RELEASE "-O2")
endif()

include_directories(${Singleton_SOURCE_DIR})
if (Singleton_build_tests)
  enable_testing()
  add_subdirectory(googletest)
  add_subdirectory(tests)
endif()

install(FILES Singleton.h Singleton_priv.h
        DESTINATION include)
