#pragma once

namespace LeetCode::HashSet
{
    class IHashSet
    {
    public:
        virtual ~IHashSet() = default;

        virtual void add(int key) = 0;
        virtual void remove(int key) = 0;
        virtual bool contains(int key) = 0;

        virtual void print() const = 0;

    private:
        virtual size_t hash(int key) const = 0;
    };
}
