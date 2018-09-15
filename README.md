# linked_list_Cplusplus
*******************************************************
*  Name      : Michael Zabawa         
*  Student ID: 107522040                
*  Class     :  CSCI 2421           
*  Due Date  :  Mar. 8, 2018
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

Demonstration of the STL <list> iterators and an implementation
of a user double linked list. The program reads in a file of words then 
sorts and reads in another file to search the list. The program
then outputs the words to an external file in reverse order.

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
	Driver program to demonstrate the <list> iterators and the
	implementation of the LinkedList. Produces an

       DictEntry.h
	Provided header file for assignment. Nothing was changed.

       LinkedList.h
	Holds the definitions for the student defined LinkedList.
	
       LinkedList.cpp
	Member functions for adding at the front, at the back, sorting and swapping the 
	nodes.
   
       dictionary.h
	Holds the definitions for the dictionary class.

       dictionary.cpp
	Provides the implementations for the dictionary class. Sort, searchForward,
	searchBackward revPrintList. The searching functions looks at the list from the
	respective sides of the list. The revPrintList function looks sends output to 
	an external file (revsorted.txt).

*******************************************************
*  Status of program
*******************************************************

   Extra credit for student defined double linked list.

   The program runs successfully.
   
   The program was developed and tested on Xcode g++.  It was 
   compiled, run, and tested on csegrid.ucdenver.pvt.
   Target hw6.
