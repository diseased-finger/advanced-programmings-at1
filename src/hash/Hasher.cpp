//
// Created by jedsaxon on 8/10/23.
//

#include <string>
#include "Hasher.h"

/// Converts a char[] into a hash
unsigned int Hasher::Hash(void *key, int length) {
    unsigned char *p = static_cast<unsigned char *>(key);
    unsigned int h = 0x811c9dc5;

    for(int i = 0; i < length; i++) {
        h = (h ^ p[i]) * 0x01000193;
    }

    return h;
}

/// Uses the hash generated by Hasher::Hash, limiting the hash by the amount of keys inside the hash table
unsigned int Hasher::StringToHash(std::string const &key, unsigned int maxKeys) {
    char const* p = &key[0];
    unsigned int index = Hash((void *) p, key.size());
    return index % maxKeys;
}