#include "HashTable.h"
#include <iostream>

HashTable::HashTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        table[i] = nullptr;
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        HashNode* entry = table[i];
        while (entry != nullptr) {
            HashNode* prev = entry;
            entry = entry->next;
            delete prev;
        }
    }
}

int HashTable::hashFunction(const std::string& key) const {

    return key.length() % TABLE_SIZE;
}

void HashTable::add(const std::string& key, double value) {
    int index = hashFunction(key);
    HashNode* newNode = new HashNode(key, value);
    newNode->next = table[index];
    table[index] = newNode;
}

bool HashTable::remove(const std::string& key) {
    int index = hashFunction(key);
    HashNode* entry = table[index];
    HashNode* prev = nullptr;

    while (entry != nullptr) {
        if (entry->key == key) {
            if (prev == nullptr) {
                table[index] = entry->next;
            } else {
                prev->next = entry->next;
            }
            delete entry;
            return true;
        }
        prev = entry;
        entry = entry->next;
    }
    return false;
}

bool HashTable::find(const std::string& key, double& value) const {
    int index = hashFunction(key);
    HashNode* entry = table[index];

    while (entry != nullptr) {
        if (entry->key == key) {
            value = entry->value;
            return true;
        }
        entry = entry->next;
    }
    return false;
}

bool HashTable::isEmpty() const {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (table[i] != nullptr) {
            return false;
        }
    }
    return true;
}

int HashTable::size() const {
    int count = 0;
    for (int i = 0; i < TABLE_SIZE; ++i) {
        HashNode* entry = table[i];
        while (entry != nullptr) {
            ++count;
            entry = entry->next;
        }
    }
    return count;
}
