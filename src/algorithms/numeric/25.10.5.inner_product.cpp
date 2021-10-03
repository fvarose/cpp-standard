#include <catch2/catch_all.hpp>

#include <numeric>
#include <vector>

using namespace Catch::Matchers;

TEST_CASE("25.10.5 inner_product") {

  SECTION("inner_product returns the sum of products from 2 collections, "
          "starting from an initial value") {
    const auto grades = std::vector<double>{10.0, 2.0, 8.0, 4.0};
    const auto weights = std::vector<double>{0.45, 0.30, 0.15, 0.10};
    CHECK(std::accumulate(weights.begin(), weights.end(), 0.0) == 1.0);

    const auto average_grade =
        std::inner_product(grades.begin(), grades.end(), weights.begin(), 0.0);

    CHECK(average_grade == 6.7);
  }
}
