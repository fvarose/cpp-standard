#include <catch2/catch_all.hpp>

#include <algorithm>
#include <vector>

using namespace Catch::Matchers;

TEST_CASE("25.6.6 fill") {

  SECTION("fill assigns a given value to a range") {
    auto collection = std::vector<int>{0, 1, 2, 3};
    auto expected = std::vector<int>{-1, -1, -1, -1};

    std::fill(collection.begin(), collection.end(), -1);

    CHECK_THAT(collection, Equals(expected));
  }

  SECTION("fill_n assigns a given value to the first n elements of a range") {
    auto collection = std::vector<int>{0, 1, 2, 3};
    auto expected = std::vector<int>{-1, -1, 2, 3};

    std::fill_n(collection.begin(), 2, -1);

    CHECK_THAT(collection, Equals(expected));
  }
}
