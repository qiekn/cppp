# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Interaction Guidelines

## Interaction Guidelines

- **Response Language**: Chinese. Please use Chinese for all answers, explanations, and conversational text.
- **Code Comments**: English. All comments within code blocks must be strictly in English, maintaining a professional and concise style.


## Repository Overview

This is a C++ practice repository organized by topics and C++ standard versions. The codebase demonstrates modern C++ features with examples organized under `modern/11/`, `modern/17/`, etc. Additional placeholder directories exist for future content: `algorithm/`, `stl/`, `concurrency/`, `effective/`, `primer/`, `advanced/`, and `leetcode/`.

## Build System

The project uses CMake with a unique build configuration:

- **Each `.cpp` file becomes a separate executable** - The CMakeLists.txt recursively finds all `.cpp` files and creates individual executables for each
- **C++20 standard is enabled** for compilation, though examples may demonstrate C++11, C++17, etc.
- **`PROJECT_ROOT_DIR` macro** is automatically defined for all executables, providing the absolute path to the project root at compile time

### Build Commands

Build all executables:
```bash
cmake -S . -B build && cmake --build build -j$(nproc)
```

Build a specific executable (where `<name>` is the `.cpp` filename without extension):
```bash
cd build
cmake ..
make <name> -j$(nproc)
./<name>  # or ./<name>.exe on Windows
```

## Code Style and Quality

### Formatting (.clang-format)
- Based on Google C++ style with customizations
- 100 character line limit
- 2-space indentation
- Left-aligned pointers/references (`int* ptr` not `int *ptr`)
- No short if statements on single line (always use braces)

### Static Analysis (.clang-tidy)
- Google checks enabled with bug-prone and performance checks
- **Warnings are treated as errors**
- Naming conventions enforced:
  - `lower_case` for namespaces, variables, class members
  - `CamelCase` for classes, structs, template parameters
  - `aNy_CasE` for functions (flexible)
  - Class members must have `_` suffix
  - Constants must have `k` prefix and be `CamelCase` (e.g., `kMaxSize`)

## Architecture Patterns

### File Organization
Examples are organized by C++ standard version and feature:
```
modern/
├── 11/
│   └── variadic_templates/    # C++11 variadic template examples
├── 17/
│   ├── optional/              # std::optional examples
│   └── filesystem/            # std::filesystem examples
```

### Main Function Pattern
Each `.cpp` file should contain a `main()` function since each file becomes a standalone executable. Helper functions can be defined in the same file.

### Using PROJECT_ROOT_DIR
When examples need to access project files at runtime, use the `PROJECT_ROOT_DIR` macro:
```cpp
std::string root_dir = PROJECT_ROOT_DIR;
fs::path root_path(root_dir);
```

This macro is automatically defined by CMake as the absolute path to the project root.

## Adding New Examples

When adding new C++ examples:

1. Place the file in the appropriate directory based on the C++ standard version and feature being demonstrated
2. Include a `main()` function - each `.cpp` file becomes a standalone executable
3. Add comments explaining the feature being demonstrated
4. The build system will automatically pick up new `.cpp` files - no CMakeLists.txt modification needed
5. Follow the naming conventions enforced by clang-tidy
6. Run clang-format before committing

## Related Documentation

The author maintains blog notes about C++ at: http://qiekn.notion.site/cpp
