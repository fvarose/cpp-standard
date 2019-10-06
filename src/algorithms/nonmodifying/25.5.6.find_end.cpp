#include <catch2/catch.hpp>

#include <algorithm>
#include <cstdlib>
#include <vector>

TEST_CASE("25.2.6 find_end")
{
    SECTION("find_end returns an iterator to the last subsequence of elements in "
            "a collection")
    {
        auto pattern = std::vector<int>{0, 1};
        auto collection = std::vector<int>{0, 0, 1, 1, 1, 0, 1, 1};
        //                                    ⬆          ⬆
        //                                 0  1  2  3  4  5  6  7

        auto it = std::find_end(collection.cbegin(), collection.cend(),
                                pattern.cbegin(), pattern.cend());

        CHECK(std::distance(collection.cbegin(), it) == 5);
    }

    SECTION("find_end returns an iterator to the last subsequence of elements in "
            "a collection. Comparison is performed element-wise using a given "
            "predicate")
    {
        auto pattern = std::vector<char>{'0', '1'};
        auto collection = std::vector<int>{0, 0, 1, 1, 1, 0, 1, 1};
        //                                    ⬆          ⬆
        //                                 0  1  2  3  4  5  6  7
        auto equal = [](int i, char c) { return i == std::atoi(&c); };

        auto it = std::find_end(collection.cbegin(), collection.cend(),
                                pattern.cbegin(), pattern.cend(), equal);

        CHECK(std::distance(collection.cbegin(), it) == 5);
    }
}
