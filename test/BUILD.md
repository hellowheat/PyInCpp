# 测试工程构建说明

## 构建步骤

```bash
# 在 test 目录下创建 build 目录
mkdir build
cd build

# 配置 CMake
cmake ..

# 构建
cmake --build .

# 运行测试
ctest
```

或者直接运行测试可执行文件：
```bash
./test_pyincpp
```
