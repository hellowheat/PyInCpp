# PyInCpp

## 简介

PyInCpp 是一个轻量级的 C++ 头文件库，让你可以在 C++ 中使用 Python 风格的 `in` 操作符进行容器成员检查。通过简洁的语法糖，让 C++ 代码更加优雅和易读。

### 特性

- **Python 风格语法**：使用 `if (x in container)` 替代繁琐的 `std::find` 或 `container.find()`
- **零依赖**：仅需标准库支持
- **头文件即用**：只需包含一个头文件即可使用

## 使用说明

### 基本用法

#### Map 查找

```cpp
#include <map>
#include <utility>
#include "PyInCpp_vX.X.hpp"

int main() {
    std::map<std::string, int> scores = {
        {"Alice", 95},
        {"Bob", 87}
    };
    
    if ("Alice" in scores) {
        // Alice 存在
    }
    
    if (std::make_pair("Bob", 87) in scores) {
        // Bob 的分数是 87
    }
    
    return 0;
}
```

#### 其他容器

```cpp
#include <vector>
#include <set>
#include <array>
#include "PyInCpp_vX.X.hpp"

int main() {
    std::vector<int> nums = {1, 2, 3};
    std::set<std::string> names = {"Alice", "Bob"};
    std::array<int, 3> arr = {10, 20, 30};
    
    if (2 in nums) { }
    if ("Bob" in names) { }
    if (20 in arr) { }
    
    return 0;
}
```

### 支持的容器类型

- **序列容器**：`std::vector`, `std::list`, `std::deque`, `std::array`
- **关联容器**：`std::set`, `std::map`, `std::multiset`, `std::multimap`
- **无序容器**：`std::unordered_set`, `std::unordered_map`

## 版本更新记录

### v0.9 (2026-01-20)

- 初始版本发布
- 实现核心 `in` 操作符功能
- 支持标准库容器（vector, list, set, map, array 等）

## 许可证

本项目采用 MIT 许可证。详见 [LICENSE](LICENSE) 文件。

## 作者

hellowheat

## 贡献

欢迎提交 Issue 和 Pull Request！
