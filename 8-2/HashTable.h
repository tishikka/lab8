#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>

class HashTable {
private:
    static const int TABLE_SIZE = 10;

    struct HashNode {
        std::string key;
        double value;
        HashNode* next;

        HashNode(const std::string& key, double value) 
            : key(key), value(value), next(nullptr) {}
    };

    HashNode* table[TABLE_SIZE];

    int hashFunction(const std::string& key) const;
    HashNode* searchNode(const std::string& key) const;

public:
    HashTable();
    ~HashTable();

    void add(const std::string& key, double value);
    bool remove(const std::string& key);
    bool find(const std::string& key, double& value) const;
    bool isEmpty() const;
    int size() const;
};

#endif
