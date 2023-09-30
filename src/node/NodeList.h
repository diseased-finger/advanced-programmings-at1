//
// Created by jedsaxon on 3/09/23.
//

#ifndef ADVANCED_PROGRAMMINGS_AT1_NODELIST_H
#define ADVANCED_PROGRAMMINGS_AT1_NODELIST_H


#include <iostream>
#include <memory>
#include "Node.h"

template <typename T>
class NodeList {
private:
    Node<T>* first; // In the list, the first node is the one at index 0, or on the far left side of the list
    Node<T>* last; // In the list, the first node is the one at the size of the list, or on the far right side of the list
    int size;

    void DestroyNodeRecursive(Node<T> *firstNode) {
        /* If there is a previous node, it will call this same function to delete it. If that node also has a previous
         * one, it will be deleted too. This means that this function will end up being called for each node in the
         * list. Once it reaches the end of the list, it will delete the node and then get out of the function, meaning
         * the node in front of it will be deleted, and it goes on until all nodes have been deleted
         */

        if (firstNode->GetPreviousNode()) {
            DestroyNodeRecursive(firstNode->GetPreviousNode());
        }

        // Delete the firstNode after deleting the pevious one
        std::cout << "Deleting Node";
        delete firstNode;
    }

    void Destroy() {
        Node<T> *lastNode = GetLast();
        DestroyNodeRecursive(lastNode);
    }
public:
    ~NodeList() {
        Destroy();
    }

    Node<T>* GetFirst() { return first; }

    Node<T>* GetLast() { return last; }

    int GetSize() { return size; }

    void Insert(Node<T>* newNode) {
        // Nothing in the list. Set the first node (not the last)
        if (first == nullptr) {
            first = std::move(newNode);
            size++;
            return;
        }

        // Only 1 element in the list, the first node. Set the first node's next node to the new one, and also set the new
        // one as the last node
        if (last == nullptr) {
            first->SetNextNode(newNode);
            newNode->SetPreviousNode(first);
            last = std::move(newNode);
            size++;
            return;
        }

        newNode->SetPreviousNode(last); // Current Last now has one in front of it!
        last->SetNextNode(newNode); // Current Last
        last = newNode; // New Last
        size++;
    }
};


#endif //ADVANCED_PROGRAMMINGS_AT1_NODELIST_H