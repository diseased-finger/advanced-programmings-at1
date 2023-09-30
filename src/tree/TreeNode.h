//
// Created by jedsaxon on 11/09/23.
//

#ifndef ADVANCED_PROGRAMMINGS_AT1_TREENODE_H
#define ADVANCED_PROGRAMMINGS_AT1_TREENODE_H


#include <utility>

#include "../Contact.h"

class TreeNode {
private:
    Contact data;

    // Underneath the tree node, there will be 2 more. This would be the left and right nodes
    TreeNode* left;
    TreeNode* right;

    // The parent node is the one above this node
    TreeNode* parent;
public:
    TreeNode(Contact _data)
        : data(std::move(_data)) { }

    Contact* GetData() { return &data; }
    TreeNode* GetLeftNode() { return left; }
    TreeNode* GetRightNode() { return right; }
    TreeNode* GetParentNode() { return parent; }

    void SetLeftNode(TreeNode *node) { left = node; }
    void SetRightNode(TreeNode *node) { right = node; }
    void SetParentNode(TreeNode *node) { parent = node; }
};


#endif //ADVANCED_PROGRAMMINGS_AT1_TREENODE_H
