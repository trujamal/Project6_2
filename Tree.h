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

    // this is part of the Tree class
    Node * head;

    /**
     * Helper Function for insert
     * COMPLETE!!
     * @param y
     * @param head
     * @return
     */
    Node * BSTInsert(Node* y, Node * head) {
        if (head == NULL) {
            //sets the head value to the y value then sets it to be the only leaf
            Node *a = new Node(y->key,y->value);
            Tree::setHead(a);
            return head;
        }

        if(y->value < Tree::head->value)
            head->left = BSTInsert(head->left,y);
        if(y->value > Tree::head->value)
            head->right = BSTInsert(Tree::head->right,y);

        printTree();
        return head;
    }

    /**
     * Helper function for search
     * Complete!!!!!!
     * @param node
     * @param key
     * @return
     */
    Node* binary_search(Node* node, int key)
    {
        /**
         * Checking for base case if its NULL or the same information
         */
        if (node == NULL || node->key == key)
            return node;

        // Key is greater than root's key
        if (node->key < key)
            return binary_search(node->right, key);

        // Key is smaller than root's key
        return binary_search(node->left, key);
    }


    /**
     * Helper function for height
     * COMPLETE!!!
     * @param node
     * @return
     */
    int parse_height(Node* node) {
        if (node==NULL)
            return 0;
        else
        {
            int left_depth = parse_height(node->left);
            int right_depth = parse_height(node->right);

            /* use the larger one */
            if (left_depth > right_depth)
                return(left_depth+1);
            else return(right_depth+1);
        }
        return 0;
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

        printInOrder(node->left); // Will first handle the left side of the tree

        std::cout << node->value << "' "; // Will print out the value at that certain part

        printInOrder(node->right); // Will handle the right hand side of the tree

    }

public:

    Tree() { head = NULL; }

    Node * createNode(int key, int value){
        Node * temp = new Node(key,value);
        return temp;
    }

    //Prints the keys for the tree in inorder mode
    // Helper function in private section
    void printTree(){
        printInOrder(head);
    }

    //Inserts a node into the tree
    // Helper function in private section
    void insert(const int key, const int value){
        Node * temp = createNode(key,value);
        this->head = BSTInsert(temp,this->head);
    }

    //Finds a node with a specific key, returns TRUE or FALSE and the # of compares done. - a pair.
    // Helper function in private section
    std::pair<bool,int> searchNode(int key){

        bool if_found = BST_search_Helper(head, key);
        std::pair<bool,int> creation_of_pair;
        creation_of_pair.first = if_found;
        creation_of_pair.second = key;
        return creation_of_pair;
    }

    /**
     * @function height
     * COMPLETE!!!
     * Designed to print out the information from the parse_height helper function
     */
    void height(){
        std::cout << parse_height(this->head) << std::endl;
    }

    /**
     * kvp_helper
     * add create a node with key, value and both pointers
     * Complete!!
     * @param key
     * @param value
     * @param _left
     * @param _right
     * @return
     */
    Node * kvp_helper(int key, int value,Node* _left, Node* _right){
        Node * temp = new Node(key,value, _left,_right);
        return temp;
    }

    bool BST_search_Helper(Node * _node,int _key){
        return _node == binary_search(_node, _key);
    }

    Node *getHead() const {
        return head;
    }

    void setHead(Node *head) {
        Tree::head = head;
    }

};



#endif //PROJECT6_2_TREE_H
