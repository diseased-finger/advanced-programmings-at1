//
// Created by jedsaxon on 19/09/23.
//

#include <string>
#include <iostream>
#include "HashQuestions.h"
#include "Hasher.h"

int HashQuestions::Start() {
    NodeList<unsigned int>* hashedList = new NodeList<unsigned int>();
    Hasher* hasher = new Hasher();

    while (true) {
        std::cout << std::endl;
        int option = GetInput<int>("Please enter an option:\n1 - Insert\n2 - List\n3 - Search\n4 - Quit\n");
        std::cout << std::endl;
        switch (option) {
            case 1: {
                InsertIntoList(hashedList, hasher);
                break;
            }
            case 2: {
                LoopList(hashedList);
                break;
            }
            case 3: {
                bool foundValue = Search(hashedList, hasher);
                printf(foundValue ? "That word was found in the list!" : "That word doesn't exist");
                break;
            }
            case 4: {
                hashedList->~NodeList();
                return 0;
            }
            default: {
                printf("That is an invalid option. Please enter a number between 1 - 4");
                break;
            }
        }
    }

    return 0;
}

bool HashQuestions::Search(NodeList<unsigned int>* list, Hasher* hasher) {
    std::string query = std::move(GetInput<std::string>("Enter Query: "));
    unsigned int hashedQuery = hasher->Hash(&query.at(0), query.size());

    Node<unsigned int>* n = list->GetFirst();
    int size = 0;
    while (n != nullptr) {
        unsigned int derefData = *(n->GetData());
        if (derefData == hashedQuery) {
            return true;
        }
        n = n->GetNextNode();
    }
    return false;
}

template <typename T>
T HashQuestions::GetInput(const std::string& message) {
    std::cout << message;
    T output;
    std::cin >> output;
    return output;
}

void HashQuestions::InsertIntoList(NodeList<unsigned int>* list, Hasher* hasher) {
    std::string strToInsert = std::move(GetInput<std::string>("Enter string to insert into the list: "));
    unsigned int hash = hasher->Hash(&strToInsert.at(0), strToInsert.size());
    std::cout << hash << std::endl;
    list->Insert(new Node<unsigned int>(hash));
}

void HashQuestions::LoopList(NodeList<unsigned int> *list) {
    Node<unsigned int>* n = list->GetFirst();
    int size = 0;
    while (n != nullptr) {
        unsigned int derefData = *(n->GetData());
        std::cout << "Element [" << size << "] = " << derefData << "\n";
        n = n->GetNextNode();
    }
}