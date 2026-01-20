/**
 * SyntaxSugar.hpp
 * 一个让你在 C++ 中使用 Python 风格 "if (x in container)" 的轻量级库
 */

#pragma once

#include <algorithm> // std::find
#include <utility>   // std::pair
#include <type_traits>

namespace sugar {

    // --- 内部辅助元编程工具 (Trait Detection) ---

    // 检测容器是否有 .find() 成员函数 (如 set, map)
    template <typename T, typename Key, typename = void>
    struct has_find : std::false_type {};

    template <typename T, typename Key>
    struct has_find<T, Key, std::void_t<decltype(std::declval<T>().find(std::declval<Key>()))>> : std::true_type {};

    // 检测类型是否是 std::pair
    template <typename T>
    struct is_pair : std::false_type {};
    
    template <typename K, typename V>
    struct is_pair<std::pair<K, V>> : std::true_type {};

    // --- 核心逻辑 ---

    struct InTag {};     // 占位符结构体
    
    // 代理对象，暂存左侧的值
    template <typename T>
    struct InProxy {
        const T& value;
    };

    // 1. 重载 < 运算符：捕获左操作数 (val <_in)
    template <typename T>
    InProxy<T> operator<(const T& val, InTag) {
        return {val};
    }

    // 2. 重载 > 运算符：捕获右操作数并执行逻辑 ((proxy) > container)
    template <typename ValType, typename Container>
    bool operator>(InProxy<ValType> proxy, const Container& container) {
        
        // 场景 A: 容器有 .find() 成员函数 (Map, Set, Unordered_...)
        // 我们利用 if constexpr 在编译期通过 SFINAE 选择最优路径
        if constexpr (has_find<Container, ValType>::value) {
            // 直接查找 Key (适用于 Set, 或 Map 查 Key)
            return container.find(proxy.value) != container.end();
        }
        // 场景 B: 针对 Map 的特殊优化 - 查找 Pair<Key, Value>
        // 用户想做: if (pair("key", val) in map)
        else if constexpr (is_pair<ValType>::value) {
            // 尝试推导是否是 Map (通过检查 key_type)
            // 这里逻辑是：如果我们拿的是个 pair，且容器有 key_type，我们尝试先找 key
            if constexpr (has_find<Container, typename Container::key_type>::value) {
                // 1. 先用 Key 快速查找 (O(logN) 或 O(1))
                auto it = container.find(proxy.value.first);
                // 2. 如果 Key 存在，再比对 Value
                if (it != container.end()) {
                    return it->second == proxy.value.second;
                }
                return false;
            } else {
                 // 回退到通用算法
                 return std::find(std::begin(container), std::end(container), proxy.value) != std::end(container);
            }
        }
        // 场景 C: 普通线性容器 (Vector, List, Deque, Array)
        else {
            return std::find(std::begin(container), std::end(container), proxy.value) != std::end(container);
        }
    }

    // 定义全局常量 _in_tag
    static const InTag _in_tag;

} // namespace sugar

// 暴露宏到全局
// 注意：为了避免宏污染，用户也可以手动 using，但为了 Python 体验，这里直接定义
#define in <sugar::_in_tag>