// FILE: node.h
// define and implement node class for BST tree

#ifndef NODE_H
#define NODE_H

class Node{
    public:
        Node() : data{0}, left{nullptr}, right{nullptr} {}

        int get_data()const{return data;}
        Node* get_left()const{return left;}
        Node* get_right()const{return right;}

        void set_data(int val){data = val;}
        void set_left(Node* temp){left = temp;}
        void set_right(Node* temp){right = temp;}

    private:
        int data;
        Node* left;
        Node* right;
};

#endif // NODE_H
