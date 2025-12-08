#include <exception>
#include <iostream>
#include <stdexcept>

namespace ck {
void printf(const char* s) {
  while (*s) {
    if (*s == '%' && *(++s) != '%') {
      throw std::runtime_error("invalid format string: missing argument");
    }
    std::cout << *s++;
  }
}

template <typename T, typename... Args>
void printf(const char* s, T value, Args... args) {
  while (*s) {
    if (*s == '%' && *(++s) != '%') {
      std::cout << value;
      printf(++s, args...);
      return;
    }
    std::cout << *s++;
  }
  throw std::logic_error("extra arguments provided to printf");
}
}  // namespace ck

int main() {
  int* pi = new int;

  try {
    ck::printf("%d %s %p %f\n", 15, "Check this out", pi, 3.1415926535);
    // ck::printf("Extra Args: %d\n", 1, 2);    // Extra args logic error
    // ck::printf("Missing Args: %d %d\n", 1);  // Missing args runtime error
    delete pi;
  } catch (const std::exception& e) {
    std::cerr << "Error caught in main: " << e.what() << '\n';
    return 1;
  }

  return 0;
}

/* --------------------------------- output ---------------------------------
   15 this is Ace. 000002234f1c4ea0 3.141593
   -------------------------------------------------------------------------- */
