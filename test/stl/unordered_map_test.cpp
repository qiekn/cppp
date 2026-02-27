#include <gtest/gtest.h>

#include <string>
#include <unordered_map>

// operator[] silently inserts a default value for missing keys
TEST(UnorderedMapTest, BracketOperatorInsertsDefault) {
  std::unordered_map<std::string, bool> map;
  EXPECT_EQ(map.size(), 0);

  bool value = map["test"];
  EXPECT_FALSE(value);
  EXPECT_EQ(map.size(), 1);
}

// find() does NOT insert missing keys
TEST(UnorderedMapTest, FindDoesNotInsert) {
  std::unordered_map<std::string, bool> map;

  auto it = map.find("test");
  EXPECT_EQ(it, map.end());
  EXPECT_EQ(map.size(), 0);
}

// insert() does not overwrite existing keys
TEST(UnorderedMapTest, InsertDoesNotOverwrite) {
  std::unordered_map<int, int> map;
  map.insert({1, 1});
  map.insert({1, 1000});
  EXPECT_EQ(map.at(1), 1);
}

// insert_or_assign() overwrites existing keys (C++17)
TEST(UnorderedMapTest, InsertOrAssignOverwrites) {
  std::unordered_map<int, int> map;
  map.insert_or_assign(1, 1);
  map.insert_or_assign(1, 1000);
  EXPECT_EQ(map.at(1), 1000);
}
