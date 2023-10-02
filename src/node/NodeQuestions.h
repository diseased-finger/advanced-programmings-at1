// This C++ header file defines the 'NodeQuestions' class, which appears to be a part of a program
// that interacts with a list of nodes, specifically designed for managing contacts.

#ifndef ADVANCED_PROGRAMMINGS_AT1_NODEQUESTIONS_H
#define ADVANCED_PROGRAMMINGS_AT1_NODEQUESTIONS_H

// Include the "NodeList.h" header file, which is likely used within this class.
#include "NodeList.h"

// Declare the NodeQuestions class.
class NodeQuestions {
public:
    // Function to get a valid number input from the user within a specified range.
    int GetNumberFromUser(const std::string& message, const std::string& errorMessage, int min, int max);

    // Function to create a new Node<Contact> based on user input.
    Node<Contact>* CreateNode();

    // Function to start the NodeQuestions program.
    int Start();
};

// End of the preprocessor directives.
#endif //ADVANCED_PROGRAMMINGS_AT1_NODEQUESTIONS_H
