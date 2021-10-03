#include <catch2/catch_all.hpp>

#include <algorithm>
#include <vector>

TEST_CASE("25.5.1 all_of") {
  SECTION("all_of returns true if all elements of a collection satisfy a "
          "predicate") {
    auto predicate = [](int i) { return i < 4; };
    auto collection = std::vector<int>{0, 1, 2, 3};

    CHECK(std::all_of(collection.cbegin(), collection.cend(), predicate));
  }

  SECTION("all_of returns false if at least one element of a collection does "
          "not satisfy a predicate") {
    auto predicate = [](int i) { return i < 4; };
    auto collection = std::vector<int>{0, 1, 2, 3, 4};

    CHECK_FALSE(std::all_of(collection.cbegin(), collection.cend(), predicate));
  }
}
