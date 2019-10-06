#include <catch2/catch.hpp>

#include <algorithm>
#include <vector>

using namespace Catch::Matchers;

TEST_CASE("25.7.1.1 sort") {
  SECTION("sort sorts a collection in place using the default operator<") {
    auto collection = std::vector<int>{1, 3, 0, 2};

    std::sort(collection.begin(), collection.end());

    CHECK_THAT(collection, Equals(std::vector<int>{0, 1, 2, 3}));
  }

  SECTION("sort sorts a collection in place using a Comparison function") {
    auto collection = std::vector<int>{1, 3, 0, 2};
    auto compare = std::greater<int>();

    std::sort(collection.begin(), collection.end(), compare);

    CHECK_THAT(collection, Equals(std::vector<int>{3, 2, 1, 0}));
  }
}
