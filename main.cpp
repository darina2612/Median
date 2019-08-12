#include "Median.hpp"
#include <iostream>

int main()
{
    Median<int> m;
    m.add(1);
    m.add(1);
    m.add(3);
    //m.add(4);
    m.add(3);
    m.add(5);
    //m.add(2);

    std::cout << m.getMedian() << std::endl;

    return 0;
}
