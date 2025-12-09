#include <functional>
#include <iostream>

// Bare function pointer
int (*functin_ptr)(int);

// std::function wrapper
std::function<int(int)> callback;

// Actual function definition
int function_a(int x) {
  return x;
}

int main(int argc, char* argv[]) {
  functin_ptr = function_a;
  std::cout << "bare function ptr: " << functin_ptr(10) << '\n';

  callback = function_a;
  std::cout << "std::function wrap function ptr: " << callback(10) << '\n';

  callback = functin_ptr;
  std::cout << "std::function wrap function: " << callback(10) << '\n';

  return 0;
}
