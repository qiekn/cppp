#include <bitset>
#include <iostream>

void Print() {}

template <typename T, typename... Types>
void Print(const T& first_arg, const Types&... args) {
  std::cout << first_arg << std::endl;
  Print(args...);
}

int main() {
  Print(7.5, "hello", std::bitset<16>(377), 42);
  return 0;
}

/* --------------------------------- output --------------------------------- *
   7.5
   hello
   0000000101111001
   42
 * -------------------------------------------------------------------------- */
