// This C++ header file defines a generic 'Node' structure that can be used in linked data structures like lists.
// It includes functions to set and retrieve data, previous and next nodes.

#ifndef ADVANCED_PROGRAMMINGS_AT1_NODE_H
#define ADVANCED_PROGRAMMINGS_AT1_NODE_H

// Include necessary headers.
#include <utility>      // Include the utility header for std::move.

// Include the Contact class definition.
#include "../Contact.h"

// Define a generic Node structure using a template.
template <typename T>
struct Node {
private:
    T data;                 // The data stored in the node.

    Node<T>* previous{};    // Pointer to the previous node (if used in a linked structure).
    Node<T>* next{};        // Pointer to the next node (if used in a linked structure).

public:
    // Destructor (empty as there's no dynamic memory allocation).

    // Constructor to initialize the node with data.
    Node(T data_) : data(data_) {}

    // Function to get a pointer to the data stored in the node.
    T* GetData() { return &data; }

    // Function to get a pointer to the previous node (if used in a linked structure).
    Node<T>* GetPreviousNode() { return previous; }

    // Function to get a pointer to the next node (if used in a linked structure).
    Node<T>* GetNextNode() { return next; }

    // Function to set new data for the node.
    void SetData(T newData) { data = newData; }

    // Function to set the previous node (if used in a linked structure).
    void SetPreviousNode(Node<T>* newPrevious) { previous = std::move(newPrevious); }

    // Function to set the next node (if used in a linked structure).
    void SetNextNode(Node<T>* newNext) { next = std::move(newNext); }
};

// End of the preprocessor directives.
#endif //ADVANCED_PROGRAMMINGS_AT1_NODE_H
