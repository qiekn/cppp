import math;
#include <iostream>
#include <print>

int main() {
  vec3 a{1, 2, 3};
  vec3 b{4, 5, 6};

  auto c = a + b;
  std::println("{}, {}, {}", c.x, c.y, c.z);
  std::println("dot = {}", dot(a, b));
}
