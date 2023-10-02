// This C++ header file defines the 'TreeNode' class, which represents a node in a tree data structure.
// It includes data, left, right, and parent pointers for tree navigation.

#ifndef ADVANCED_PROGRAMMINGS_AT1_TREENODE_H
#define ADVANCED_PROGRAMMINGS_AT1_TREENODE_H

// Include the necessary headers for the TreeNode class.
#include <utility>      // Utility header for std::move
#include "../Contact.h" // Include the Contact class definition.

// Declare the TreeNode class.
class TreeNode {
private:
    Contact data;       // Data stored in the tree node.
    TreeNode* left;     // Pointer to the left child node.
    TreeNode* right;    // Pointer to the right child node.
    TreeNode* parent;   // Pointer to the parent node.

public:
    // Constructor that initializes the TreeNode with Contact data.
    TreeNode(Contact _data)
            : data(std::move(_data)) { }

    // Getter functions to access node attributes.
    Contact* GetData() { return &data; }
    TreeNode* GetLeftNode() { return left; }
    TreeNode* GetRightNode() { return right; }
    TreeNode* GetParentNode() { return parent; }

    // Setter functions to update child and parent pointers.
    void SetLeftNode(TreeNode *node) { left = node; }
    void SetRightNode(TreeNode *node) { right = node; }
    void SetParentNode(TreeNode *node) { parent = node; }
};

// End of the preprocessor directives.
#endif //ADVANCED_PROGRAMMINGS_AT1_TREENODE_H
