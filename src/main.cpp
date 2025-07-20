#include <folly/FBString.h>
#include <folly/FBVector.h>
#include <folly/executors/GlobalExecutor.h>
#include <folly/futures/Future.h>
#include <folly/json/json.h>
#include <iostream>

int main()
{
    std::cout << "=== Folly Template Demo ===" << std::endl;

    // 1. FBVector 示例
    std::cout << "\n1. FBVector Example:" << std::endl;
    folly::fbvector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    std::cout << "FBVector contents: ";
    for (const auto &v : vec)
    {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    // 2. FBString 示例
    std::cout << "\n2. FBString Example:" << std::endl;
    folly::fbstring str("Hello, Folly!");
    std::cout << "FBString: " << str << std::endl;
    std::cout << "Length: " << str.size() << std::endl;

    // 3. JSON 示例
    std::cout << "\n3. JSON Example:" << std::endl;
    try
    {
        folly::dynamic jsonObj = folly::dynamic::object("name", "Folly Demo")("version", 1.0)(
            "features", folly::dynamic::array("fast", "efficient", "modern"));

        std::string jsonStr = folly::toJson(jsonObj);
        std::cout << "JSON: " << jsonStr << std::endl;

        // 解析 JSON
        folly::dynamic parsed = folly::parseJson(jsonStr);
        std::cout << "Parsed name: " << parsed["name"].asString() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "JSON error: " << e.what() << std::endl;
    }

    // 4. Future 示例
    std::cout << "\n4. Future Example:" << std::endl;
    try
    {
        auto future = folly::via(folly::getGlobalCPUExecutor()).thenValue([](auto &&) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            return std::string("Async operation completed!");
        });

        auto result = std::move(future).get();
        std::cout << "Future result: " << result << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Future error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Demo completed ===" << std::endl;
    return 0;
}
