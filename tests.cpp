#include <cmath>
#include <utility>
#include "Median.hpp"
#include <gtest/gtest.h>

TEST(MedianTest, InstantiationTest)
{
//    ASSERT_NO_THROW({Median<int> intMedian;});
//    ASSERT_ANY_THROW({Median<std::pair<int, int>> pairMedian;});
}

TEST(MedianTest, EmptyStructureTest)
{
    Median<int> intMedian;
    ASSERT_TRUE(std::isnan(intMedian.getMedian()));

    Median<float> floatMedian;
    ASSERT_TRUE(std::isnan(floatMedian.getMedian()));

    Median<bool> boolMedian;
    ASSERT_TRUE(std::isnan(boolMedian.getMedian()));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
