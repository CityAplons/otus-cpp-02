#include <gtest/gtest.h>

#include "io.hpp"
#include "sort.hpp"

std::vector<std::array<uint8_t, 4>> testSet{
    {1, 2, 1, 1},
    {1, 1, 1, 1},
    {1, 10, 1, 1},
    {1, 1, 2, 1},
};

TEST(TestSortAscending, BasicAssertions)
{

    using namespace NHomework2;
    auto resultSet = testSet;

    SortLexicographically(resultSet);
    EXPECT_EQ(resultSet.size(), testSet.size());

    for (decltype(resultSet)::const_iterator ip = resultSet.cbegin() + 1;
         ip != resultSet.cend(); ++ip)
    {
        auto current = *ip;
        auto prev = *(ip - 1);

        // it's just a test :)
        EXPECT_TRUE(current[FIRST] >= prev[FIRST]);
        if (current[FIRST] == prev[FIRST])
        {
            EXPECT_TRUE(current[SECOND] >= prev[SECOND]);
            if (current[SECOND] == prev[SECOND])
            {
                EXPECT_TRUE(current[THIRD] >= prev[THIRD]);
                if (current[THIRD] == prev[THIRD])
                {
                    EXPECT_TRUE(current[FOURTH] >= prev[FOURTH]);
                }
            }
        }
    }
}

TEST(TestSortDescending, BasicAssertions)
{

    using namespace NHomework2;
    auto resultSet = testSet;

    SortLexicographicallyReversed(resultSet);
    EXPECT_EQ(resultSet.size(), testSet.size());

    for (decltype(resultSet)::const_iterator ip = resultSet.cbegin() + 1;
         ip != resultSet.cend(); ++ip)
    {
        auto current = *ip;
        auto prev = *(ip - 1);

        EXPECT_TRUE(current[FIRST] <= prev[FIRST]);
        if (current[FIRST] == prev[FIRST])
        {
            EXPECT_TRUE(current[SECOND] <= prev[SECOND]);
            if (current[SECOND] == prev[SECOND])
            {
                EXPECT_TRUE(current[THIRD] <= prev[THIRD]);
                if (current[THIRD] == prev[THIRD])
                {
                    EXPECT_TRUE(current[FOURTH] <= prev[FOURTH]);
                }
            }
        }
    }
}
