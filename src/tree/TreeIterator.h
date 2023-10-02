// This C++ header file defines the 'TreeIterator' class. The class appears to be designed for traversing a tree data structure and printing its elements.

#ifndef ADVANCED_PROGRAMMINGS_AT1_TREEITERATOR_H
#define ADVANCED_PROGRAMMINGS_AT1_TREEITERATOR_H

// Include the "TreeNode.h" header file, which is necessary for using TreeNode objects.
#include "TreeNode.h"

// Declare the TreeIterator class.
class TreeIterator {
private:
    TreeNode* current; // Pointer to the current node in the tree.

    // Private member function for recursively traversing the tree and printing its elements.
    void GetNextTreeRecursively(TreeNode *node);

public:
    // Constructor that initializes the TreeIterator with the top (root) node of the tree.
    TreeIterator(TreeNode* top) : current(top) { }

    // Public member function to initiate the tree traversal and printing process.
    void PrintTrees();
};

// End of the preprocessor directives.
#endif //ADVANCED_PROGRAMMINGS_AT1_TREEITERATOR_H
