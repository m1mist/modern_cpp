#include <iostream>
/** 
 * @brief 编译期判断类型
 */
template <typename T>
auto print_type_info(const T &t)
{
    if constexpr (std::is_integral<T>::value)
    {
        return t + 1;
    }
    else
    {
        return t + 0.001;
    }
}
// 在编译时，实际代码就会表现为如下：
//  int print_type_info(const int &t)
//  {
//      return t + 1;
//  }
//  double print_type_info(const double &t)
//  {
//      return t + 0.001;
//  }
int main()
{
    std::cout << print_type_info(5) << std::endl;
    std::cout << print_type_info(3.14) << std::endl;
}