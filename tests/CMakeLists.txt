include_directories(${Singleton_SOURCE_DIR}/googletest)
include_directories(${Singleton_SOURCE_DIR}/googletest/include)

# Eigenvalue test-gtest
add_executable(testSingleton testSingleton.cc)
target_link_libraries(testSingleton gtest_main)

# Add test to testing framework
add_test(NAME testSingleton
         COMMAND testSingleton)
