//
// Created by jedsaxon on 19/09/23.
//

#ifndef ADVANCED_PROGRAMMINGS_AT1_HASHQUESTIONS_H
#define ADVANCED_PROGRAMMINGS_AT1_HASHQUESTIONS_H


#include "../node/NodeList.h"
#include "Hasher.h"

class HashQuestions {
private:
    void InsertIntoList(NodeList<unsigned int>* list, Hasher* hasher);
    void LoopList(NodeList<unsigned int>* list);
    bool Search(NodeList<unsigned int>* list, Hasher* hasher);
public:
    int Start();
    template <typename T> T GetInput(const std::string& message);
};


#endif //ADVANCED_PROGRAMMINGS_AT1_HASHQUESTIONS_H
