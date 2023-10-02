// This C++ code defines the functions within the 'TreeIterator' class. The class appears to be designed to traverse a tree data structure and print its elements.

#include <iostream>         // Include the input/output stream for printing.
#include "TreeIterator.h"   // Include the TreeIterator class definition.

// Function to recursively traverse the tree and print its elements.
void TreeIterator::GetNextTreeRecursively(TreeNode *node) {
    // Print the data stored in the current node.
    std::cout << node->GetData()->ToString() << std::endl;

    // If there is a left child node, recursively traverse it.
    if (node->GetLeftNode() != nullptr) {
        GetNextTreeRecursively(node->GetLeftNode());
    }

    // If there is a right child node, recursively traverse it.
    if (node->GetRightNode() != nullptr) {
        GetNextTreeRecursively(node->GetRightNode());
    }
}

// Function to initiate the tree traversal and printing process.
void TreeIterator::PrintTrees() {
    // Start the tree traversal from the 'current' node.
    GetNextTreeRecursively(current);
}
