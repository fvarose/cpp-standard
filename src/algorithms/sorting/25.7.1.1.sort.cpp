#include <catch2/catch_all.hpp>

#include <algorithm>
#include <vector>

using namespace Catch::Matchers;

TEST_CASE("25.7.1.1 sort") {
  auto unsorted = std::vector<int>{1, 3, 0, 2};

  SECTION("sort sorts a collection in place using the default operator<") {
    auto expected = std::vector<int>{0, 1, 2, 3};

    std::sort(unsorted.begin(), unsorted.end());

    CHECK_THAT(unsorted, Equals(expected));
  }

  SECTION("sort sorts a collection in place using a comparison function") {
    auto expected = std::vector<int>{3, 2, 1, 0};

    auto compare = std::function<bool(int, int)>();
    SECTION("using a standard library compare function object") {
      compare = std::greater<int>();
    }
    SECTION("using a lambda") {
      compare = [](int a, int b) { return a > b; };
    }
    SECTION("using a custom function object") {
      struct CustomLess {
        bool operator()(int a, int b) const { return a > b; }
      };
      compare = CustomLess{};
    }

    std::sort(unsorted.begin(), unsorted.end(), compare);

    CHECK_THAT(unsorted, Equals(expected));
  }
}
