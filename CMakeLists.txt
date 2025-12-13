cmake_minimum_required(VERSION 3.15)

project(main)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Use LLVM C++ STL Implementation
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")

# -----------------------------------------------------------------------------: Dependences

# -----------------------------------------------------------------------------: Targets

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/src/*.cpp")

foreach(src ${SOURCE_FILES})
  get_filename_component(name ${src} NAME_WE) # without extension
  add_executable(${name} ${src})
  target_compile_definitions(${name} PRIVATE PROJECT_ROOT_DIR="${CMAKE_SOURCE_DIR}")
endforeach()
