#include <functional>
#include <iostream>

// clang-format off

void f(int& a, int& b, const int& c) {
  std::cout << "In function: " << a << ' ' << b << ' ' << c << '\n';
  ++a;  // increments the copy of a stored in the function object
  ++b;  // increments the main()'s b
//++c;  // compile error
}

int main() {
  int a = 1, b = 2, c = 3;
  std::function<void()> bound_f = std::bind(f, a, std::ref(b), std::cref(c));

  a = 11, b = 12, c = 13;
  std::cout << "Before function: " << a << ' ' << b << ' ' << c << '\n';

  // a is value copy      1
  // b is reference       2 -> 12
  // c is const reference 3 -> 13
  bound_f();

  // b will be changed after runing bound_f()
  std::cout << "After function: " << a << ' ' << b << ' ' << c << '\n';
}

/* --------------------------------- output --------------------------------- *
   Before function: 11 12 13
   In function: 1 12 13
   After function: 11 13 13
 * -------------------------------------------------------------------------- */
