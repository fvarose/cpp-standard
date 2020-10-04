#include <catch2/catch.hpp>

#include <algorithm>
#include <vector>

using namespace Catch::Matchers;

TEST_CASE("25.6.6 fill") {

  SECTION("fill() assigns a given value to a range") {
    auto collection = std::vector<int>{0, 1, 2, 3};
    auto expected = std::vector<int>{-1, -1, -1, -1};

    std::fill(collection.begin(), collection.end(), -1);

    CHECK_THAT(collection, Equals(expected));
  }
}
