# Folly Template Project

这是一个使用 Facebook Folly 库的 C++ 项目模板。该模板提供了完整的项目结构和配置，可以作为新项目的起点。

## 特性

- 📦 使用 vcpkg 进行依赖管理
- 🔧 CMake 构建系统配置
- 🧪 Google Test 单元测试支持
- 🐳 Docker 容器化支持
- 🚀 GitHub Actions CI/CD
- 📝 完整的示例代码

## 依赖项

- **Folly**: Facebook 的 C++ 库集合
- **fmt**: 现代 C++ 格式化库
- **glog**: Google 的日志库
- **GTest**: Google 的测试框架

## 快速开始

### 前置要求

1. **CMake** (>= 3.20)
2. **vcpkg** 包管理器
3. **Ninja** 构建系统（推荐）
4. 支持 C++17 的编译器

### 环境设置

确保设置了 `VCPKG_ROOT` 环境变量：

```bash
# Windows PowerShell
$env:VCPKG_ROOT = "C:\path\to\vcpkg"

# Linux/macOS
export VCPKG_ROOT=/path/to/vcpkg
```

### 构建项目

1. **安装依赖**：
   ```bash
   vcpkg install
   ```

2. **配置项目**：
   ```bash
   cmake --preset=default
   ```

3. **构建项目**：
   ```bash
   cmake --build build
   ```

4. **运行程序**：
   ```bash
   ./build/bin/folly_template
   ```

### 运行测试

构建调试版本并运行测试：

```bash
cmake --preset=debug
cmake --build build/debug
cd build/debug && ctest --output-on-failure
```

## 项目结构

```
folly_template/
├── CMakeLists.txt          # 主 CMake 配置文件
├── CMakePresets.json       # CMake 预设配置
├── vcpkg.json             # vcpkg 依赖配置
├── Dockerfile             # Docker 容器配置
├── .gitignore             # Git 忽略文件
├── include/               # 头文件目录
│   └── example.h         # 示例头文件
├── src/                   # 源代码目录
│   ├── main.cpp          # 主程序
│   └── example.cpp       # 示例实现
├── tests/                 # 测试目录
│   └── test_example.cpp  # 示例测试
└── .github/
    └── workflows/
        └── build-ci.yaml # GitHub Actions CI 配置
```

## 示例功能

该模板展示了如何使用 Folly 的以下特性：

1. **字符串处理**: 使用 `folly::fbstring` 进行高效字符串操作
2. **容器**: 使用 `folly::fbvector` 作为 `std::vector` 的替代
3. **异步编程**: 使用 `folly::Future` 进行异步操作
4. **JSON 处理**: 使用 Folly 的 JSON 解析和序列化功能
5. **日志记录**: 集成 glog 和 Folly 的 xlog 系统

## Docker 支持

使用 Docker 构建和运行：

```bash
# 构建镜像
docker build -t folly-template .

# 运行容器
docker run --rm folly-template
```

## 开发指南

### 添加新的源文件

1. 在 `src/` 目录添加源文件
2. 在 `include/` 目录添加头文件
3. 更新 `CMakeLists.txt` 中的源文件列表

### 添加新的依赖

1. 在 `vcpkg.json` 中添加依赖项
2. 在 `CMakeLists.txt` 中添加 `find_package` 和 `target_link_libraries`
3. 运行 `vcpkg install` 安装新依赖

### 编写测试

1. 在 `tests/` 目录添加测试文件
2. 使用 Google Test 框架编写测试
3. 更新 `CMakeLists.txt` 中的测试文件列表

## 许可证

本项目仅作为模板使用，请根据您的项目需求选择合适的许可证。

## 贡献

欢迎提交 Issue 和 Pull Request 来改进这个模板！

## 相关链接

- [Folly 官方文档](https://github.com/facebook/folly)
- [vcpkg 包管理器](https://github.com/Microsoft/vcpkg)
- [CMake 官方文档](https://cmake.org/documentation/)
- [Google Test 文档](https://github.com/google/googletest)
