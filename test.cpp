// FILE: test.cpp
// testing file for Binary Search Tree
#include <utility> // std::move()
#include <chrono> // std::chrono // timer
#include "bst.h"
#include <iostream>
using std::cout;
using std::endl;

int main(){

    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();    
  
    Bst tree;
    Node* temp = nullptr;
    tree.insert_node(tree.get_root(),20);
    tree.insert_node(tree.get_root(),10);
    tree.insert_node(tree.get_root(),30);
    tree.insert_node(tree.get_root(),8);
    tree.insert_node(tree.get_root(),19);

    tree.insert_node(tree.get_root(),51);
    tree.insert_node(tree.get_root(),47);
    tree.insert_node(tree.get_root(),46);
    tree.insert_node(tree.get_root(),48);
    tree.insert_node(tree.get_root(),52);
    tree.insert_node(tree.get_root(),53);

    tree.print_inorder(tree.get_root());

    cout << "Now using move constructor...with tree2, constructed next...\n\n";
    Bst tree2 = std::move(tree);    
    cout << "Bst tree2 = std::move(tree) has been done. print_inorder(tree2.get_root())\n";
    tree2.print_inorder(tree2.get_root());

    temp = tree2.delete_node(tree2.get_root(),53);
    temp = tree2.delete_node(tree2.get_root(),51);
    temp = tree2.delete_node(tree2.get_root(),48);
    temp = tree2.delete_node(tree2.get_root(),46);
    temp = tree2.delete_node(tree2.get_root(),47);
    temp = tree2.delete_node(tree2.get_root(),52);

    temp = tree2.delete_node(tree2.get_root(),8);
    temp = tree2.delete_node(tree2.get_root(),19);
    temp = tree2.delete_node(tree2.get_root(),30);
    temp = tree2.delete_node(tree2.get_root(),10);
    temp = tree2.delete_node(tree2.get_root(),20);

    end = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double> elapsedTime( end - start);
    const double seconds(elapsedTime.count());

    std::cout << "  Runtime: " << seconds << "s" << std::endl; 

    return 0;
}
