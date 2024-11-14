#include <iostream>
#include <bits/unique_ptr.h>
/*
lamda表达式使用场景
1. std::sort
2. std::thread
3. std::bind
4. std::function
5. std::async
6. std::accumulate
7. std::for_each
8. std::transform
9. std::find_if
10. std::remove_if
*/

// 捕获值
// 与参数传值类似，值捕获的前提是变量可以拷贝，不同之处则在于，被捕获的变量在 Lambda 表达式被创建时拷贝， 而非调用时才拷贝：
void lambda_value_capture()
{
    int value = 1;
    auto copy_value = [value]
    { return value; }; // 或者[=]
    value = 100;
    auto stored_value = copy_value();
    std::cout << "stored_value = " << stored_value << std::endl;
    std::cout << "value = " << value << std::endl;
    // 这时, stored_value == 1, 而 value == 100.
    // 因为 copy_value 在创建时就保存了一份 value 的拷贝
}

// 捕获引用
// 与引用传参类似，引用捕获保存的是引用，值会发生变化。
// 与值捕获不同，引用捕获有以下两点限制：
// 1. 引用捕获的变量在 Lambda 表达式创建时必须存在，因此捕获列表中不能有 this 指针。
// 2. 与值捕获不同，引用捕获的是变量本身，而不是变量的拷贝，所以在 Lambda 表达式中可以修改捕获的引用的值。

void lambda_reference_capture()
{
    int value = 1;
    auto copy_value = [&value]
    { return value; }; // 或者[&]
    value = 100;
    auto stored_value = copy_value();
    std::cout << "stored_value = " << stored_value << std::endl;
    std::cout << "value = " << value << std::endl;
    // 这时, stored_value == 100, value == 100.
    // 因为 copy_value 保存的是引用
}

/*
隐式捕获
[] 空捕获列表
[name1, name2, ...] 捕获一系列变量
[&] 引用捕获, 从函数体内的使用确定引用捕获列表
[=] 值捕获, 从函数体内的使用确定值捕获列表
*/

// 表达式捕获
// important 是一个独占指针，是不能够被 "=" 值捕获到，这时候我们可以将其转移为右值，在表达式中初始化。

void lamda_expression_capture()
{
    auto important = std::make_unique<int>(1);
    auto add = [v1 = 1, v2 = std::move(important)](int x, int y) -> int
    {
        return x + y + v1 + (*v2);
    };
    std::cout << add(3, 4) << std::endl;
}
// 泛型 Lambda
auto add = [](auto x, auto y)
{
    return x + y;
};

int main()
{
    lambda_value_capture();
    lambda_reference_capture();
    lamda_expression_capture();
    std::cout << add(1, 2) << std::endl;
    std::cout << add(1.1, 2.2) << std::endl;
    return 0;
};