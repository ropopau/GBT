cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SOURCE_FLAGS -Wall -Wextra -Wpedantic -Werror)
set(TEST_FLAGS -Wall -Wpedantic -Werror --coverage)  # Add coverage only for tests

project(GG)

# Debug mode by default
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

include_directories(./include)

# ========= EXTERNAL LIBRARIES =========
find_package(SDL2 REQUIRED)
find_library(CRITERION_LIBRARY NAMES criterion REQUIRED)
find_path(CRITERION_INCLUDE_DIR NAMES criterion/criterion.h REQUIRED)

# ========= FILES =========
file(GLOB_RECURSE GG_SOURCES "src/*.cc")
file(GLOB_RECURSE GG_SOURCES_CPU "src/cpu/*.cc")
file(GLOB_RECURSE GG_TESTS "tests/*.cc")

# ========= EXECUTABLES =========

# Source
add_executable(GG ${GG_SOURCES})
target_link_libraries(GG PRIVATE SDL2::SDL2)
target_compile_options(GG PRIVATE ${SOURCE_FLAGS})

# Test cpu model
add_executable(tests_cpu ${GG_TESTS} ${GG_SOURCES_CPU})
target_include_directories(tests_cpu PRIVATE ${CRITERION_INCLUDE_DIR})
target_link_libraries(tests_cpu PRIVATE ${CRITERION_LIBRARY})
target_compile_options(tests_cpu PRIVATE ${TEST_FLAGS})
target_link_options(tests_cpu PRIVATE ${TEST_FLAGS})

# ========= TARGETS =========

add_custom_target(run_clean
    COMMAND rm -fr CMakeFiles cmake_install.cmake CMakeCache.txt GG tests_cpu Makefile coverage.info coverage_report
)

# Generate coverage reports
add_custom_target(coverage
    COMMAND lcov --capture --directory . --output-file coverage.info
    COMMAND genhtml coverage.info --output-directory coverage_report
)

# Compile, run then delete tests
add_custom_target(run_tests
    COMMAND tests_cpu
    COMMAND rm tests_cpu
)

