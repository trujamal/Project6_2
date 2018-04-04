#include <iostream>
#include "Tree.h"
#include <stdlib.h>

int main() {
    Tree binary_tree;

    /**
     * Insert 1,000 nodes into the binary search tree
     */
    for (int i = 0; i < 1000; ++i) {
        int random_integer = rand() % 2000 + 1; // Randomly generate a value between 1 and 2,000
        binary_tree.insert(i,random_integer);
    }

    binary_tree.printTree();

    /**
     * Printing out contents of the tree
     */
    std::cout << "Process has completed \n Now getting the height of the overall tree: " << std::endl;
    binary_tree.height();



    return 0;
}