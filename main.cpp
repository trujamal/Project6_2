#include <iostream>
#include "Tree.h"
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(nullptr));
    int val,smallest_tree, biggest_tree, total;
    const int array_size = 1000;
    int r_val[array_size];
    int r_search[array_size];
    double avg;

    Tree b_tree;

    /**
     * Insert 1,000 nodes into the binary search tree
     * Temporarily set to 2
     */

    for (int i = 0; i < array_size; ++i) {
        val = rand() % 2000 + 1;
        r_val[i] = val;
        val = rand() % 2000 + 1;
        r_search[i] = val;
    }

    for (int j = 1; j < array_size; ++j) {
        b_tree.insert(r_val[j],r_val[j]);
    }

    /**
     * Display infomration within the tree
     */
    b_tree.printTree();
    std::cout << '\n';

    // Going through and printing the information relating to the height
    std::cout << "Height Tree: " << b_tree.height()+1 << endl;
    std::cout << "Height L Tree: " << b_tree.height(0) << endl;
    std::cout << "Height R Tree: " << -(b_tree.height(1)) << endl;

    std::pair<bool,int> searchT = b_tree.searchNode(r_search[0]);
    smallest_tree = searchT.second;
    biggest_tree = searchT.second;
    total = searchT.second;

    for (int n = 0; n < array_size; ++n) {
        std::pair<bool, int> search_b_tree = b_tree.searchNode(30);

        if(smallest_tree > search_b_tree.second)
            smallest_tree = search_b_tree.second;
        if(biggest_tree < search_b_tree.second)
            biggest_tree = search_b_tree.second;

        total += search_b_tree.second;
    }
    avg = static_cast<double>(total)/array_size;

    std::cout << "Minimum Comparisons: " << smallest_tree << endl;
    std::cout << "Maximum Comparisons: " << biggest_tree << endl;
    std::cout << "Time Complexity: " << avg << std::endl;

    std::cout << "\n Test Complete! \n";

    return 0;
}