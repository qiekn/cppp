#include "primer/hash/uuid.cpp"  // NOLINT: include implementation directly for testing

#include <gtest/gtest.h>

#include <unordered_set>

TEST(UUIDTest, ExplicitValueConstruction) {
  UUID uuid(42);
  EXPECT_EQ(static_cast<uint64_t>(uuid), 42);
}

TEST(UUIDTest, ZeroValue) {
  UUID uuid(0);
  EXPECT_EQ(static_cast<uint64_t>(uuid), 0);
}

TEST(UUIDTest, MaxValue) {
  UUID uuid(UINT64_MAX);
  EXPECT_EQ(static_cast<uint64_t>(uuid), UINT64_MAX);
}

TEST(UUIDTest, CopyConstruction) {
  UUID original(123);
  UUID copy(original);
  EXPECT_EQ(static_cast<uint64_t>(copy), static_cast<uint64_t>(original));
}

TEST(UUIDTest, RandomUUIDsAreUnique) {
  // generate multiple random UUIDs and verify no collisions
  constexpr int kCount = 1000;
  std::unordered_set<uint64_t> seen;
  for (int i = 0; i < kCount; ++i) {
    seen.insert(static_cast<uint64_t>(UUID()));
  }
  EXPECT_EQ(seen.size(), kCount);
}

TEST(UUIDTest, WorksAsUnorderedSetKey) {
  std::unordered_set<UUID> set;
  UUID a(1), b(2), c(1);

  set.insert(a);
  set.insert(b);
  set.insert(c);  // duplicate of a

  EXPECT_EQ(set.size(), 2);
  EXPECT_TRUE(set.count(UUID(1)));
  EXPECT_TRUE(set.count(UUID(2)));
  EXPECT_FALSE(set.count(UUID(3)));
}
