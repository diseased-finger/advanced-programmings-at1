//
// Created by jedsaxon on 26/09/23.
//

#ifndef ADVANCED_PROGRAMMINGS_AT1_CONTACTLIST_H
#define ADVANCED_PROGRAMMINGS_AT1_CONTACTLIST_H


#include "../Contact.h"
#include "NodeList.h"

class ContactList : public NodeList<Contact> {
private:
    /// Finds the smallest age from an array of contacts
    /// \param arr The array of contacts to look through
    /// \param start The index to start looking through (starting at 0)
    /// \param length The length of the array
    /// \return The index of the youngest contact
    int FindSmallestFromSubset(Contact** arr, int start, int length);
    void SwapArrayElements(Contact* a, Contact* b);
public:
    void Sort();
    void LoopThroughNodes();
    void LoopThroughNodesReverse();
    void Search();
};


#endif //ADVANCED_PROGRAMMINGS_AT1_CONTACTLIST_H
