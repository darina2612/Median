#pragma once
#include <queue>
#include <limits>

template <typename ValueType>
class Median
{
    static_assert(std::is_arithmetic<ValueType>::value, "Template type must be arithmetic.");

public:
   /**
    * @brief Inserts a new value to the structure with O(log n) operation complexity.
    *
    * @param entry The value to be inserted in the structure.
    */
    void add(ValueType entry);

   /**
    * @brief Calculates the current median value with O(1) operation complexity.
    *
    * @return Current median value, if the structure is not empty, NaN value otherwise.
    */
    double getMedian() const;

private:
    //elements <= of the current median at any moment are kept here:
    std::priority_queue<ValueType> leftHalf_;
    //elements >= of the current median at any moment are kept here:
    std::priority_queue<ValueType, std::vector<ValueType>, std::greater<ValueType>> rightHalf_;
};

template <typename ValueType>
void Median<ValueType>::add(ValueType entry)
{
    if(leftHalf_.empty() && rightHalf_.empty())
    {
        //if both containers are empty, we choose to add the first element at the left half
        leftHalf_.emplace(entry);
    }
    else
    {
        // determining in which half the new element should go :
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

        // Keeping the difference between the left and the right half elements count at most 1, so that :
        // - the median is the value at the top of the container with the greater size,
        // when sizes differ (and the total elements count is an odd number) and
        // - the median is the value at the average of the tops of both containers conunt,
        // when sizes are equal (and the total elements count is an even number)
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
        //returning NaN, if the median of an empty structure is requested.
        return std::numeric_limits<double>::quiet_NaN();
    }
    if(leftHalf_.size() == rightHalf_.size())
    {
        //if elements count is an even number,
        //the median is the average of the greatest element value of the first half and
        //the minimum element value of the second half
        return (leftHalf_.top() + rightHalf_.top()) * 0.5;
    }
    else
    {
        //if structure elements count is an odd number,
        //the value of the median is the greatest element value of the first (left) half, if it contains more elements than the second half,
        //or the minimum element value of the second (right) half, if it contains more elements than the first half
        return leftHalf_.size() > rightHalf_.size() ?
               leftHalf_.top() :
               rightHalf_.top();
    }
}
