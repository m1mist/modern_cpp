#include <iostream>
#include <utility>
#include <forward_list>
void reference(int &v)
{
    std::cout << "左值引用" << std::endl;
}
void reference(int &&v)
{
    std::cout << "右值引用" << std::endl;
}
template <typename T>
void pass(T &&v)
{
    std::cout << "                 传参: ";
    reference(v);
    std::cout << "       std::move 传参: ";
    reference(std::move(v));
    std::cout << "    std::forward 传参: ";
    reference(std::forward<T>(v));
    std::cout << "static_cast<T&&> 传参: ";
    reference(static_cast<T &&>(v));
}
int main()
{
    std::cout << "传递右值:" << std::endl;
    pass(1);

    std::cout << "传递左值:" << std::endl;
    int v = 1;
    pass(v);
    return 0;
}