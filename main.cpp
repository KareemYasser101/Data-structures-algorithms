#include <iostream>
#include "DSA.h"
#include <random>

using namespace std;

int main(){

    /*
    To initialize a linked list:

    1- "SLL" for singly linked list or "DLL" for doubly linked list for namespace specification
    2- "list" for class name in both "SLL" & "DLL"
    3- put the name of your list
    */  
    
    //SLL::list mylist;

    /*
    Functions that come with SLL & DLL:

    *Insertion of a node*
    1- insert_start(int value) - to insert a node at the head of the list
    2- insert_mid(int value, int position) - to insert a node in any position in the linked list
    3- append(int value) - to add a node to the end of the list

    *Deletion of Node/s*
    4- DeleteFromHead() - to delete the head "first" node
    5- DeleteFromTail() - to delete the tail "last" node
    6- DeleteByPos(int position) - to delete a node with a specified position
    7- DeleteByValue(int value) - to delete every instance of a node with the specified value

    8- ReverseList() - to reverse the whole list

    9- Print() - to print the whole linked list

    */
    
    // More to be added!!
    

    BST::BinarySearchTree bst;
    BST::Node*& root = bst.getRoot();

    // Define the random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100); // Change the range as needed

    for (int i = 1; i <= 10; i++)
        bst.insertNode(dis(gen), root);
    bst.insertNode(6, root);
    cout<<"Printing BST preOrder: ";
    bst.preOrderTrav(root);
    cout<<endl;

    cout<<"Printing BST inOrder(ascending): ";
    bst.inOrderTrav(root);
    cout<<endl;

    cout<<"Printing BST postOrder: ";
    bst.postOrderTrav(root);
    cout<<endl;

    cout<<endl;

    int key;
    cout<<"Enter key to search for: ";
    cin>>key;

    cout<< (bst.searchNode(key, bst.getRoot()) ? "Found":"Not found") <<endl;

    int value;
    cout<<"Enter value to delete: ";
    cin>>value;
    bst.deleteNode(value, root);

    cout<<"BST after deleting "<<value<<": ";
    bst.inOrderTrav(root);

    return 0;
}


