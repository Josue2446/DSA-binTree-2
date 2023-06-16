// FILE: bst.h
// define Binary Search Tree class (Bst)

#include "node.h"
#include <utility> // exchange()
#ifndef BST_H
#define BST_H

class Bst{
    public:
        Bst() : root{nullptr}{}
        // move constructor
        Bst(Bst&& rhs)noexcept : root{std::exchange(rhs.root,nullptr)} {}

        void insert_node(Node* cursor, int val);
        // printing DFS methods
        void print_preorder(Node* cursor)const;
        void print_inorder(Node* cursor)const;
        void print_postorder(Node* cursor)const;
        // printing BFS method
        void print_breadth(Node* cursor)const;

        Node* delete_node(Node* cursor, int val);

        void set_root(Node* temp){root = temp;}
        Node* get_root(){return root;}
        Node* min_val_node(Node* temp);

        // additional function to get new node for ease
        Node* new_node(int val);
    private:
        Node* root;
};

#endif // BST_H
