#include <type_traits>
#include <iostream>

int main()
{
    // 正确，"01234" 类型为 const char [6]，因此是左值
    const char(&left)[6] = "01234";

    // 断言正确，确实是 const char [6] 类型，注意 decltype(expr) 在 expr 是左值
    // 且非无括号包裹的 id 表达式与类成员表达式时，会返回左值引用
    static_assert(std::is_same<decltype("01234"), const char(&)[6]>::value, "");

    // 错误，"01234" 是左值，不可被右值引用
    const char(&&right)[6] = "01234";
    const char *p = "01234";    // 正确，"01234" 被隐式转换为 const char*
    const char *&&pr = "01234"; // 正确，"01234" 被隐式转换为 const char*，该转换的结果是纯右值
    const char *&pl = "01234";  // 错误，此处不存在 const char* 类型的左值
}