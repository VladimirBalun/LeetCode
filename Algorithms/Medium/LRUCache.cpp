#include "../Helpers.hpp"

// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
// Implement the LRUCache class:

// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

// The functions get and put must each run in O(1) average time complexity.

// Example 1:
// Input
// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// Output
// [null, null, null, 1, null, -1, null, -1, 3, 4]

// Explanation
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // cache is {1=1}
// lRUCache.put(2, 2); // cache is {1=1, 2=2}
// lRUCache.get(1);    // return 1
// lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
// lRUCache.get(2);    // returns -1 (not found)
// lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
// lRUCache.get(1);    // return -1 (not found)
// lRUCache.get(3);    // return 3
// lRUCache.get(4);    // return 4

class LRUCache
{
public:
    LRUCache(int capacity)
        : m_capacity(capacity) {}
    
    int get(int key)
    {
        const auto it = m_lookup_table.find(key);
        if (it == end(m_lookup_table)) {
            return -1;
        }

        const int value = it->second->second;
        update(key, value);
        return value;
    }
    
    void put(int key, int value)
    {
        if (m_capacity <= 0) {
            return;
        }

        if ((m_lookup_table.count(key) == 0) && (m_values.size() == m_capacity)) {
            const int old_key = m_values.front().first;
            m_values.pop_front();
            m_lookup_table.erase(old_key);
        }

        update(key, value);
    }
private:
    void update(int key, int value)
    {
        const auto it = m_lookup_table.find(key);
        if (it != end(m_lookup_table)) {
            m_values.erase(it->second);
        }

        m_values.emplace_back(key, value);
        m_lookup_table[key] = prev(end(m_values));
    }
private:
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m_lookup_table; 
    std::list<std::pair<int, int>> m_values;
    int m_capacity;
};


int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
