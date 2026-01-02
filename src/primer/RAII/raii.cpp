#include <iostream>

// RAII - Reosurce Acquisition Is Initialization

// clang-format off

class MyClass {
public:
  MyClass() { 
    std::cout << "Acquire resource in constructor.\n";
  }

  ~MyClass() {
    std::cout << "Release resource in constructor.\n";
  }

  void SayHello() {
    std::cout << "Hello.\n";
  }
};

int main() {
  MyClass my_class;
  my_class.SayHello();

  return 0;
}

/* --------------------------------- output --------------------------------- *
   Acquire resource in constructor.
   Hello.
   Release resource in constructor.
 * -------------------------------------------------------------------------- */
