#include <catch2/catch.hpp>

#include <algorithm>
#include <vector>

TEST_CASE("25.2.2 any_of")
{
  SECTION("any_of returns true if at least one element of a collection "
          "satisfies a predicate")
  {
    auto predicate = [](int i) { return i < 4; };
    auto collection = std::vector<int>{0, 1, 2, 3, 4, 5};

    CHECK(std::any_of(collection.cbegin(), collection.cend(), predicate));
  }

  SECTION("any_of returns false if no element of a collection satisfy a "
          "predicate")
  {
    auto predicate = [](int i) { return i > 4; };
    auto collection = std::vector<int>{0, 1, 2, 3, 4};

    CHECK_FALSE(std::any_of(collection.cbegin(), collection.cend(), predicate));
  }
}
