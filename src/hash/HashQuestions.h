// This is a C++ header file that defines the 'HashQuestions' class.
// The class appears to be related to a program that interacts with hash tables.

#ifndef ADVANCED_PROGRAMMINGS_AT1_HASHQUESTIONS_H
#define ADVANCED_PROGRAMMINGS_AT1_HASHQUESTIONS_H

// Include necessary headers for the class.
#include "../node/NodeList.h"  // Include the NodeList class definition.
#include "Hasher.h"            // Include the Hasher class definition.

class HashQuestions {
private:
    // Private member functions for internal use.

    // The InsertIntoList function inserts a hash value into the hash table.
    void InsertIntoList(NodeList<unsigned int>* list, Hasher* hasher);

    // The LoopList function lists elements in the hash table.
    void LoopList(NodeList<unsigned int>* list);

    // The Search function searches for a value in the hash table.
    bool Search(NodeList<unsigned int>* list, Hasher* hasher);

public:
    // Public member functions accessible from outside the class.

    // The Start function serves as the entry point of the program.
    int Start();

    // A template function for getting user input.
    template <typename T> T GetInput(const std::string& message);
};

// End of the preprocessor directives.
#endif //ADVANCED_PROGRAMMINGS_AT1_HASHQUESTIONS_H
