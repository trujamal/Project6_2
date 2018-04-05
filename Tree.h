//
// Created by Greg LaKomski on 3/20/18.
//

#ifndef PROJECT6_2_TREE_H
#define PROJECT6_2_TREE_H


#include<utility>
#include<iostream>

using std::cout;
using std::endl;


// Note the nested classes - look this up!
// I could have added parent pointers to make deletion more efficient
// The node class will have both the key and an associated value you can carry with. Should remind you of a MAP or SET.
class Tree {
private:

    /**
     * Subclass of type Node
     */

    class Node {
    private:

        Node * left;
        Node * right;
        int key;
        int value;

    public:

        Node(int key, int value ) {
            this->key = key;
            this->value = value;
            this->left = NULL;
            this->right = NULL;
        }

        Node(int key, int value, Node* _left, Node* _right) {
            this->key = key;
            this->value = value;
            this->left = _left;
            this->right = _right;
        }

        friend class Tree;
    };

    /**
     * Helper Function for insert
     * COMPLETE!!
     * @param y
     * @param head
     * @return
     */
    Node * BSTInsert(Node* y, Node * head) {
        if (head == NULL) {
            head = y; //Stack error? :(
        }

        if(y->key < head->key)
            if(head->left !=NULL)
                BSTInsert(y,head->left);
            else
                if(head->key!=y->key)
                    head->left = y;
        else if(y->key >= head->key)
            if(head->right != NULL)
                BSTInsert(y, head->right);
            else
                if(head->key!=y->key)
                    head->right =y;
        return head;
    }

    /**
     * Helper function for search
     * Complete!!!!!!
     * @param node
     * @param key
     * @return
     */
    std::pair<bool,int> binary_tree_search(std::pair<bool,int> search_N, Node *node, int key) {
        if(node != NULL){
            if(key == node->key){
                search_N.first = true;
                search_N.second++;
                return search_N;
            }
            if(key < node->key){
                search_N.second++;
                return binary_tree_search(search_N, node->left, key);
            }else{
                search_N.second++;
                return binary_tree_search(search_N, node->right, key);
            }
        }else{
            search_N.first = false;
            return search_N;
        }
    }

    /**
     * Helper function for height
     * COMPLETE!!!
     * @param node
     * @return
     */
    int parse_height(Node* node) {
        if (node==NULL)
            return -1;

        int left_depth = parse_height(node->left);
        int right_depth = parse_height(node->right);

            /* use the larger one */
        if (left_depth > right_depth) {return(left_depth+1);}
        else {return(right_depth+1);}
    }

    /**
     * printInOrder: Helper function for printTree
     * COMPLETE!!!
     * Will print out the information by doing left -> print -> right
     * @param node
     */

    void printInOrder(Node * node)
    {
        if (node == NULL)
            return;
        else {
            printInOrder(node->left); // Will first handle the left side of the tree
            std::cout << node->value << "' "; // Will print out the value at that certain part
            printInOrder(node->right); // Will handle the right hand side of the tree
        }
    }

    // this is part of the Tree class
    Node * head;

public:

    Tree() { head = NULL; }

    Node * createNode(int key, int value){
        Node * temp = new Node(key,value);
        return temp;
    }

    //Prints the keys for the tree in inorder mode
    // Helper function in private section
    void printTree(){
        printInOrder(this->head);
    }

    //Inserts a node into the tree
    // Helper function in private section
    void insert(const int key, const int value){
        Node * temp = new Node(key,value);
        this->head = BSTInsert(temp,this->head);
    }

    //Finds a node with a specific key, returns TRUE or FALSE and the # of compares done. - a pair.
    // Helper function in private section
    std::pair<bool,int> searchNode(int key){

        std::pair <bool, int> creation_pair;
        creation_pair.first = false;
        creation_pair.second = 0; // Default Value

        return binary_tree_search(creation_pair,head,key);
    }

    // Default height constructor
    int height() {
        return parse_height(head);
    }

    // Good old height function that takes in the int values
    int height(int other_trees) {
        if(other_trees == 0)
            return parse_height(head->left);
        return parse_height(head->right);
    }


};



#endif //PROJECT6_2_TREE_H
