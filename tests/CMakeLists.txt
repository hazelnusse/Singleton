include_directories(${Singleton_SOURCE_DIR}/gtest)
include_directories(${Singleton_SOURCE_DIR}/gtest/include)

# Eigenvalue test-gtest
add_executable(testSingleton testSingleton.cc)
target_link_libraries(testSingleton Singleton gtest_main)

# Add test to testing framework
add_test(NAME testSingleton
         COMMAND testSingleton)
