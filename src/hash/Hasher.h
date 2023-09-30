//
// Created by jedsaxon on 19/09/23.
//

#ifndef ADVANCED_PROGRAMMINGS_AT1_HASHER_H
#define ADVANCED_PROGRAMMINGS_AT1_HASHER_H


class Hasher {
public:
    // We use a void pointer because this function should be flexible with hashing any type.
    unsigned int Hash(void *key, int length);
};


#endif //ADVANCED_PROGRAMMINGS_AT1_HASHER_H
