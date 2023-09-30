//
// Created by jedsaxon on 11/09/23.
//

#ifndef ADVANCED_PROGRAMMINGS_AT1_NODEQUESTIONS_H
#define ADVANCED_PROGRAMMINGS_AT1_NODEQUESTIONS_H


#include "NodeList.h"

class NodeQuestions {
public:
    int GetNumberFromUser(const std::string& message, const std::string& errorMessage, int min, int max);
    Node<Contact>* CreateNode();
    int Start();
};


#endif //ADVANCED_PROGRAMMINGS_AT1_NODEQUESTIONS_H
