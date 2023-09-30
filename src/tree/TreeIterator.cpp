//
// Created by jedsaxon on 11/09/23.
//

#include <iostream>
#include "TreeIterator.h"

void TreeIterator::GetNextTreeRecursively(TreeNode *node) {
    std::cout << node->GetData()->ToString() << std::endl;

    if (node->GetLeftNode() != nullptr) {
        GetNextTreeRecursively(node->GetLeftNode());
    }

    if (node->GetRightNode() != nullptr) {
        GetNextTreeRecursively(node->GetRightNode());
    }
}

void TreeIterator::PrintTrees() {
    GetNextTreeRecursively(current);
}
