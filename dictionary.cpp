/*******************************************************
 *  Name      : Michael Zabawa
 *  Student ID: 107522040
 *  Class     :  CSCI 2421
 *  Due Date  :  Mar. 8, 2018
 *******************************************************/
//  dictionary.cpp
//  zabawaHW6

#include <list>
#include "dictionary.h"

void dictionary::add(DictEntry temp){//adds to list
    wordList.push_back(temp);
}

void dictionary::sort(){//sorts list
    wordList.sort();
}

/*Searches the list starting at the front of the list and moving to the back
 Returns the number of searches it took to find the findString, or a -1 if not found*/
int dictionary::searchForward(wordType &findString){
    int found = -1;
    int countH = 0;
    list<DictEntry>::iterator frontwordList = wordList.begin();
    
    while(frontwordList != wordList.end()){
        countH++;
        if(frontwordList -> getWord() == findString){
            found = countH;
            break;
        }
        frontwordList++;
    }
    return found;
}

/*Searches the list starting at the back of the list and moving to the front
Returns the number of searches it took to find the findString, or a -1 if not found*/
int dictionary::searchBackward(wordType &findString){
    int found = -1;
    int countT = 0;
    list<DictEntry>::reverse_iterator tailwordList = wordList.rbegin();
    
    while(tailwordList != wordList.rend()){
        countT++;
        if(tailwordList -> getWord() == findString){
            found = countT;
            break;
        }
        tailwordList++;
    }
    return found;
}

/*Prints the list of words in reverse alphabetic order to a file*/
void dictionary::revPrintList(ostream& output){
    list<DictEntry>::reverse_iterator tailwordList = wordList.rbegin();
    
    while(tailwordList != wordList.rend()){
        output << tailwordList -> getWord() << " ";
        tailwordList++;
    }
}
