#include "Median.h"

#include <iterator>

void Median::add(int number)
{
    numbers_.insert(number);
}

double Median::getMedian() const
{
    auto size = numbers_.size();

    if(size % 2 == 0)
    {
        auto left = numbers_.begin();
        std::advance(left, size / 2);

        auto right = numbers_.begin();
        std::advance(left, size / 2);

        return (*left + *right) / 2.0;
    }
    else
    {
        auto median = numbers_.begin();
        std::advance(median, size / 2);

        return *median;
    }
}
