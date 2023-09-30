//
// Created by jedsaxon on 11/09/23.
//

#ifndef ADVANCED_PROGRAMMINGS_AT1_TREEITERATOR_H
#define ADVANCED_PROGRAMMINGS_AT1_TREEITERATOR_H


#include "TreeNode.h"

class TreeIterator {
private:
    TreeNode* current;
    void GetNextTreeRecursively(TreeNode *node);
public:
    TreeIterator(TreeNode* top) : current(top) { }
    void PrintTrees();
};


#endif //ADVANCED_PROGRAMMINGS_AT1_TREEITERATOR_H
