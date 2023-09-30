//
// Created by jedsaxon on 26/09/23.
//

#include "ContactList.h"

void ContactList::SwapArrayElements(Contact* a, Contact* b) {
    Contact c = *a;
    *a = *b;
    *b = c;
}

int ContactList::FindSmallestFromSubset(Contact **arr, int start, int length) {
    int youngestIndex = -1; // Index of the youngest in the array
    int youngestAge = -1; // The age that the youngest is

    for (int i = start; i < length; i++) {
        if (youngestIndex == -1 && youngestAge == -1) {
            youngestIndex = i;
            youngestAge = arr[i]->GetAge();
            continue;
        }

        if (youngestAge >= arr[i]->GetAge()) {
            youngestAge = arr[i]->GetAge();
            youngestIndex = i;
            continue;
        }
    }

    return youngestIndex;
}

void ContactList::Sort() {
    Contact** arr = new Contact*[GetSize()];
    int i = 0;
    Node<Contact>* n = GetFirst();

    while (n != nullptr) {
        arr[i] = n->GetData();
        n = n->GetNextNode();
        i++;
    }

    // TODO - Could be in the while loop instead??
    // GetSize() - 1 because we don't want to swap the last element with itself
    for (int j = 0; j < GetSize() - 1; j++) {
        // Find the smallest of the elements IN FRONT of the current index (j)
        int smallestIndex = FindSmallestFromSubset(arr, j + 1, GetSize());

        // If arr[j] is greater than arr[smallestIndex], then continue
        // If the index == -1, that means that we should continue too
        if (arr[j]->GetAge() <= arr[smallestIndex]->GetAge()) {
            continue;
        }

        // Swap
        SwapArrayElements(arr[j], arr[smallestIndex]);
    }
}

void ContactList::LoopThroughNodesReverse() {
    int count = 0;
    std::cout << "Going From end -> 0" << std::endl;
    Node<Contact> *node = GetLast();
    std::cout << "[" << count << "]: " << node->GetData()->ToString() << std::endl;
    while (true) {
        Node<Contact> *previousNode = node->GetPreviousNode();

        if (previousNode == nullptr) {
            std::cout << std::endl << "Finished" << std::endl;
            break;
        }

        count++;
        std::cout << "[" << count << "]: " << previousNode->GetData()->ToString() << std::endl;
        node = previousNode;
    }
}

void ContactList::LoopThroughNodes() {
    std::cout << "Going From 0 -> end" << std::endl;
    int count = 0;
    Node<Contact> *node = GetFirst();
    std::cout << "[Element " << count << "]: " << node->GetData()->ToString() << std::endl;
    while (true) {
        Node<Contact> *nextNode = node->GetNextNode();

        if (nextNode == nullptr) {
            std::cout << std::endl << "There was a total of " << count + 1 << " elements in the list" << std::endl;
            break;
        }

        count++;
        std::cout << "[Element " << count << "]: " << nextNode->GetData()->ToString() << std::endl;
        node = nextNode;
    }
}

void ContactList::Search() {
    int age;
    std::cout << "Search Age: ";
    std::cin >> age;

    int i = 0;
    int found = 0;
    Node<Contact> *node = GetFirst();

    while (node != nullptr) {
        Contact* data = node->GetData();
        if (data->GetAge() == age) {
            std::cout << data->GetFirstName() << " " << data->GetLastName() << " is aged " << data->GetAge() << std::endl;
            found++;
        }

        node = node->GetNextNode();
    }
}