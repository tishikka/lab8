#include "HashFunction.h"

unsigned int customHash(const std::string& name) {
    unsigned int hash = 0;
    for (char c : name) {
        hash = hash * 31 + c;
    }
    return hash;
}