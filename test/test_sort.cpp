#include <gtest/gtest.h>

#include "io.hpp"
#include "sort.hpp"

std::vector<std::vector<std::string>> testSet{
    {"1", "2", "1", "1"},
    {"1", "1", "1", "1"},
    {"1", "10", "1", "1"},
    {"1", "1", "2", "1"},
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
        EXPECT_TRUE(std::stoi(current[FIRST]) >= std::stoi(prev[FIRST]));
        if (std::stoi(current[FIRST]) == std::stoi(prev[FIRST]))
        {
            EXPECT_TRUE(std::stoi(current[SECOND]) >= std::stoi(prev[SECOND]));
            if (std::stoi(current[SECOND]) == std::stoi(prev[SECOND]))
            {
                EXPECT_TRUE(std::stoi(current[THIRD]) >= std::stoi(prev[THIRD]));
                if (std::stoi(current[THIRD]) == std::stoi(prev[THIRD]))
                {
                    EXPECT_TRUE(std::stoi(current[FOURTH]) >= std::stoi(prev[FOURTH]));
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

        EXPECT_TRUE(std::stoi(current[FIRST]) <= std::stoi(prev[FIRST]));
        if (std::stoi(current[FIRST]) == std::stoi(prev[FIRST]))
        {
            EXPECT_TRUE(std::stoi(current[SECOND]) <= std::stoi(prev[SECOND]));
            if (std::stoi(current[SECOND]) == std::stoi(prev[SECOND]))
            {
                EXPECT_TRUE(std::stoi(current[THIRD]) <= std::stoi(prev[THIRD]));
                if (std::stoi(current[THIRD]) == std::stoi(prev[THIRD]))
                {
                    EXPECT_TRUE(std::stoi(current[FOURTH]) <= std::stoi(prev[FOURTH]));
                }
            }
        }
    }
}
