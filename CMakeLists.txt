cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")

project(GG)

# Debug mode by default
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

include_directories(./include)

# ========= EXTERNAL LIBRARIES =========
find_package(SDL2 REQUIRED)
find_library(CRITERION_LIBRARY criterion REQUIRED)

# ========= FILES =========
file(GLOB_RECURSE GG_SOURCES "src/*.cc")
file(GLOB_RECURSE GG_TESTS "tests/*.cc")

# ========= EXECUTABLES =========

# Source
add_executable(GG ${GG_SOURCES})
target_link_libraries(GG PRIVATE SDL2::SDL2)

# Test
add_executable(GG_tests ${GG_TESTS})
target_link_libraries(GG_tests PRIVATE ${CRITERION_LIBRARY})

# ========= TARGETS =========

# Generate coverage reports
add_custom_target(coverage
    COMMAND lcov --capture --directory . --output-file coverage.info
    COMMAND genhtml coverage.info --output-directory coverage_report
)

# Compile, run then delete tests
add_custom_target(run_tests
    COMMAND GG_tests
    COMMAND rm GG_tests
)

# Ensure coverage depends on running tests
add_dependencies(coverage run_tests)
