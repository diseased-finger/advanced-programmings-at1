// This code defines a hash function implemented in C++.
// It takes a pointer to a key and its length as input and returns an unsigned integer hash value.

#include <iostream>
#include "Hasher.h"

// The Hasher class seems to contain the implementation of the hash function.

// This function calculates a hash value for the given key.
unsigned int Hasher::Hash(void *key, int length) {
    // Cast the 'key' pointer to an array of unsigned characters.
    unsigned char *p = static_cast<unsigned char *>(key);

    // Initialize the hash 'h' with a constant value, 0x811c9dc5.
    unsigned int h = 0x811c9dc5;

    // Iterate over each byte of the key.
    for (int i = 0; i < length; i++) {
        // Perform a bitwise XOR (^) operation between the current 'h' value and the current byte of the key
        // multiplied by another constant, 0x01000193.
        h = (h ^ p[i] * 0x01000193);
    }

    // Return the final hash value 'h'.
    return h;
}
