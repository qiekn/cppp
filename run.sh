#!/bin/bash

if [ -z "$1" ]; then
  echo "Usage: ./run.sh <target_name> [args...]"
  return 1
fi

target=$1
build_dir="build" # Adjust this if your build folder is different

# Determine number of CPU cores for parallel build
# 'nproc' works on Linux/Windows(Git Bash), 'sysctl' for macOS.
if command -v nproc > /dev/null; then
  jobs=$(nproc)
elif [ "$(uname)" == "Darwin" ]; then
  jobs=$(sysctl -n hw.ncpu)
else
  jobs=2 # Fallback default
fi

# Compile
echo "🔨 Building $target with $jobs cores..."
cmake --build "$build_dir" --target "$target" -j "$jobs"


# Run if build succeeded
if [ $? -eq 0 ]; then
  echo "🚀 Running $target..."
  echo "----------------------------------------"

  shift # Remove target name from arguments
  exe_path="./$build_dir/$target"

  # In Windowds add .exe extension
  if [ ! -f "$exe_path" ] && [ -f "${exe_path}.exe" ]; then
    exe_path="${exe_path}.exe"
  fi

  # Check if executable exists before running
  if [ -f "$exe_path" ]; then
    "$exe_path" "$@"
  else
    echo "❌ Error: Executable not found at: $exe_path"
    echo "   (Make sure CMAKE_RUNTIME_OUTPUT_DIRECTORY is set to bin)"
    exit 1
  fi
else
  echo "❌ Build failed."
fi
