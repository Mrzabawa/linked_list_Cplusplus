/*******************************************************
*  Name      : Michael Zabawa
*  Student ID: 107522040
*  Class     :  CSCI 2421
*  Due Date  :  Mar. 8, 2018
*******************************************************/
//  main.cpp
//  zabawaHW6

#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include "DictEntry.h"
#include "dictionary.h"
#include "LinkedList.h"

using namespace std;

int main() {
    string word;
    LinkedList mylist;
    dictionary notMyList;
    
    //**********************************************************************
    //opens files
    
    ifstream infile("dictionary.txt");
    ifstream findFile("findwords.txt");
    ofstream outFile("revsorted.txt");
    if(infile.fail()){//makes sure file is open
        cout << "dictionary.txt failed to open\n";
    }
    if(findFile.fail()){//makes sure file is open
        cout << "findwords.txt failed to open\n";
    }
    if(infile.fail()){//makes sure file is open
        cout << "revsorted.txt failed to open\n";
    }
    
    //**********************************************************************
    //inputs words to mylist and notMyList
    
    outFile << "Reading words to lists...\n";
    while(getline(infile, word)){
        DictEntry temp;
        temp.setWord(word);
        mylist.insertAtBack(word);
        notMyList.add(temp);
    }
    
    //**********************************************************************
    //sorts mylist and notMyList
    
    outFile << "Sorting lists...\n";
    notMyList.sort();
    mylist.sort();
    
    //**********************************************************************
    //searches mylist and notMyList
    
    outFile<< "Reading in words to search for...\n";
    int foundF = -1;//assumes word is not found used for forward search
    int foundR = -1;//assumes word is not found used for rearward search
    
    while(getline(findFile, word)){
        //serch of mylist and out puts results to consol
        mylist.search(word);
        
        //search of not myList
        foundF = notMyList.searchForward(word);
        if(foundF > 0){
            outFile << word <<": Forward search found in "<< foundF << " comparisons.\n";
        }
        else {
            outFile << word <<": Not found in forward search!\n";
        }
        
        foundR = notMyList.searchBackward(word);
        if(foundR > 0){
            outFile << word <<": Rearward search found in "<< foundR << " comparisons.\n";
        }
        else {
            outFile << word <<": Not found in rearward search!\n";
        }
    }
    
    //**********************************************************************
    //prints to outFile with space between words
    
    notMyList.revPrintList(outFile);
    
    //**********************************************************************
    //closes files
    
    outFile.close();
    findFile.close();
    infile.close();
    
    if(infile.is_open()){//makes sure file is closed
        cout<< "dictionary.txt failed to close\n";
    }
    if(findFile.is_open()){//makes sure file is closed
        cout<< "findwords.txt failed to close\n";
    }
    if(findFile.is_open()){//makes sure file is closed
        cout<< "revsorted.txt failed to close\n";
    }
    return 0;
}
