//
// Created by jedsaxon on 19/09/23.
//

#include <iostream>
#include "Hasher.h"

unsigned int Hasher::Hash(void *key, int length) {
    unsigned char *p = static_cast<unsigned char *>(key);
    unsigned int h = 0x811c9dc5;
    for (int i = 0; i < length; i++) {
        h = (h ^ p[i] * 0x01000193);
    }
    return h;
}
