#include <gtest/gtest.h>

#include "filter.hpp"

std::vector<std::array<uint8_t, 4>> testSet{
    {1, 2, 1, 1},
    {1, 1, 1, 1},
    {1, 10, 1, 1},
    {1, 1, 2, 1},
};

std::vector<std::array<uint8_t, 4>> testBadSet{
    {1, 223, 1, 1},
    {1, 1, 136, 1},
    {1, 10, 1, 1},
};

TEST(TestFilterActual, BasicAssertions)
{

    using namespace NHomework2;
    auto resultSet = FilterByOctetValue(testSet, {{SECOND, 10}}, FMODE_OR);

    EXPECT_GT(resultSet.size(), 0);
    EXPECT_EQ(resultSet.size(), 1);
    for (size_t i = 0; i < OCTET_NUM; ++i)
    {
        EXPECT_EQ(resultSet[0][i], testSet[2][i]);
    }

    resultSet = FilterByOctetValue(testSet, {{SECOND, 2}, {THIRD, 2}}, FMODE_OR);
    EXPECT_EQ(resultSet.size(), 2);

    resultSet = FilterByOctetValue(testSet, {{SECOND, 2}, {THIRD, 2}}, FMODE_AND);
    EXPECT_EQ(resultSet.size(), 0);

    resultSet = FilterByOctetValue(testSet, {{SECOND, 1}, {THIRD, 1}}, FMODE_AND);
    EXPECT_EQ(resultSet.size(), 1);

    resultSet = FilterByOctetValue(testSet, {{FIRST, 1}, {SECOND, 1}, {THIRD, 1}, {FOURTH, 1}}, FMODE_OR);
    EXPECT_EQ(resultSet.size(), 4);
}

TEST(TestFilterCorner, BasicAssertions)
{
    using namespace NHomework2;
    auto resultSet = FilterByOctetValue(testBadSet, {{SECOND, 1}}, FMODE_OR);
    EXPECT_EQ(resultSet.size(), 1);

    for (size_t i = 0; i < OCTET_NUM; ++i)
    {
        EXPECT_EQ(resultSet[0][i], testBadSet[1][i]);
    }

    EXPECT_EQ(FilterByOctetValue(testBadSet, {{}}, FMODE_OR).size(), 0);
    EXPECT_EQ(FilterByOctetValue(testBadSet, {{}}, FMODE_AND).size(), 0);
    EXPECT_EQ(FilterByOctetValue(testBadSet, {{FIRST, -1}}, FMODE_OR).size(), 0);
    EXPECT_EQ(FilterByOctetValue(testBadSet, {{SECOND, -10}}, FMODE_AND).size(), 0);
}
