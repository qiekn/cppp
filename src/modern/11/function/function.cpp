#include <threadpoolapiset.h>
#include <winnt.h>
#include <cmath>
#include <functional>
#include <iostream>

// std::function<ReturnType(Arg1Type, Arg2Type, ...)> function_name;

// ----------------------------------------------------------------------------: Function

namespace case_functon {
float Add(float x, float y) {
  return x + y;
}

std::function<float(float, float)> callback = Add;

void Test() {
  std::cout << "Function: 1.2f + 1.3f = " << callback(1.2f, 1.3f) << '\n';
}
}  // namespace case_functon

// ----------------------------------------------------------------------------: Function Pointer

namespace case_function_pointer {
int Add(int x, int y, int z) {
  return x + y + z;
}

std::function<int(int, int, int)> callback = Add;

void Test() {
  std::cout << "Funtion Pointer: 3 + 4 + 5 = " << callback(3, 4, 5) << '\n';
}
}  // namespace case_function_pointer

// ----------------------------------------------------------------------------: Lambda

namespace case_lambda {
float Pow(float x, float y) {
  return std::pow(x, y);
}

std::function<float(float, float)> callback = Pow;

void Test() {
  std::cout << "Lambda: 2^3 = " << callback(2, 3) << '\n';
}
}  // namespace case_lambda

// ----------------------------------------------------------------------------: Functor

namespace case_functor {
class Multipy {
public:
  int operator()(int x, int y) { return x * y; }
};

std::function<int(int, int)> callback = Multipy{};

void Test() {
  std::cout << "Functor: 2 * 4 = " << callback(2, 4) << '\n';
}
}  // namespace case_functor

// ----------------------------------------------------------------------------: main

int main() {

  case_functon::Test();
  case_function_pointer::Test();
  case_lambda::Test();
  case_functor::Test();
  return 0;
}
