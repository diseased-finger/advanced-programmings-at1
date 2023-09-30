//
// Created by jedsaxon on 11/09/23.
//

#include "TreeQuestions.h"
#include "TreeNode.h"
#include "TreeIterator.h"

int TreeQuestions::Start() {
    // Creating Nodes
    TreeNode* layer3node1 = new TreeNode(Contact("Foo3-1", "Bar3-1", 3));
    TreeNode* layer3node2 = new TreeNode(Contact("Foo3-2", "Bar3-2", 4));
    TreeNode* layer3node3 = new TreeNode(Contact("Foo3-3", "Bar3-3", 5));
    TreeNode* layer3node4 = new TreeNode(Contact("Foo3-4", "Bar3-4", 6));

    TreeNode* layer2node1 = new TreeNode(Contact("Foo2-1", "Bar2-1", 1));
    TreeNode* layer2node2 = new TreeNode(Contact("Foo2-2", "Bar2-2", 2));

    TreeNode* layer1node1 = new TreeNode(Contact("Foo1-1", "Bar1-1", 0));
    layer1node1->SetLeftNode(layer2node1);
    layer1node1->SetRightNode(layer2node2);

    layer2node1->SetParentNode(layer1node1);
    layer2node1->SetLeftNode(layer3node1);
    layer2node1->SetRightNode(layer3node2);

    layer2node2->SetParentNode(layer1node1);
    layer2node2->SetLeftNode(layer3node3);
    layer2node2->SetRightNode(layer3node4);

    layer3node1->SetParentNode(layer2node1);
    layer3node2->SetParentNode(layer2node1);
    layer3node3->SetParentNode(layer2node2);
    layer3node4->SetParentNode(layer2node2);

    // Looping Through
    TreeIterator* iterator = new TreeIterator(layer1node1);
    iterator->PrintTrees();

    return 0;
}
