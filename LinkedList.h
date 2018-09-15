/*******************************************************
 *  Name      : Michael Zabawa
 *  Student ID: 107522040
 *  Class     :  CSCI 2421
 *  Due Date  :  Mar. 8, 2018
 *******************************************************/
//
//  LinkedList.hpp
//  zabawaHW6

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include"DictEntry.h"
using namespace std;

struct Node{
    DictEntry data;
    Node *nextPtr = nullptr;
    Node *prevPtr = nullptr;
};

class LinkedList{
private:
    Node *headPtr = nullptr;
    Node *tailPtr = nullptr;
    int size;

public:
    LinkedList(){size = 0;}

    
    bool insertAtFront(std::string word);
    bool insertAtBack(std::string word);
    
    bool sort();
    bool swap(int one, int two);
    bool search(string word);
    
    bool deleteAtFront();
    bool deleteAtBack();
    void clear(); //frees memory for entire list
    ~LinkedList();
};
#endif /* LinkedList_h */
