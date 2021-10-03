#include <catch2/catch_all.hpp>

#include <algorithm>
#include <vector>

TEST_CASE("25.5.5 find") {
  SECTION("find returns an iterator to the first element of a "
          "collection that is equal to a certain value") {
    auto collection = std::vector<std::string>{"abc", "klm", "xyz"};

    auto it = std::find(collection.cbegin(), collection.cend(), "klm");
    CHECK(*it == "klm");
  }

  SECTION("find_if returns an iterator to the first element of a collection "
          "that satisfies a predicate") {
    auto is_empty = [](std::string s) { return s.empty(); };
    auto collection = std::vector<std::string>{"abc", "", "xyz"};

    auto it = std::find_if(collection.cbegin(), collection.cend(), is_empty);
    CHECK(*it == "");
  }

  SECTION(
      "find_if_not returns an iterator to the first element of a collection "
      "that does not satisfy a predicate") {
    auto is_empty = [](std::string s) { return s.empty(); };
    auto collection = std::vector<std::string>{"", "klm", ""};

    auto it =
        std::find_if_not(collection.cbegin(), collection.cend(), is_empty);
    CHECK(*it == "klm");
  }
}
