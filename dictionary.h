/*******************************************************
 *  Name      : Michael Zabawa
 *  Student ID: 107522040
 *  Class     :  CSCI 2421
 *  Due Date  :  Mar. 8, 2018
 *******************************************************/

/* Dr. Augustine
 dictionary.h
 Last Updated:02/14/2016
 Status: Compiles and all requirements met*/

#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <string>
#include <list>
#include <iostream>
#include "DictEntry.h"
using namespace std;

class dictionary
{
private:
    list<DictEntry> wordList;
    
public:
    //typedef string wordType;
    dictionary(){;}
    
    void add(DictEntry temp);
    
    void sort();
    
    /*Searches the list starting at the front of the list and moving to the back
     Returns the number of searches it took to find the findString, or a -1 if not found*/
    int searchForward(wordType &findString);
    
    /*Searches the list starting at the back of the list and moving to the front
     Returns the number of searches it took to find the findString, or a -1 if not found*/
    int searchBackward(wordType &findString);
    
    /*Prints the list of words in reverse alphabetic order to a file*/
    void revPrintList(ostream& output);
    };
/*******************************/
#endif /* dictionary_h */


