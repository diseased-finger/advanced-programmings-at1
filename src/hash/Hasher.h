// This is a C++ header file for a class named 'Hasher'.
// It contains the declaration of the 'Hash' function, which is intended for flexible hashing of any type of data.

// These preprocessor directives ensure that this header file is included only once in a compilation unit.
#ifndef ADVANCED_PROGRAMMINGS_AT1_HASHER_H
#define ADVANCED_PROGRAMMINGS_AT1_HASHER_H

class Hasher {
public:
    // Declaration of the 'Hash' function.
    // It takes a void pointer 'key' and an integer 'length' as parameters.
    // 'key' is a pointer to the data to be hashed, and 'length' specifies the length of the data.
    // The function returns an unsigned integer, which represents the hash value.
    unsigned int Hash(void *key, int length);
};

// End of the preprocessor directives.
#endif //ADVANCED_PROGRAMMINGS_AT1_HASHER_H
