// FILE: bst.cpp
// implement bst.h functions for Binary Search Tree class

#include "node.h" // new_node(int val);
#include "bst.h"
#include <iostream>

void Bst::insert_node(Node* cursor, int val){
    if(!cursor){ // cursor = root
        root = new_node(val);
        return;
    }

    if(val ==  cursor->get_data())
        return; // no duplicates

    else if((val < cursor->get_data()) && (cursor->get_left() == nullptr)){
        cursor->set_left(new_node(val));
        return; // no left child and val is less so it fills that spot
    }
    else if((val > cursor->get_data()) && (cursor->get_right() == nullptr)){
        cursor->set_right(new_node(val));
        return;
    }
    else if(val > cursor->get_data())
        insert_node(cursor->get_right(), val);
    else{
        insert_node(cursor->get_left(), val);
    }
    return;   
}

Node* Bst::delete_node(Node* cursor, int val){
    if(!cursor) // cursor = root
        return cursor; // tree is empty

    else if(val < cursor->get_data())
        cursor->set_left(delete_node(cursor->get_left(),val));
    else if(val > cursor->get_data())
        cursor->set_right(delete_node(cursor->get_right(),val));// 1st here // 2nd here
    else{ // only gets here if val == cursor->get_data()
        if(cursor->get_left() == nullptr){
            Node* temp = cursor->get_right();
            delete cursor;
            return temp;
        }
        else if(cursor->get_right() == nullptr){
            Node* temp = cursor->get_left();
            delete cursor;
            return temp;
        }
        else{
            Node* temp = min_val_node(cursor->get_right());
            cursor->set_data(temp->get_data());
            cursor->set_right(delete_node(cursor->get_right(), temp->get_data()));
        }
    }
    return cursor;
}

Node* Bst::min_val_node(Node* temp){
    while(temp->get_left() != nullptr){
        temp = temp->get_left();
    }
    return temp;
}

void Bst::print_preorder(Node* cursor)const{
    if(!cursor)
        return; // basecase

    std::cout << cursor->get_data() << " ";
    print_preorder(cursor->get_left());
    print_preorder(cursor->get_right());
    return;
}

void Bst::print_inorder(Node* cursor)const{
    if(!cursor)
        return; // basecase

    print_inorder(cursor->get_left());
    std::cout << cursor->get_data() << " ";
    print_inorder(cursor->get_right());
    return;
}

void Bst::print_postorder(Node* cursor)const{
    if(!cursor)
        return; // basecase

    print_postorder(cursor->get_left());
    print_postorder(cursor->get_right());
    std::cout << cursor->get_data() << " ";
    return;
}

Node* Bst::new_node(int val){
    Node* temp = new Node();
    temp->set_data(val);
    return temp;
}
