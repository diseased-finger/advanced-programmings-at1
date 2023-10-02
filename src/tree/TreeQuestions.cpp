// This C++ code appears to be a part of a program that creates a tree data structure consisting of TreeNode objects,
// and then it uses a TreeIterator to traverse and print the elements of the tree.

#include "TreeQuestions.h" // Include the TreeQuestions class definition.
#include "TreeNode.h"      // Include the TreeNode class definition.
#include "TreeIterator.h"  // Include the TreeIterator class definition.

// Function to start the TreeQuestions program.
int TreeQuestions::Start() {
    // Creating Nodes: Create TreeNode objects for the tree structure.
    TreeNode* layer3node1 = new TreeNode(Contact("Foo3-1", "Bar3-1", 3));
    TreeNode* layer3node2 = new TreeNode(Contact("Foo3-2", "Bar3-2", 4));
    TreeNode* layer3node3 = new TreeNode(Contact("Foo3-3", "Bar3-3", 5));
    TreeNode* layer3node4 = new TreeNode(Contact("Foo3-4", "Bar3-4", 6));

    TreeNode* layer2node1 = new TreeNode(Contact("Foo2-1", "Bar2-1", 1));
    TreeNode* layer2node2 = new TreeNode(Contact("Foo2-2", "Bar2-2", 2));

    TreeNode* layer1node1 = new TreeNode(Contact("Foo1-1", "Bar1-1", 0));

    // Set relationships between nodes to build the tree structure.
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

    // Looping Through: Create a TreeIterator and print the tree elements.
    TreeIterator* iterator = new TreeIterator(layer1node1);
    iterator->PrintTrees();

    return 0;
}
