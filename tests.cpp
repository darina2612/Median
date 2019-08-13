#include <cmath>
#include "Median.hpp"
#include <gtest/gtest.h>

TEST(MedianTest, EmptyStructureTest)
{
    Median<int> intMedian;
    EXPECT_TRUE(std::isnan(intMedian.getMedian()));

    Median<float> floatMedian;
    EXPECT_TRUE(std::isnan(floatMedian.getMedian()));

    Median<double> doubleMedian;
    EXPECT_TRUE(std::isnan(doubleMedian.getMedian()));

    Median<bool> boolMedian;
    EXPECT_TRUE(std::isnan(boolMedian.getMedian()));

    Median<char> charMedian;
    EXPECT_TRUE(std::isnan(charMedian.getMedian()));
}

TEST(MedianTest, SingleValueTest)
{
    Median<int> intMedian;
    intMedian.add(3);
    EXPECT_EQ(intMedian.getMedian(), 3);

    Median<double> doubleMedian;
    doubleMedian.add(-1.2);
    EXPECT_EQ(doubleMedian.getMedian(), -1.2);

    Median<bool> boolMedian;
    boolMedian.add(true);
    EXPECT_EQ(boolMedian.getMedian(), true);

    Median<char> charMedian;
    charMedian.add('a');
    EXPECT_EQ(charMedian.getMedian(), 'a');
}

TEST(MedianTest, OneRepeatingNumberTest)
{
    Median<int> intMedian;
    Median<double> doubleMedian;

    for(auto i = 0; i < 100; ++i)
    {
        intMedian.add(-1);
        doubleMedian.add(3.5);
    }

    EXPECT_EQ(intMedian.getMedian(), -1);
    EXPECT_EQ(doubleMedian.getMedian(), 3.5);
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
    Median<int> intMedian;
    addValues(intMedian, {-1, 3, 0, 2, 100, -1, 0, 5});
    EXPECT_EQ(intMedian.getMedian(), 1);

    // 0.5, 0.7, -2.0, 1.3 -> -2.0, <0.5, 0.7>, 1.3
    Median<double> doubleMedian;
    addValues(doubleMedian, {0.5, 0.7, -2.0, 1.3});
    EXPECT_EQ(doubleMedian.getMedian(), 0.6);

    Median<bool> boolMedian;
    addValues(boolMedian, {true, false});
    EXPECT_EQ(boolMedian.getMedian(), 0.5);

    Median<char> charMedian;
    addValues(charMedian, {'a', 'c'});
    EXPECT_EQ(charMedian.getMedian(), 'b');
}

TEST(MedianTest, TestOddNumbersCount)
{
    //-2, 100, -1, 5, 5 -> -2, -1, <5>, 5, 100
    Median<int> m;
    addValues(m, {-2, 100, -1, 5, 5});
    EXPECT_EQ(m.getMedian(), 5);

    // 0.5, 0.7, -2.0, 1.3, 0.0 -> -2.0, 0.0, <0.5>, 0.7, 1.3
    Median<double> doubleMedian;
    addValues(doubleMedian, {0.5, 0.7, -2.0, 1.3, 0.0});
    EXPECT_EQ(doubleMedian.getMedian(), 0.5);

    Median<bool> boolMedian;
    addValues(boolMedian, {true, false, false});
    EXPECT_EQ(boolMedian.getMedian(), false);

    Median<char> charMedian;
    addValues(charMedian, {'a', 'c', 'e'});
    EXPECT_EQ(charMedian.getMedian(), 'c');
}

TEST(MedianTest, TestLargerNumbersCount)
{
    Median<int> m;

    //0, 1, ..., <499999, 500000>, ..., 999999 -> 499999.5
    auto n = 1000000;
    for(auto i = 0; i < n / 2; ++i)
    {
        m.add(i);
        m.add(n - i - 1);
    }

    EXPECT_EQ(m.getMedian(), 499999.5);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
