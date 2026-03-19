#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <ranges>


int main() {
  const auto keys = {1, 2, 3, 4, 5};

  const auto it_1 = std::ranges::find_if(keys, [](int i) {
    return i == 3;
  });
  const auto it_2 = std::ranges::find_if(keys, [](int x) {
    return x == 6;
  });

  if (it_1 == keys.end()) {
    std::cout << "3 is not here\n";
  }

  if (it_2 == keys.end()) {
    std::cout << "6 is not here\n";
  }

  return 0;
}
