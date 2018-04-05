#include <iostream>
#include "Tree.h"
#include <stdlib.h>
#include <time.h>

int main() {
    Tree binary_tree;
    srand( time(0));

    /**
     * Insert 1,000 nodes into the binary search tree
     * Temporarily set to 2
     */
    for (int i = 0; i < 4; ++i) {
        int random_integer = (rand() % 2000) + 1; // Randomly generate a value between 1 and 2,000
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