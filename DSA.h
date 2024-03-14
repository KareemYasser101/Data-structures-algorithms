//************************************* Data structures and algorithms Library ******************************
#include <iostream>

//Singly linked list
namespace SLL{

    class Node {

        public:

            int data;
            Node* next;

            //default constructor
            Node();
            //parametarized constructor
            Node(int value);


    };

    class list {

        private:
            Node* head;
            Node* tail;

        public:

            //default constructor
            list();
            //destructor
            ~list();
            //function to insert a node at start
            void insert_start(int value);

            //function to insert a node at a certain position
            void insert_mid(int value, int position);

            //functions to inset a new node at the end
            void append(int value);

            //functions to delete a node
            void DeleteFromHead();
            void DeleteFromTail();
            void DeleteByPos(int position);
            void DeleteByValue(int value);

            //function to reverse list
            void reverselist();

            //function to print a node
            void print();

    };

}

//Doubly linked list
namespace DLL{

    class Node{
        public:
            int data;
            Node* next;
            Node* prev;

            //default constructor
            Node();
            //parametarized constructor
            Node(int value);
        
    };

    class list{
        private:
            Node* head;
            Node* tail;
        
        public:

            //Default constructor
            list();
            //destructor
            ~list();
            //function to insert a node at start
            void insert_start(int value);

            //function to insert a node at a certain position
            void insert_mid(int value, int position);

            //functions to inset a new node at the end
            void append(int value);

            //function to delete a node
            void DeleteFromHead();
            void DeleteFromTail();
            void DeleteByPos(int position);
            void DeleteByValue(int value);

            //function to reverse list
            void c;

            //function to print a node
            void print();

    };
}