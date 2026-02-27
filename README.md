# Cpp Practice

This is my C++ practice codes. See my blog notes at [qiekn.notion.site/cpp](http://qiekn.notion.site/cpp)

## Build

```shell
cmake -S . -B build && cmake --build build -j$(nproc)
```

Or you can compile only the selected file.
```shell
cmake --build build --target <name> -j$(nproc)
./build/<name> # or ./build/<name>.exe
```

## Test

Tests use [GoogleTest](https://github.com/google/googletest) (fetched automatically via CMake FetchContent). Test files live in `test/` and must be named `*_test.cpp`.

```shell
# build and run all tests
cmake --build build -j$(nproc) && ctest --test-dir build --output-on-failure

# build and run a single test
cmake --build build --target <test_name> -j$(nproc)
./build/<test_name>
```

## Neovim

```lua
-- Code Runner
vim.api.nvim_create_user_command("Run", function()
  local ft = vim.bo.filetype

  if ft == "cpp" then
    local exe_name = vim.fn.expand("%:t:r")
    local root = vim.fs.root(0, "CMakeLists.txt")
    local build_dir = root .. "/build"
    local exe_path = build_dir .. "/" .. exe_name

    vim.cmd("!" .. "cmake --build " .. build_dir .. " --target " .. exe_name .. " -j && " .. exe_path)
  elseif ft == "javascript" then
    vim.cmd("!node %:.")
  else
    print("Not support this filetype yet.")
  end
end, {})
```
