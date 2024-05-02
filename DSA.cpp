#include <iostream>
#include "DSA.h"

//*************** SLL IMPLEMENTATION ***************

//Default constructor
SLL::Node::Node(){
    data=0;
    next=nullptr;
}
//parametarized constructor
SLL::Node::Node(int value){
    data = value;
    next = nullptr;
}

//default constructor
SLL::list::list(){
    head = nullptr;
    tail = nullptr;
}

//destructor
SLL::list::~list(){
    Node* temp = head;
    while(head != nullptr){
        temp = head;
        head = head -> next;
        delete temp;
    }
}

//****METHODS****

//Insert at the beginning of the SLL
void SLL::list::insert_start(int value){
    if(head != nullptr){
        Node* newnode = new Node(value);
        newnode -> next = head;
        head = newnode;
    }
    else { 
        Node* newnode = new Node(value);
        head = tail = newnode;
    }
}

//Insert at the middle of the SLL 
void SLL::list::insert_mid(int value, int position){
    if(head != nullptr){
        Node* newnode = new Node(value);

        Node* temp = head;
    for(int i=2;i<position;i++){
        temp = temp -> next;
    }
    newnode -> next = temp -> next;
    temp->next = newnode;
    }
    else{
        Node* newnode = new Node(value);
        head = tail = newnode;
    }
}

//Append to the SLL
void SLL::list::append(int value){
    if(tail != nullptr){
        //allocate new node in the heap
        Node* newnode = new Node(value);
        tail->next = newnode;
        tail = newnode;
    }
    else { 
        Node* newnode = new Node(value);
        head = tail = newnode;
    }
}

//Functions to delete a node

void SLL::list::DeleteFromHead(){
    if(head == nullptr){
        std::cout<<"List is empty."<<std::endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void SLL::list::DeleteFromTail(){
    if(head == nullptr){
        std::cout<<"List is empty."<<std::endl;
        return;
    }

    Node* temp = head;
    while(temp -> next != tail){
        temp = temp -> next;
    }
    tail = temp;
    temp = temp -> next;
    delete temp;
    tail -> next = nullptr;
    
}

void SLL::list::DeleteByPos(int position){
    Node* temp1 = head;
    if(head == nullptr){
        std::cout<<"List is empty.";
        return;
    }

    //get size of list
    int listlen=0;
    while(temp1 != nullptr){
        temp1 = temp1 -> next;
        listlen++;
    }

    //check if position to be deleted is out of scope
    if(listlen < position){
        std::cout<<"out of scope.";
        return;
    }

    //delete first node
    if(position == 1){
        SLL::list::DeleteFromHead();
        return;
    }

    //delete last node
    if(position == listlen){
        SLL::list::DeleteFromTail();
        return;
    }

    //delete any node in the middle
    temp1=head;
    Node* temp2 = head;
    for(int i=2;i<=position;i++){
        temp1 = temp2;
        temp2 = temp2 -> next;
    }
    temp1->next = temp2->next;
    delete temp2;
}

void SLL::list::DeleteByValue(int value){
    if(head == nullptr)
        return;

    while(head -> data == value && head != tail)
        SLL::list::DeleteFromHead();

    if(head != tail){
        Node* temp2 = head;
        Node* temp1 = temp2;

        while ( temp2 -> next != tail ){

            temp1 = temp2;
            temp1 = temp1 -> next;
            if(temp1->data == value){
                temp2 -> next = temp1 -> next;
                delete temp1;
            }
            else
                temp2 = temp2 -> next;

        }
    }
    if(tail->data == value)
        SLL::list::DeleteFromTail();
    
}

//Function to reverse list
void SLL::list::reverselist(){
                    
    Node* before = nullptr;
    Node* current = head;
    Node* after = nullptr;

    while(current != nullptr){
        after = current -> next;
        current -> next = before;
        before = current;
        current = after;
    }

    tail = head;
    head = before;
}

//Function to print the list
void SLL::list::print(){
    if(head == nullptr){
        std::cout<<"List is empty.";
        return;
    }
    Node* current = head;
    while(current != nullptr){
        std::cout<<current->data<<" ";
        current = current -> next;
    }
    std::cout<<std::endl;
}


//*************** DLL IMPLEMENTATION ***************
//Default constructor
DLL::Node::Node(){
    data = 0;
    next = nullptr;
    prev = nullptr;
}

//Parametarized constructor
DLL::Node::Node(int value){
    data = value;
    next = nullptr;
    prev = nullptr;
}

//Default constructor
DLL::list::list(){
    head = nullptr;
    tail = nullptr;
}

//Destructor
DLL::list::~list(){
    Node* temp = head;
    while(head != nullptr){
        temp = head;
        head = head -> next;
        delete temp;
    }
}

void DLL::list::insert_start(int value){
    if(head != nullptr){
        Node* newnode = new Node(value);
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
    else { 
        Node* newnode = new Node(value);
        head = tail = newnode;
    }
}

void DLL::list::insert_mid(int value, int position){
    if(head != nullptr){
        Node* newnode = new Node(value);
        Node* temp1 = head;
        Node* temp2 = head;
    for(int i=2;i<=position;i++){
        temp2 = temp2 -> next;
        if(i!=position)
            temp1 = temp1 -> next;
    }
    newnode->next=temp2;
    newnode->prev=temp1;
    temp1->next=newnode;
    temp2->prev=newnode;
    }
    else{
        Node* newnode = new Node(value);
        head = tail = newnode;
    }
}

void DLL::list::append(int value){
    if(head != nullptr){
        Node* newnode = new Node(value);
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
    else{
        Node* newnode = new Node(value);
        head = tail = newnode;
    }
}

void DLL::list::DeleteFromHead(){
    if(head == nullptr){
        std::cout<<"List is empty."<<std::endl;
        return;
    }
    Node* temp = head;
    if(head == tail)
        head = tail = nullptr;
    else{
        head = head->next;
        head -> prev = nullptr;
    }
    delete temp;  
}

void DLL::list::DeleteFromTail(){
    if(head == nullptr){
        std::cout<<"List is empty."<<std::endl;
        return;
    }
    Node* temp = tail;
    if(head == tail)
        head = tail = nullptr;
    else{
        tail = tail -> prev;
        tail -> next = nullptr;
    }
    delete temp;     
}

void DLL::list::DeleteByPos(int position){
    Node* temp1 = head;
    if(head == nullptr){
        std::cout<<"List is empty.";
        return;
    }

    //get size of list
    int listlen=0;
    while(temp1 != nullptr){
        temp1 = temp1 -> next;
        listlen++;
    }

    //check if position to be deleted is out of scope
    if(listlen < position){
        std::cout<<"out of scope.";
        return;
    }

    //delete first node
    if(position == 1){
        DLL::list::DeleteFromHead();
        return;
    }

    //delete last node
    if(position == listlen){
        DLL::list::DeleteFromTail();
        return;
    }

    //delete any node in the middle
    temp1=head;
    Node* temp2 = head;
    for(int i=2;i<=position;i++){
        temp1 = temp2;
        temp2 = temp2 -> next;
    }
    temp1->next = temp2->next;
    temp2->next->prev = temp1;
    delete temp2;

}

void DLL::list::DeleteByValue(int value){
    if(head == nullptr)
          return;
    // first case: if the element is the head
    while(head->data == value && head != tail) // a while loop in case the elements is the same consecutively
        DLL::list::DeleteFromHead();
    // third case: if the element is not the head nor the tail
    if(head != tail){ // to check that the list doesn't consist of only one node
          Node* temp2 = head;
          Node* temp1 = temp2;

          while ( temp2 -> next != tail ){

               temp1 = temp2;
               temp1 = temp1 -> next;
               if(temp1->data == value){
                    temp2 -> next = temp1 -> next;
                    temp1 -> next -> prev = temp2;
                    delete temp1;
               }
               else
                    temp2 = temp2 -> next;

          }
    }

    // second case: if the element is the tail 
    if(tail->data == value)
        DLL::list::DeleteFromTail();
}

void DLL::list::ReverseList(){
    Node* before = nullptr;
    Node* current = head;

    while(current != nullptr){
        current -> prev = current -> next;
        current -> next = before;
        before = current;
        current = current -> prev;
    }

    tail = head;
    head = before;
}

void DLL::list::print(){
    if(head == nullptr){
        std::cout<<"List is empty.";
        return;
    }
    Node* current = head;
    while(current != nullptr){
        std::cout<<current->data<<" ";
        current = current -> next;
    }
    std::cout<<std::endl;
}


//*************** BST IMPLEMENTATION ***************

BST::Node::Node(){
    data = 0;
    left = nullptr;
    right = nullptr;
}

BST::Node::Node(int value){
    data = value;
    left = nullptr;
    right = nullptr;
}

BST::BinarySearchTree::BinarySearchTree(){
    root = nullptr;
}

BST::BinarySearchTree::~BinarySearchTree(){

}

BST::Node*& BST::BinarySearchTree::getRoot(){ return root; }

void BST::BinarySearchTree::insertNode(int value, Node* &root){

    if(!root){
        root = new Node(value);
        return;
    }

    if(value < root->data)
        insertNode(value, root->left);
    else if(value > root->data)
        insertNode(value, root->right);
    else{
        std::cout<<"Can't insert duplicate."<<std::endl;
        return;
    } 
}

bool BST::BinarySearchTree::searchNode(int key, Node* root){
    if(!root)
        return false;
    
    if(key < root->data)
        return searchNode(key, root->left);
    else if(key > root->data)
        return searchNode(key, root->right);
    else
        return true;
}

void BST::BinarySearchTree::deleteNode(int valToDelete, Node* &root){
    /*
        In deletion we have three cases:
            1- val is a leaf
                -just delete the leaf
            2- val has one child
                -make it's parent point to it's only child 
                -then delete it
            3- val has two childs
                -make it's parent point to it's inorder predessesor(largest in the left sub tree) or 
                 successor(smallest in the right sub tree)
                -then delete it
    */
   if(!root)
     return;

    static Node* parent = root;
    if(valToDelete < root->data){
        parent = root;
        deleteNode(valToDelete, root->left);
    }
    else if(valToDelete > root->data){
        parent = root;
        deleteNode(valToDelete, root->right);
    }
    else if(valToDelete == root->data){ // if the valToDelete is equal to root->data
    //case 1:
        if(root->left == nullptr && root->right == nullptr){
            if(parent->right->data == valToDelete)
                parent->right = nullptr;
            else
                parent->left = nullptr;
            delete root;
        }
    //case 2:
        else if(!(root -> left)){
            Node* rightChild = root -> right;
            if(parent->right->data == valToDelete)
                parent->right = rightChild;
            else
                parent->left = rightChild;

            delete root;
        }
        else if(!(root -> right)){
            Node* leftChild = root -> left;
            delete root;
            if(parent->left->data == valToDelete)
                parent->left = leftChild;
            else
                parent->right = leftChild;

            delete root;
        }
    //case 3: 
        else {
            Node* minRight; // will hold minimum in right sub tree
            parent->data = root->data;
            while(root->right != nullptr){
                minRight->data = 99999999;
                if(root->right->data < minRight->data)
                    minRight->data = root->data;
            }

            deleteNode(root->right->data, root->right);
        }
    }
    else
     std::cout<<"Value not found in BST."<<std::endl;
}

void BST::BinarySearchTree::preOrderTrav(Node* root){
    if(!root)
        return;

    std::cout<<root->data<<" ";
    preOrderTrav(root->left);
    preOrderTrav(root->right);
    
}

void BST::BinarySearchTree::inOrderTrav(Node* root){
    if(!root)
        return;

    inOrderTrav(root->left);
    std::cout<<root->data<<" ";
    inOrderTrav(root->right);
}

void BST::BinarySearchTree::postOrderTrav(Node* root){
    if(!root)
        return;

    postOrderTrav(root->left);
    postOrderTrav(root->right);
    std::cout<<root->data<<" ";
}