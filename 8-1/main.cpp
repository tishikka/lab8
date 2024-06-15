#include "HashFunction.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::vector<std::string> votedNames;
std::vector<unsigned int> votedHashes;
int duplicateCount = 0;

void enrolled(const std::string& filename) {
    std::ifstream file(filename);
    std::string name;
    while (std::getline(file, name)) {
        unsigned int hashValue = customHash(name);
        bool isDuplicate = false;
        for (unsigned int hash : votedHashes) {
            if (hash == hashValue) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            votedNames.push_back(name);
            votedHashes.push_back(hashValue);
        } else {
            duplicateCount++;
        }
    }
}

void unenrolled(const std::string& name) {
    unsigned int hashValue = customHash(name);
    bool isDuplicate = false;
    for (unsigned int hash : votedHashes) {
        if (hash == hashValue) {
            isDuplicate = true;
            break;
        }
    }
    if (!isDuplicate) {
        votedNames.push_back(name);
        votedHashes.push_back(hashValue);
    } else {
        duplicateCount++;
    }
}

void printResults() {
    std::cout << "Number of voters: " << votedNames.size() << std::endl;
    std::cout << "Number of duplicates: " << duplicateCount << std::endl;
    std::cout << "Voters: " << std::endl;
    for (const auto& name : votedNames) {
        std::cout << name << std::endl;
    }
}

int main() {
    std::string filename = "students.txt";
    enrolled(filename);

    std::string name;
    while (true) {
        std::cout << "Enter a surname (or 'end' to finish): ";
        std::getline(std::cin, name);
        if (name == "end") {
            break;
        }
        unenrolled(name);
    }

    printResults();
    return 0;
}