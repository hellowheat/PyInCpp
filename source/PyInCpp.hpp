/**
 * PyInCpp
 * 一个让你在 C++ 中使用 Python 风格 "if (x in container)" 的轻量级库
 *
 * Requirements: C++17 or later
 */

#pragma once

#include <algorithm>
#include <utility>
#include <type_traits>

namespace sugar {

    // Type trait to check if a container has a .find() member function
    template <typename T, typename Key, typename = void>
    struct has_find : std::false_type {};

    template <typename T, typename Key>
    struct has_find<T, Key, std::void_t<decltype(std::declval<T>().find(std::declval<Key>()))>> : std::true_type {};

    // Type trait to check if a type is std::pair
    template <typename T>
    struct is_pair : std::false_type {};
    
    template <typename K, typename V>
    struct is_pair<std::pair<K, V>> : std::true_type {};

    // Tag type for the 'in' operator
    struct InTag {};
    
    // Proxy object to hold the value being checked
    template <typename T>
    struct InProxy {
        const T& value;
    };

    // Creates an InProxy from a value and the InTag
    template <typename T>
    InProxy<T> operator<(const T& val, InTag) {
        return {val};
    }

    // Checks if the value is in the container
    template <typename ValType, typename Container>
    bool operator>(InProxy<ValType> proxy, const Container& container) {
        
        // Use container's .find() method if available (optimized for associative containers)
        if constexpr (has_find<Container, ValType>::value) {
            return container.find(proxy.value) != container.end();
        }
        // Handle std::pair for map-like containers (key-value pair lookup)
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
        // Fallback to linear search for containers without .find()
        else {
            return std::find(std::begin(container), std::end(container), proxy.value) != std::end(container);
        }
    }

    // Global tag instance for the 'in' operator
    static const InTag _in_tag;

}

// Macro to enable Python-style 'in' operator syntax
#define in <sugar::_in_tag>
