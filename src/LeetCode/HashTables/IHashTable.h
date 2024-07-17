#pragma once

namespace LeetCode::HashTable
{
    class IHashTable
    {
    public:
        virtual ~IHashTable() = default;

        virtual void put(int key, int value) = 0;
        virtual void remove(int key) = 0;
        virtual int get(int key) = 0;

        virtual void print() const = 0;

    private:
        virtual size_t hash(int key) const = 0;
    };
}
