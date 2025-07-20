#pragma once

#include <string>
#include <vector>
#include <folly/FBString.h>
#include <folly/FBVector.h>
#include <folly/futures/Future.h>

namespace folly_template {

/**
 * 示例类，展示如何使用 Folly 库的一些特性
 */
class Example {
public:
    Example() = default;
    ~Example() = default;

    /**
     * 使用 folly::fbstring 进行字符串操作
     */
    folly::fbstring processString(const std::string& input);

    /**
     * 使用 folly::fbvector 进行向量操作
     */
    folly::fbvector<int> processVector(const std::vector<int>& input);

    /**
     * 异步处理示例，使用 folly::Future
     */
    folly::Future<std::string> processAsync(const std::string& input);

    /**
     * JSON 处理示例
     */
    std::string processJson(const std::string& jsonStr);

private:
    // 私有成员变量
    mutable std::mutex mutex_;
};

} // namespace folly_template
