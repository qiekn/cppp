#include <format>
#include <iostream>

int main() {
  std::string string = std::format("Speed is {}, mass is {}, name is {}", 5.5f, 40, "qiekn");
  std::cout << string << '\n';
}
