#include <catch2/catch_all.hpp>

#include <algorithm>
#include <vector>

TEST_CASE("25.5.4 for_each") {
  SECTION("for_each applies a function to all elements of a collection, "
          "without modifying them.") {
    auto sum = 0;
    auto add = [&sum](int i) { sum += i; };
    auto collection = std::vector<int>{0, 1, 2, 3, 4};

    std::for_each(collection.cbegin(), collection.cend(), add);

    CHECK(sum == 10);
  }
}
