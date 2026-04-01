import math;
#include <iostream>

int main() {
  vec3 a{1, 2, 3};
  vec3 b{4, 5, 6};

  auto c = a + b;
  std::cout << c.x << ", " << c.y << ", " << c.z << '\n';
  std::cout << dot(a, b) << '\n';
}
