#include <iostream>
template <typename... T>
auto avg(T... t)
{
    // 折叠表达式
    //sizeof...(t) 可变参数的个数
    return (t + ...)/sizeof...(t);
}
int main()
{
    std::cout << avg(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << std::endl;
}