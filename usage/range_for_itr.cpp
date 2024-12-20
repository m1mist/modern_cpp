#include <iostream>
#include <vector>
#include <algorithm>
template <typename T, typename U>
class MagicType
{
public:
    T dark;
    U magic;
};

// 不合法

using NewProcess = int (*)(void *);
template <typename T>
using TrueDarkMagic = MagicType<std::vector<T>, std::string>;

int main()
{
    std::vector<int> vec = {1, 2, 3, 4};
    if (auto itr = std::find(vec.begin(), vec.end(), 3); itr != vec.end())
        *itr = 4;
    for (auto element : vec)
        std::cout << element << std::endl; // read only
    for (auto &element : vec)
    {
        element += 1; // writeable
    }
    for (auto element : vec)
        std::cout << element << std::endl; // read only
}