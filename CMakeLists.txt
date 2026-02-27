cmake_minimum_required(VERSION 3.15)

project(main)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Use LLVM C++ STL Implementation
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")

# -----------------------------------------------------------------------------: Dependences

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.15.2
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# -----------------------------------------------------------------------------: Targets

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/src/*.cpp")

foreach(src ${SOURCE_FILES})
  get_filename_component(name ${src} NAME_WE) # without extension
  add_executable(${name} ${src})
  target_compile_definitions(${name} PRIVATE PROJECT_ROOT_DIR="${CMAKE_SOURCE_DIR}")
endforeach()

# -----------------------------------------------------------------------------: Tests

enable_testing()

file(GLOB_RECURSE TEST_FILES CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/test/*_test.cpp")

foreach(test_src ${TEST_FILES})
  get_filename_component(test_name ${test_src} NAME_WE)
  add_executable(${test_name} ${test_src})
  target_compile_definitions(${test_name} PRIVATE PROJECT_ROOT_DIR="${CMAKE_SOURCE_DIR}")
  target_include_directories(${test_name} PRIVATE "${PROJECT_SOURCE_DIR}/src")
  target_link_libraries(${test_name} PRIVATE GTest::gtest_main)
  add_test(NAME ${test_name} COMMAND $<TARGET_FILE:${test_name}>)
  set_tests_properties(${test_name} PROPERTIES
    ENVIRONMENT "PATH=C:\\msys64\\ucrt64\\bin\;$ENV{PATH}")
endforeach()
