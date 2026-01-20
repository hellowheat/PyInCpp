/**
 * PyInCpp
 * 一个让你在 C++ 中使用 Python 风格 "if (x in container)" 的轻量级库
 */

#pragma once

#include <algorithm>
#include <utility>
#include <type_traits>

namespace sugar {

    template <typename T, typename Key, typename = void>
    struct has_find : std::false_type {};

    template <typename T, typename Key>
    struct has_find<T, Key, std::void_t<decltype(std::declval<T>().find(std::declval<Key>()))>> : std::true_type {};

    template <typename T>
    struct is_pair : std::false_type {};
    
    template <typename K, typename V>
    struct is_pair<std::pair<K, V>> : std::true_type {};

    struct InTag {};
    
    template <typename T>
    struct InProxy {
        const T& value;
    };

    template <typename T>
    InProxy<T> operator<(const T& val, InTag) {
        return {val};
    }

    template <typename ValType, typename Container>
    bool operator>(InProxy<ValType> proxy, const Container& container) {
        
        if constexpr (has_find<Container, ValType>::value) {
            return container.find(proxy.value) != container.end();
        }
        else if constexpr (is_pair<ValType>::value) {
            if constexpr (has_find<Container, typename Container::key_type>::value) {
                auto it = container.find(proxy.value.first);
                if (it != container.end()) {
                    return it->second == proxy.value.second;
                }
                return false;
            } else {
                 return std::find(std::begin(container), std::end(container), proxy.value) != std::end(container);
            }
        }
        else {
            return std::find(std::begin(container), std::end(container), proxy.value) != std::end(container);
        }
    }

    static const InTag _in_tag;

}

#define in <sugar::_in_tag>
