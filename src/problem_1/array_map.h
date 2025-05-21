/*
 * DO NOT MAKE ANY CHANGES UNLESS SPECIFIED
 */

#pragma once

#include "entry.h"
#include "map.h"
#include "array_list.h"

template<class KeyType, class ValueType>
class ArrayMap : public Map<KeyType, ValueType> {
private:
    static const int DEFAULT_CAPACITY = 10;
    Entry<KeyType, ValueType> **entries;
    int capacity;
    int count;

    int hashFunc(KeyType key) const {
        return std::hash<KeyType>{}(key) % capacity;
    }

public:

    ArrayMap() : ArrayMap(DEFAULT_CAPACITY) {}

    ArrayMap(int capacity) : capacity(capacity), count(0) {
        // () at the end initialize all values to nullptr
        entries = new Entry<KeyType, ValueType> *[capacity]();
    }


    ArrayMap(const std::vector<std::pair<KeyType, ValueType>> &map_data) : ArrayMap(map_data.size()) {
        for (auto &pair: map_data) {
            put(pair.first, pair.second);
        }
    }

    ArrayMap(const ArrayMap &other_map) : ArrayMap(other_map.capacity) {
        for (int i = 0; i < capacity; i++) {
            Entry<KeyType, ValueType> *ptr = other_map.entries[i];
            while (ptr != nullptr) {
                put(ptr->key, ptr->value);
                ptr = ptr->next;
            }
        }
    }

    ~ArrayMap() {
        /*
         * TODO: implement this destructor.
         *  Free every last byte—no memory leaks, no haunting pointers, no regrets.
         *  Leave nothing behind other than good memory :)
         */
    }

    int size() override {
        return count;
    }

    bool is_empty() override {
        return count == 0;
    }

    void put(KeyType const &key, ValueType const &value) override {
        /*
         * TODO: implement this put function.
         *  Must use the given function hashFunc for hashing
         */
    }

    bool get(KeyType const &key, ValueType &value) const override {
        int hashed_key = hashFunc(key);
        Entry<KeyType, ValueType> *ptr = entries[hashed_key];
        while (ptr != nullptr) {
            if (ptr->key == key) {
                value = ptr->value;
                return true;
            }
            ptr = ptr->next;
        }
        return false;
    }

    void print() {
        for (int i = 0; i < capacity; i++) {
            if (entries[i] == nullptr) {
                printf("[%d] = null\n", i);
                continue;
            }
            Entry<KeyType, ValueType> *ptr = entries[i];
            printf("[%d] = {", i);
            while (ptr != nullptr) {
                printf("(%d, %f)", ptr->key, ptr->value);
                ptr = ptr->next;
            }
            printf("}\n");
        }
    }

    bool remove(KeyType const &key) override {
        /*
         * TODO: implement this remove function.
         *  Must use the given function hashFunc for hashing
         */
    }

    bool operator==(const ArrayMap &other_map) const {
        if (count != other_map.count) {
            return false;
        }

        for (int i = 0; i < other_map.capacity; i++) {
            Entry<KeyType, ValueType> *other_ptr = other_map.entries[i];
            while (other_ptr != nullptr) {
                ValueType val;
                if (!get(other_ptr->key, val) || val != other_ptr->value) {
                    return false;
                }
                other_ptr = other_ptr->next;
            }
        }
        return true;
    }

    bool operator!=(const ArrayMap &other_map) const {
        return !(other_map == *this);
    }

    void key_set(List<KeyType> &keys) {
        for (int i = 0; i < capacity; i++) {
            if (entries[i] == nullptr) {
                continue;
            }
            Entry<KeyType, ValueType> *ptr = entries[i];
            while (ptr != nullptr) {
                keys.push_back(ptr->key);
                ptr = ptr->next;
            }
        }
    }
};