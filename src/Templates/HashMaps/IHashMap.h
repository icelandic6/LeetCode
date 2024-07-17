#pragma once

#include <optional>

namespace Template::HashMap
{
    template<typename T, typename V>
    class IHashMap
    {
    public:
        virtual ~IHashMap() = default;

        virtual void put(const T& key, const V& value) = 0;
        virtual void remove(const T& key) = 0;
        virtual std::optional<V> get(const T& key) = 0;

        virtual void print() const = 0;

    private:
        virtual size_t hash(const T& key) const = 0;
    };
}
