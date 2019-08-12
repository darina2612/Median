#pragma once
#include <queue>

template <typename ValueType>
class Median
{
    static_assert (std::is_arithmetic<ValueType>::value, "Template type must be arithmetic.");

public:
    Median() = default;

    void add(const ValueType& entry);
    double getMedian() const;

private:
    std::priority_queue<ValueType> leftHalf_;
    std::priority_queue<ValueType, std::vector<ValueType>, std::greater<ValueType>> rightHalf_;
};

template <typename ValueType>
void Median<ValueType>::add(const ValueType& entry)
{
    if(leftHalf_.empty() && rightHalf_.empty())
    {
        leftHalf_.emplace(entry);
    }
    else
    {
        if(entry > leftHalf_.top())
            rightHalf_.emplace(entry);
        else
            leftHalf_.emplace(entry);

        auto moveNeeded = [](const auto& left, const auto& right)
        {
            return left.size() > right.size() + 1;
        };

        auto moveTop = [](auto& source, auto& destination)
        {
            destination.emplace(source.top());
            source.pop();
        };

        if(moveNeeded(leftHalf_, rightHalf_))
            moveTop(leftHalf_, rightHalf_);
        else if(moveNeeded(rightHalf_, leftHalf_))
            moveTop(rightHalf_, leftHalf_);
    }
}

template <typename ValueType>
double Median<ValueType>::getMedian() const
{
    if(leftHalf_.empty() && rightHalf_.empty())
    {
        //todo what?
        return 0.0;
    }
    if(leftHalf_.size() == rightHalf_.size())
    {
        return (leftHalf_.top() + rightHalf_.top()) / 2.0;
    }
    else
    {
        return leftHalf_.size() > rightHalf_.size() ?
               leftHalf_.top() :
               rightHalf_.top();
    }
}
