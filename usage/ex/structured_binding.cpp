#include <iostream>
#include <map>
#include <tuple>

template <typename Key, typename Value, typename F>
void update(std::map<Key, Value> &m, F foo) 
{
    // 结构化绑定
    // 遍历 map 中的元素，将 key 作为参数传入 foo 函数，将返回值作为 value 进行更新
    for (auto &&[key, value] : m)
        value = foo(key);
}

int main()
{
    std::map<std::string, long long int> m{
        {"a", 1},
        {"b", 2},
        {"c", 3}};
    update(m, [](std::string key)
           { return std::hash<std::string>{}(key); });
    for (auto &&[key, value] : m)
        std::cout << key << ":" << value << std::endl;
};
