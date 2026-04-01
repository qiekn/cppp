cmake_minimum_required(VERSION 3.30)

project(main LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# -----------------------------------------------------------------------------: Dependences

# -----------------------------------------------------------------------------: Targets

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS "src/*.cpp")
file(GLOB_RECURSE MODULE_FILES CONFIGURE_DEPENDS "src/*.cppm")

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
  PRIVATE
    ${SOURCE_FILES}
  PRIVATE
    FILE_SET CXX_MODULES FILES
      ${MODULE_FILES}
)

target_include_directories(${PROJECT_NAME} PRIVATE
  include
)

# cmake -S . -B build -G Ninja -DCMAKE_CXX_COMPILER=clang++
# cmake --build build
