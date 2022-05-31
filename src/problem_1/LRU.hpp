#pragma once

#include "array_map.h"
#include "util.h"

template<typename T>
class LRUCache;

template<typename T>
class ListNode {
private:
    std::string key;
    T value;
    ListNode<T> *next;

public:
    ListNode() : next(nullptr) {}

    ListNode(const std::string &key, const T &value) : key(key), value(value), next(nullptr) {}

    friend class LRUCache<T>;
};

template<typename T>
class LRUCache {
private:
    int capacity;

    int num_of_entry;

    ArrayMap<std::string, ListNode<T> *> *map;

    ListNode<T> head; // dummy head node

public:

    explicit LRUCache(int capacity) : capacity(capacity), num_of_entry(0) {
        map = new ArrayMap<std::string, ListNode<T> *>(capacity);
    }

    int get_capacity() {
        return capacity;
    }

    bool get(const std::string &key, T &value);

    bool remove(const std::string &key);

    bool put(const std::string &key, const T &value, T &evicted_value);

    virtual ~LRUCache() {
        /*
         * TODO: Clean up memory
         */
    }
};

/*
 * removes the item with the given name as the key
 */
template<typename T>
bool LRUCache<T>::remove(const std::string &key) {
    /*
     * TODO: Remove an item from the LRU
     *  Return true if any item removed. False otherwise.
     */
    return true;
}

template<typename T>
bool LRUCache<T>::put(const std::string &key, const T &value, T &evicted_value) {
    /*
     * TODO: Store a key-value pair in the LRU. Evict and return another item if necessary.
     *  Return true if eviction happens. False otherwise.
     *
     */
    return false;
}

/*
 * get finds and return the item based on name
 */
template<typename T>
bool LRUCache<T>::get(const std::string &key, T &result) {
    /*
     * TODO: Find and return the value of the given key.
     *  Return true if item found. False otherwise.
     */
    return false;
}
