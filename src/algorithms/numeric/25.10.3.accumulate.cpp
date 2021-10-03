#include <catch2/catch_all.hpp>

#include <numeric>
#include <vector>

using namespace Catch::Matchers;

TEST_CASE("25.10.3 accumulate") {

  SECTION("accumulate sums all values in a collection, starting from an "
          "initial value") {
    const auto values = std::vector<int>{1, 3, 0, 2};

    SECTION("with a 0 initial value") {
      const auto result = std::accumulate(values.begin(), values.end(), 0);
      CHECK(result == 6);
    }
    SECTION("with a non-0 initial value") {
      const auto result = std::accumulate(values.begin(), values.end(), 10);
      CHECK(result == 16);
    }
  }
}
