#include <catch2/catch_all.hpp>

#include <numeric>
#include <vector>

using namespace Catch::Matchers;

TEST_CASE("25.10.7 partial_sum") {

  SECTION("partial_sum fills a collection with the partial sums of the input "
          "collection") {
    const auto per_day = std::vector<int>{2, 4, 8, 4, 2};
    const auto expected = std::vector<int>{2, 6, 14, 18, 20};

    auto partial_sums = std::vector<int>(per_day.size());
    std::partial_sum(per_day.begin(), per_day.end(), partial_sums.begin());

    CHECK_THAT(partial_sums, Equals(expected));
  }
}
