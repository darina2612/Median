#pragma once
#include <queue>

template <typename ValueType,
          typename = std::enable_if_t<std::is_arithmetic<ValueType>::value>>
class Median
{
public:
    Median() = default;

    void add(ValueType entry);
    double getMedian() const;

private:
    std::priority_queue<ValueType> leftHalf_;
    std::priority_queue<ValueType, std::vector<ValueType>, std::greater<ValueType>> rightHalf_;
};

template <typename ValueType>
void Median<ValueType>::add(ValueType number)
{

}

template <typename ValueType>
double Median<ValueType>::getMedian() const
{
    if(leftHalf_.size() == rightHalf_.size())
    {
        return (leftHalf_.top() + rightHalf_.top()) / 2.0;
    }
    else {
        //todo
        return 0.0;
    }
}
