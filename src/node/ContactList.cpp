// This C++ code appears to be part of a ContactList class implementation.
// The class provides functions for sorting and searching contact information.

#include "ContactList.h"

// Function to swap elements of type Contact.
void ContactList::SwapArrayElements(Contact* a, Contact* b) {
    Contact c = *a;
    *a = *b;
    *b = c;
}

// Function to find the index of the youngest contact in a subset of the array.
int ContactList::FindSmallestFromSubset(Contact **arr, int start, int length) {
    int youngestIndex = -1; // Index of the youngest contact in the array
    int youngestAge = -1;   // The age of the youngest contact

    for (int i = start; i < length; i++) {
        // Initialize the youngestIndex and youngestAge if not already set.
        if (youngestIndex == -1 && youngestAge == -1) {
            youngestIndex = i;
            youngestAge = arr[i]->GetAge();
            continue;
        }

        // Update the youngestAge and youngestIndex if a younger contact is found.
        if (youngestAge >= arr[i]->GetAge()) {
            youngestAge = arr[i]->GetAge();
            youngestIndex = i;
            continue;
        }
    }

    return youngestIndex;
}

// Function to sort the contact list by age using selection sort.
void ContactList::Sort() {
    // Create an array of Contact pointers to store contact references.
    Contact** arr = new Contact*[GetSize()];
    int i = 0;
    Node<Contact>* n = GetFirst();

    // Populate the array with contact references.
    while (n != nullptr) {
        arr[i] = n->GetData();
        n = n->GetNextNode();
        i++;
    }

    // Selection sort: Iterate through the array to find the youngest contact and swap.
    for (int j = 0; j < GetSize() - 1; j++) {
        // Find the index of the youngest contact in the subset of the array.
        int smallestIndex = FindSmallestFromSubset(arr, j + 1, GetSize());

        // If arr[j] is younger than arr[smallestIndex], swap them.
        if (arr[j]->GetAge() <= arr[smallestIndex]->GetAge()) {
            continue; // No need to swap, move to the next iteration.
        }

        // Swap the elements.
        SwapArrayElements(arr[j], arr[smallestIndex]);
    }

    // Clean up memory by deallocating the temporary array.
    delete[] arr;
}

// Function to loop through the nodes of the contact list in reverse order and print contact information.
void ContactList::LoopThroughNodesReverse() {
    int count = 0;
    std::cout << "Going From end -> 0" << std::endl;
    Node<Contact> *node = GetLast();

    // Print the last contact in the list.
    std::cout << "[" << count << "]: " << node->GetData()->ToString() << std::endl;

    while (true) {
        Node<Contact> *previousNode = node->GetPreviousNode();

        if (previousNode == nullptr) {
            std::cout << std::endl << "Finished" << std::endl;
            break;
        }

        count++;

        // Print the contact information.
        std::cout << "[" << count << "]: " << previousNode->GetData()->ToString() << std::endl;
        node = previousNode;
    }
}

// Function to loop through the nodes of the contact list in order and print contact information.
void ContactList::LoopThroughNodes() {
    std::cout << "Going From 0 -> end" << std::endl;
    int count = 0;
    Node<Contact> *node = GetFirst();

    // Print the first contact in the list.
    std::cout << "[Element " << count << "]: " << node->GetData()->ToString() << std::endl;

    while (true) {
        Node<Contact> *nextNode = node->GetNextNode();

        if (nextNode == nullptr) {
            std::cout << std::endl << "There was a total of " << count + 1 << " elements in the list" << std::endl;
            break;
        }

        count++;

        // Print the contact information.
        std::cout << "[Element " << count << "]: " << nextNode->GetData()->ToString() << std::endl;
        node = nextNode;
    }
}

// Function to search for contacts by age.
void ContactList::Search() {
    int age;
    std::cout << "Search Age: ";
    std::cin >> age;

    int i = 0;
    int found = 0;
    Node<Contact> *node = GetFirst();

    // Iterate through the list and print contacts with the specified age.
    while (node != nullptr) {
        Contact* data = node->GetData();
        if (data->GetAge() == age) {
            std::cout << data->GetFirstName() << " " << data->GetLastName() << " is aged " << data->GetAge() << std::endl;
            found++;
        }

        node = node->GetNextNode();
    }
}
