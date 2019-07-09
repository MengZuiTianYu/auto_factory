/*************************************************************************
 > File Name: auto_factory.h
 > Author: XinYuan Wang
 > Mail: xywang@aiit.org.cn
 > Created Time: Tue Jul  9 13:40:13 2019
 ************************************************************************/

#pragma once
#include <functional>
#include <map>
#include <memory>
#include <string>

namespace oly {
/**
 * T 需要传入基类
 */
template <typename T>
class auto_factory {
public:
    /**
     * N 子类，这里会把对应子类添加到Map中
     */
    template <typename N>
    struct register_t {
        template <typename... Args>
        register_t(const std::string& key, Args... args)
        {
            auto_factory::instance()->_map.emplace(key, [=] { return new N(args...); });
        }
    };

    /**
     * 普通指针
     */
    static auto normal_ptr(const std::string& key) -> T*
    {
        return auto_factory::instance()->find(key);
    }

    /**
     * unique_ptr指针
     */
    static std::unique_ptr<T> unique_ptr(const std::string& key)
    {
        return std::unique_ptr<T>(normal_ptr(key));
    }

    /**
     * shared_ptr指针
     */
    static std::shared_ptr<T> shared_ptr(const std::string& key)
    {
        return std::shared_ptr<T>(normal_ptr(key));
    }

private:
    auto_factory(){};
    auto_factory(const auto_factory&) = delete;
    auto_factory(auto_factory&&)      = delete;
    auto_factory& operator=(const auto_factory&) = delete;

    /**
     * 单例模式
     */
    static auto instance() -> auto_factory<T>*
    {
        static auto_factory<T> ins;
        return &ins;
    }

    auto find(const std::string& key) -> T*
    {
        if (_map.find(key) == _map.end())
            throw std::invalid_argument("key is not exist!");

        return _map[key]();
    }
    std::map<std::string, std::function<T*()>> _map;
};
}  // namespace oly
