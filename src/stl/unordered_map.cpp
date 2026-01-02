#include <iostream>
#include <print>
#include <string>
#include <unordered_map>

// clang-format off


/**
 * @brief Be careful when you check if some key exists in map
 */
void TestCase_1() {
  std::unordered_map<std::string, bool> map;

  // Look like a simple existence check but actually modifies the map.
  if (map["test"]) {
    std::cout << "key: test founded!\n";
  }

  // Suprise! "test" was inserted with a default value.
  map.size(); // = 1

  map.clear();

  // Using find() correctly avoids insertion.
  if (map.find("test") != map.end()) {
    std::cout << "key: test founded!\n";
  }

  map.size(); // = 0 (on insertion  occurred)
}

/**
 * @brief Be careful when you insert pairs
 */
void TestCase_2() {
  std::unordered_map<int, int> map;
  map.insert({1, 1});
  map.insert({1, 1000}); // The second insert is failed.
  std::println("{}", map.at(1)); // Prints 1 (not 1000)

  // Verbose pattern needed for conditional upates.
  auto result = map.insert({1, 1000});
  if (!result.second) { // If insertion failed (key existed)
    // Update the existing value
    result.first->second = 1000;
  }

  // Or alternatively.
  if (map.find(1) != map.end()) {
    map[1] = 1000; // Update
  } else {
    map[1] = 1000; // Insert
  }

  // New way to overwrite value. (Since c++17)
  map.insert_or_assign(1, 1);
  map.insert_or_assign(1, 1000);
}

int main() {
  TestCase_1();
  TestCase_2();
}

