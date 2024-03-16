#include <iostream>
#include "DSA.h"

using namespace std;

int main(){

    /*
    To initialize a linked list:

    1- "SLL" for singly linked list or "DLL" for doubly linked list for namespace specification
    2- "list" for class name in both "SLL" & "DLL"
    3- put the name of your list
    */  
    
    SLL::list mylist;
    for (int i = 1; i <= 10; i++)
    {
        mylist.append(6);
    }
    mylist.append(5);
    mylist.print();
    mylist.DeleteByValue(6);
    mylist.print();

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
    
    return 0;
}


