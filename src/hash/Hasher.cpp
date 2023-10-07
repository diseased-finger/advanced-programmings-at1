//
// Created by jedsaxon on 8/10/23.
//

#include "Hasher.h"

unsigned long Hasher::Hash(void *key, int length) {
    unsigned char *p = static_cast<unsigned char *>(key);
    unsigned int h = 0x811c9dc5;

    for (int i = 0; i < length; i++) {
        h = (h ^ p[i]) * 0x01000193;
    }

    return h;
}
