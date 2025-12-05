cmake_minimum_required(VERSION 3.15)

project(main)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# -----------------------------------------------------------------------------: Dependences

# -----------------------------------------------------------------------------: Targets

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS "*.cpp")   # source files

foreach(src ${SOURCE_FILES})
  get_filename_component(name ${src} NAME_WE) # without extension
  add_executable(${name} ${src})
endforeach()
