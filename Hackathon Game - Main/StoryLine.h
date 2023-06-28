//linked list to store every chapter of the storyline
#ifndef STORYLINE_H 
#define STORYLINE_H

#include <iostream>
#include "Chapter.h"
using namespace std;
  
//*********************************************
// The ListNode class creates a type used to  * 
// store a node of the linked list.           * 
//********************************************* 

template <class T> 
class StoryListNode		//creating listNode class
{
   	public: 
    	T value;  		        	// Node value T of class personInfo - composition 
      	StoryListNode<T> *next;   	    // Pointer to the next node
    	StoryListNode (T nodeValue)      //Constructor  
    	{ value = nodeValue; next = nullptr; } 
};

//**************************** 
// LinkedList class template * 
//****************************

template <class T> 
class StoryLine			//creating storyline linked list class
{
   	private: 
    	StoryListNode<T> *head; 
   
   	public: 
     	StoryLine()               // Constructor 
     	{ head = nullptr; } 
     	~StoryLine();             // Destructor
     
    	// Linked list operations
     	void appendNode(T);     	//to add node 
     	void display(int) const;   	//to display all nodes 
};

//************************************************** 
// appendNode appends a node containing the chapter* 
// passed into newValue, to the end of the list.   * 
//**************************************************
template <class T>
void StoryLine<T>::appendNode(T newValue)  
{
    StoryListNode<T> *newNode; // To point to a new node 
    StoryListNode<T> *nodePtr; // To move through the list

    // Allocate a new node and store newValue there. 
    newNode = new StoryListNode<T>(newValue);

  	// If there are no nodes in the list, make newNode the first node.
  	if (!head)
  	{
     	head = newNode; 
  	}

    else // Otherwise, insert newNode at end. 
    {
      	// Initialize nodePtr to head of list. 
      	nodePtr = head;

      	// Find the last node in the list. 
      	while (nodePtr->next)
        	nodePtr = nodePtr->next;

      	// Insert newNode as the last node.
      	nodePtr->next = newNode; 
    }
}

//************************************************** 
// displayList shows the chapter stored in each node* 
// of the linked list pointed by head.          * 
//************************************************** 
template <class T>
void StoryLine<T>::display(int currentChapter) const 
{
    StoryListNode<T> *nodePtr;     // To move through the list
     
  	nodePtr = head;       // Position nodePtr at the head of the list. 
  
  	// While nodePtr points to a node, traverse the list.
  	while (nodePtr->value.getNumChapter() != currentChapter)
  	{
      	// Move to the next node. 
      	nodePtr = nodePtr->next; 
  	}
  
  	if (nodePtr)
  	{
  	//cout<< "\n-----------------------------------------CHAPTER 0-------------------------------------------------" << endl;
    	cout << "\n------------------------------------------- CHAPTER " << nodePtr->value.getNumChapter() << " ----------------------------------------------------" << endl;
    	cout << nodePtr->value.getText() << endl;
  	}
}

//************************************************** 
// Destructor                                      * 
// This function deletes every node in the list.   * 
//**************************************************

template <class T>  
StoryLine<T>::~StoryLine() 
{ 
   StoryListNode<T> *nodePtr; // To traverse the list  
   StoryListNode<T> *nextNode; // To point to the next node
   // Position nodePtr at the head of the list. 
   nodePtr = head;

   // While nodePtr is not at the end of the list... 
   while (nodePtr != nullptr)
   {
      	// Save a pointer to the next node. 
      	nextNode = nodePtr->next;
      	// Delete the current node. 
      	delete nodePtr;
      	// Position nodePtr at the next node.
      	nodePtr = nextNode;
   }
}

#endif 

