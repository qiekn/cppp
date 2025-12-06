# Cpp Practice

This is my C++ practice codes. See my blog notes at [qiekn.notion.site/cpp](http://qiekn.notion.site/cpp)

## Build

```shell
cmake -S . -B build && cmake --build -j$(nproc)
```

Or you can compile only the selected file.
```shell
mkdir build && cd build
make <name> -j$(nproc)
./<name> # or ./<name>.exe
```
