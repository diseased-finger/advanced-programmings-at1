//
// Created by jedsaxon on 8/10/23.
//

#ifndef ADVANCED_PROGRAMMINGS_AT1_HASHER_H
#define ADVANCED_PROGRAMMINGS_AT1_HASHER_H


class Hasher {
public:
    /// Hashes a string object.
    /// @param key Memory address of the first character for the string to hash
    /// @param length Length of the string
    unsigned int Hash(void *key, int length);

    /// Converts string into hash
    unsigned int StringToHash(const std::string &key, unsigned int maxKeys);
};


#endif //ADVANCED_PROGRAMMINGS_AT1_HASHER_H
