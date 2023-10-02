// This C++ header file defines a class called 'ContactList' which appears to be used to manage a list of contacts.
// It includes functions for sorting, looping through nodes, and searching for contacts.

#ifndef ADVANCED_PROGRAMMINGS_AT1_CONTACTLIST_H
#define ADVANCED_PROGRAMMINGS_AT1_CONTACTLIST_H

// Include necessary headers.
#include "../Contact.h"    // Include the Contact class definition.
#include "NodeList.h"       // Include the NodeList class definition.

class ContactList : public NodeList<Contact> {
private:
    // Private member functions for internal use.

    /// Finds the smallest age from an array of contacts.
    /// \param arr The array of contacts to look through.
    /// \param start The index to start looking through (starting at 0).
    /// \param length The length of the array.
    /// \return The index of the youngest contact.
    int FindSmallestFromSubset(Contact** arr, int start, int length);

    // Function to swap elements of type Contact.
    void SwapArrayElements(Contact* a, Contact* b);

public:
    // Public member functions accessible from outside the class.

    // Function to sort the contact list by age.
    void Sort();

    // Function to loop through the nodes of the contact list in order and print contact information.
    void LoopThroughNodes();

    // Function to loop through the nodes of the contact list in reverse order and print contact information.
    void LoopThroughNodesReverse();

    // Function to search for contacts by age.
    void Search();
};

// End of the preprocessor directives.
#endif //ADVANCED_PROGRAMMINGS_AT1_CONTACTLIST_H
