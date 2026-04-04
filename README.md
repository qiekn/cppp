# Cpp Modules

```bash
cmake -S . -B build -G Ninja \
    -DCMAKE_CXX_COMPILER=clang++ \
    -DCMAKE_CXX_FLAGS_INIT="-stdlib=libc++"
cmake --build build
./build/main
```
