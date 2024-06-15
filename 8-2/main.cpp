#include "HashTable.h"
#include <iostream>

int main() {
    HashTable ht;

    ht.add("wood", 1500);
    ht.add("steel", 2900);
    ht.add("concrete", 4900);

    double price;
    if (ht.find("steel", price)) {
        std::cout << "Price of steel:" << price << std::endl;
    } else {
        std::cout << "Steel not found in the hash table." << std::endl;
    }

    if (ht.remove("wood")) {
        std::cout << "Wood removed from the hash table." << std::endl;
    } else {
        std::cout << "Wood not found in the hash table." << std::endl;
    }

    if (ht.isEmpty()) {
        std::cout << "Hash table is empty." << std::endl;
    } else {
        std::cout << "Hash table is not empty." << std::endl;
    }

    std::cout << "Size of hash table: " << ht.size() << std::endl;

    return 0;
}
