//
// Created by jedsaxon on 3/09/23.
//

#ifndef ADVANCED_PROGRAMMINGS_AT1_NODE_H
#define ADVANCED_PROGRAMMINGS_AT1_NODE_H


#include <utility>

#include "../Contact.h"

template <typename T>
struct Node {
private:
    T data;

    // In a list, the previous would be the one to the left of this node
    Node<T>* previous{};

    // In a list, the next would be the one to the right of this node
    Node<T>* next{};
public:
    ~Node() { }
    //explicit Node(Contact data) : data(std::move(data)) { }

    Node(T data_) : data(data_) {}

    T* GetData() { return &data; }
    Node<T>* GetPreviousNode() { return previous; }
    Node<T>* GetNextNode() { return next; }

    void SetData(T newData) { data = newData; }
    void SetPreviousNode(Node<T>* newPrevious) { previous = std::move(newPrevious); }
    void SetNextNode(Node<T>* newNext) { next = std::move(newNext); }
};


#endif //ADVANCED_PROGRAMMINGS_AT1_NODE_H