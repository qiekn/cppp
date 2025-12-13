#include <print>
#include <string>
#include <string_view>
#include <vector>

/**
 * @brief Be careful when you use cpp reference
 */
void WrongCase() {
  std::vector<std::string> fruits;

  fruits.push_back("Apple");
  fruits.push_back("Orange");
  fruits.push_back("Plum");
  fruits.push_back("Pear");

  // std::string* first_fruit = &fruits[0];
  std::string_view first_fruit = fruits[0];

  std::println("{}", first_fruit);  // It print `Apple`

  fruits.push_back("GrapeFrust");

  std::println("{}", first_fruit);  // It doesn't print `Apple`
}

void WrontCase_2() {}

int main() {
  WrongCase();

  return 0;
}

/* --------------------------------- output --------------------------------- *
   Apple
   vfYm
 * -------------------------------------------------------------------------- */
