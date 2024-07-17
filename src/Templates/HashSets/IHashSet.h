#pragma once

namespace Template::HashSet
{
    template<typename T>
    class IHashSet
    {
    public:
        virtual ~IHashSet() = default;

        virtual void add(const T& key) = 0;
        virtual void remove(const T& key) = 0;
        virtual bool contains(const T& key) = 0;

        virtual void print() const = 0;

    private:
        virtual size_t hash(const T& key) const = 0;
    };
}
