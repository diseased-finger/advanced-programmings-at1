// This C++ header file defines a generic 'NodeList' class, which is used to manage a list of nodes.
// It includes functions for inserting nodes, accessing the first and last nodes, and getting the size of the list.

#ifndef ADVANCED_PROGRAMMINGS_AT1_NODELIST_H
#define ADVANCED_PROGRAMMINGS_AT1_NODELIST_H

// Include necessary headers.
#include <iostream>     // Include the input/output stream for debugging.
#include <memory>       // Include the memory header for smart pointers.
#include "Node.h"       // Include the Node class definition.

// Define a generic NodeList class using a template.
template <typename T>
class NodeList {
private:
    Node<T>* first;     // Pointer to the first node in the list.
    Node<T>* last;      // Pointer to the last node in the list.
    int size;           // The size of the list (number of nodes).

    // Private member function to recursively destroy nodes starting from the given node.
    void DestroyNodeRecursive(Node<T> *firstNode) {
        /* If there is a previous node, it will call this same function to delete it. If that node also has a previous
         * one, it will be deleted too. This means that this function will end up being called for each node in the
         * list. Once it reaches the end of the list, it will delete the node and then get out of the function, meaning
         * the node in front of it will be deleted, and it goes on until all nodes have been deleted
         */

        if (firstNode->GetPreviousNode()) {
            DestroyNodeRecursive(firstNode->GetPreviousNode());
        }

        // Delete the firstNode after deleting the previous one.
        std::cout << "Deleting Node";
        delete firstNode;
    }

    // Private member function to destroy all nodes in the list.
    void Destroy() {
        Node<T> *lastNode = GetLast();
        DestroyNodeRecursive(lastNode);
    }

public:
    // Destructor that destroys all nodes in the list when the NodeList object is destroyed.
    ~NodeList() {
        Destroy();
    }

    // Function to get a pointer to the first node in the list.
    Node<T>* GetFirst() { return first; }

    // Function to get a pointer to the last node in the list.
    Node<T>* GetLast() { return last; }

    // Function to get the size (number of nodes) in the list.
    int GetSize() { return size; }

    // Function to insert a new node into the list.
    void Insert(Node<T>* newNode) {
        // If nothing is in the list, set the first node (not the last).
        if (first == nullptr) {
            first = std::move(newNode);
            size++;
            return;
        }

        // If there's only one element in the list (the first node), set the first node's next node to the new one,
        // and also set the new one as the last node.
        if (last == nullptr) {
            first->SetNextNode(newNode);
            newNode->SetPreviousNode(first);
            last = std::move(newNode);
            size++;
            return;
        }

        newNode->SetPreviousNode(last); // Current Last now has one in front of it!
        last->SetNextNode(newNode);     // Current Last points to the new node.
        last = newNode;                 // Update the new last node.
        size++;
    }
};

// End of the preprocessor directives.
#endif //ADVANCED_PROGRAMMINGS_AT1_NODELIST_H
