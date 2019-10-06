#include <catch2/catch.hpp>

#include <algorithm>
#include <vector>

TEST_CASE("25.5.3 none_of") {
  SECTION("none_of returns true if no elements of a collection satisfy a "
          "predicate") {
    auto predicate = [](int i) { return i < 4; };
    auto collection = std::vector<int>{4, 5, 6, 7, 8};

    CHECK(std::none_of(collection.cbegin(), collection.cend(), predicate));
  }

  SECTION("none_of returns false if at least one element of a collection "
          "satisfy a predicate") {
    auto predicate = [](int i) { return i < 4; };
    auto collection = std::vector<int>{3, 4, 5, 6, 7};

    CHECK_FALSE(
        std::none_of(collection.cbegin(), collection.cend(), predicate));
  }
}
