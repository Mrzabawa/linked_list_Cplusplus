/*******************************************************
 *  Name      : Michael Zabawa
 *  Student ID: 107522040
 *  Class     :  CSCI 2421
 *  Due Date  :  Mar. 8, 2018
 *******************************************************/
//
//  LinkedList.cpp
//  zabawaHW6

#include "LinkedList.h"
#include <iostream>
#include <fstream>
using namespace std;

bool LinkedList::insertAtFront(std::string word){
    Node *currPtr = headPtr;
    if(headPtr == nullptr){//if list is empty
        headPtr = new Node;
        headPtr -> data.setWord(word);
        tailPtr = headPtr;
        size++;
    }
    else{
        headPtr = new Node;
        headPtr -> data.setWord(word);
        headPtr -> nextPtr = currPtr;
        currPtr -> prevPtr = headPtr;
        size++;
    }
    return true;
}

bool LinkedList::insertAtBack(std::string word){
    Node *currPtr = tailPtr;
    if(tailPtr == nullptr){//if list is empty
        tailPtr = new Node;
        tailPtr -> data.setWord(word);
        headPtr = tailPtr;
        size++;
    }
    else{
        tailPtr = new Node;
        tailPtr -> data.setWord(word);
        tailPtr -> prevPtr = currPtr;
        currPtr -> nextPtr = tailPtr;
        size++;
    }
    return true;
}

bool LinkedList::sort(){
    if(size == 0){//checks that list is non empty
        cout<< "List is empty no need to sort it\n";
    }
    bool swapHappened = true;//assumes that list is not in order
    Node *currPtr;
    int index;
    while(swapHappened){//continue if there is still swaps happening
        swapHappened = false;//assumes sorted
        currPtr = headPtr;
        index = 1;
        while(currPtr -> nextPtr != nullptr){
            if(currPtr -> data.getWord() > currPtr -> nextPtr -> data.getWord()){
                swap(index, index+1);
                swapHappened = true;
                currPtr = currPtr -> prevPtr;//
            }
            index++;
            currPtr = currPtr->nextPtr;
        }
    }
    return true;
}

bool LinkedList::swap(int one, int two){//ugly but it works not sure I needed to have so many variables and cases
    if(one < 1 || two > size || one > two){// cehcks input
        cout << "Check Your Input\n";
        return false;
    }
    //declares pointers
    Node *currPtr1;//moves to the index of the first node to swap
    Node *currPtr2;//moves to the index of the second node to swap
    Node *currPtr3;//where needed the previous node to currPtr1
    Node *currPtr4;//where needed the next node to the currPtr1
    Node *currPtr5;//where needed the previous node to currPtr2
    Node *currPtr6;//where needed the next node to the currPtr2
    
    if(one < (size/2)){//starts currPtr1 at front if one is less then one half the size of list
        currPtr1 = headPtr;
        for(int i = 1; i < one; i++ ){
            currPtr1 = currPtr1 -> nextPtr;
        }
    }
    else{//starts currPtr1 at rear if one is greater then one half the size of the list
        currPtr1 = tailPtr;
        for(int i = size; i > one; i-- ){
            currPtr1 = currPtr1 -> prevPtr;
        }
    }
    
    if(two < (size/2)){//starts currPtr2 at front if two is less then one half the size of list
        currPtr2 = headPtr;
        for(int i = 1; i < two; i++ ){
            currPtr2 = currPtr2 -> nextPtr;
        }
    }
    else{//starts currPtr2 at rear if two is greater then one half the size of list
        currPtr2 = tailPtr;
        for(int i = size; i > two; i-- ){
            currPtr2 = currPtr2 -> prevPtr;
        }
    }
    
    if(one == 1 & two == size){//case where the nodes to swap are the first and last
        headPtr = currPtr1 -> nextPtr;
        tailPtr = currPtr2 -> prevPtr;
        
        currPtr1 -> nextPtr = nullptr;//both should be at null
        currPtr2 -> prevPtr = nullptr;
        
        currPtr2 -> nextPtr = headPtr;
        currPtr1 -> prevPtr = tailPtr;
        
        headPtr -> prevPtr = currPtr2;
        tailPtr -> nextPtr = currPtr1;
        
        headPtr = currPtr2;
        tailPtr = currPtr1;
        
        return true;
    }
    else if(one == 1 ){// case where the the first node needs to be swaped
        if(one + 1 == two){ // case where the first and second node needs to be swaped
            //sets the previous node for currPtr2
            currPtr6 = currPtr2 -> nextPtr;
            
            currPtr2 -> prevPtr = nullptr;
            currPtr2 -> nextPtr = currPtr1;
            currPtr1 -> nextPtr = currPtr6;
            currPtr1 -> prevPtr = currPtr2;
            currPtr6 -> prevPtr = currPtr1;
            
            headPtr = currPtr2;
            return true;
        }
        headPtr = currPtr1 -> nextPtr;
        
        currPtr1 -> nextPtr = currPtr2 -> nextPtr;
        currPtr1 -> prevPtr = currPtr2 -> prevPtr;
        
        currPtr3 = currPtr2 -> nextPtr;
        currPtr3 -> prevPtr = currPtr1;
        currPtr3 = currPtr2 -> prevPtr;
        currPtr3 -> nextPtr = currPtr1;
        
        currPtr2 -> nextPtr = headPtr;
        currPtr2 -> prevPtr = nullptr;
        headPtr -> prevPtr = currPtr2;
        headPtr = currPtr2;
    }
    else if(two == size){// if two is the last index
        if(one+1 == two){//if the last two nodes at to be swaped
            //sets the previous node for currPtr1
            currPtr3 = currPtr1 -> prevPtr;
            
            currPtr3 -> nextPtr = currPtr2;
            currPtr2 -> prevPtr = currPtr3;
            
            currPtr2 -> nextPtr = currPtr1;
            currPtr1 -> prevPtr = currPtr2;
            currPtr1 -> nextPtr = nullptr;
            tailPtr = currPtr1;
            return true;
        }
        tailPtr = currPtr2 -> prevPtr;
        
        currPtr2 -> nextPtr = currPtr1 -> nextPtr;
        currPtr2 -> prevPtr = currPtr1 -> prevPtr;
        
        currPtr3 = currPtr1 -> nextPtr;
        currPtr3 -> prevPtr = currPtr2;
        currPtr3 = currPtr1 -> prevPtr;
        currPtr3 -> nextPtr = currPtr2;
        
        currPtr1 -> prevPtr = tailPtr;
        currPtr1 -> nextPtr = nullptr;
        tailPtr -> nextPtr = currPtr1;
        tailPtr = currPtr1;
    }
    else if(one + 1 == two){//if the indexs at next to one another
        //sets the previous node for currPtr1
        currPtr3 = currPtr1 -> prevPtr;
        //sets the previous and next node for currPtr2
        currPtr6 = currPtr2 -> nextPtr;
        
        currPtr3 -> nextPtr = currPtr2;
        currPtr2 -> prevPtr = currPtr3;
        currPtr2 -> nextPtr = currPtr1;
        
        currPtr1 -> prevPtr = currPtr2;
        currPtr1 -> nextPtr = currPtr6;
        currPtr6 -> prevPtr = currPtr1;
    }
    else{
        //sets the previous and next node for currPtr1
        currPtr3 = currPtr1 -> prevPtr;
        currPtr4 = currPtr1 -> nextPtr;
        //sets the previous and next node for currPtr2
        currPtr5 = currPtr2 -> prevPtr;
        currPtr6 = currPtr2 -> nextPtr;
        
        //sets currPtr2 where currPtr1 was
        currPtr3 -> nextPtr = currPtr2;
        currPtr4 -> prevPtr = currPtr2;
        currPtr2 -> nextPtr = currPtr4;
        currPtr2 -> prevPtr = currPtr3;
        
        //sets currPtr1 where currPtr2 was
        currPtr5 -> nextPtr = currPtr1;
        currPtr1 -> prevPtr = currPtr5;
        currPtr1 -> nextPtr = currPtr6;
        currPtr6 -> prevPtr = currPtr1;
    }
    return true;
}

bool LinkedList::search(string word){
    bool found = false;//assumes the word is not in the list
    int countH = 0;
    int countT = 0;
    Node *currPtrH = headPtr;
    Node *currPtrT = tailPtr;
    while(currPtrH -> nextPtr != nullptr){
        countH++;
        if(currPtrH -> data.getWord() == word){
            found = true;
            goto skip;//if not skipped then the countH will be off
        }
        currPtrH = currPtrH -> nextPtr;
    }
    if(currPtrH -> data.getWord() == word){//checks last element of list else it would not be checked
        countH++;
        found = true;
    }
skip:
    
    if(found){
            cout<< word <<": Forword search found in "<< countH << " comparisons\n";
            while(currPtrT -> prevPtr != nullptr){
                countT++;
                if(currPtrT ->data.getWord() == word){
                    cout<< word <<": Rearward search found in "<< countT << " comparisons\n";
                    break;
                }
                currPtrT = currPtrT -> prevPtr;
            }
    }
    else {
        cout << word <<": Not found in list\n";
    }
    return found;
}

bool LinkedList::deleteAtFront(){
    if(headPtr == nullptr){
        cout << "Nothing To Delete";
        return false;
    }
    else{
        Node *currPtr = headPtr;
        currPtr = currPtr -> nextPtr;
        delete headPtr;
        headPtr = currPtr;
        if(size == 1){
            headPtr = nullptr;
            tailPtr = nullptr;
            size--;
            return true;
        }
        headPtr -> prevPtr = nullptr;
    }
    size--;
    return true;
}

bool LinkedList::deleteAtBack(){
    if(tailPtr == nullptr){
        cout << "Nothing to Delete";
        return false;
    }
    else{
        Node *currPtr = tailPtr;
        currPtr = currPtr ->prevPtr;
        delete tailPtr;
        tailPtr = currPtr;
        if(size == 1){
            headPtr = nullptr;
            tailPtr = nullptr;
            size--;
            return true;
        }
        tailPtr -> nextPtr = nullptr;
    }
    size--;
    return true;
}

void LinkedList::clear(){
    while(headPtr != nullptr){
        deleteAtFront();
    }
}


LinkedList::~LinkedList(){
    clear();
}
