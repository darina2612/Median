#include <cmath>
#include "Median.hpp"
#include <gtest/gtest.h>

TEST(MedianTest, EmptyStructureTest)
{
    Median<int> intMedian;
    ASSERT_TRUE(std::isnan(intMedian.getMedian()));

    Median<float> floatMedian;
    ASSERT_TRUE(std::isnan(floatMedian.getMedian()));
}

TEST(MedianTest, OneRepeatingNumber)
{
    Median<int> intMedian;
    Median<double> doubleMedian;

    for(auto i = 0; i < 100; ++i)
    {
        intMedian.add(-1);
        doubleMedian.add(3.5);
    }

    ASSERT_EQ(intMedian.getMedian(), -1);
    ASSERT_EQ(doubleMedian.getMedian(), 3.5);
}

template <typename T>
void addValues(Median<T> & m, const std::vector<T>& values)
{
    for(const auto& value : values)
        m.add(value);
}

TEST(MedianTest, TestEvenNumbersCount)
{
    //-1, 3, 0, 2, 100, -1, 0, 5 -> -1, -1, 0, <0, 2>, 3, 5, 100
    Median<int> m;
    addValues(m, {-1, 3, 0, 2, 100, -1, 0, 5});
    ASSERT_EQ(m.getMedian(), 1);
}

TEST(MedianTest, TestOddNumbersCount)
{
    //-2, 100, -1, 5, 5 -> -2, -1, <5>, 5, 100
    Median<int> m;
    addValues(m, {-2, 100, -1, 5, 5});
    //ASSERT_EQ(m.getMedian(), 5);
}

TEST(MedianTest, TestLargerNumbersCount)
{
    Median<int> m;

    auto n = 5;//1000000;
    for(auto i = 0; i < n/* / 2*/; ++i)
    {
        m.add(i);
        //m.add(n - i - 1);
    }

    ASSERT_EQ(m.getMedian(), 5);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
