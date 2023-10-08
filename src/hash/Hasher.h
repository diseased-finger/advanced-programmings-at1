//
// Created by jedsaxon on 8/10/23.
//

#ifndef ADVANCED_PROGRAMMINGS_AT1_HASHER_H
#define ADVANCED_PROGRAMMINGS_AT1_HASHER_H


class Hasher {
public:
    unsigned int Hash(void *key, int length);

    unsigned int StringToHash(const std::string &key, unsigned int maxKeys);
};


#endif //ADVANCED_PROGRAMMINGS_AT1_HASHER_H
