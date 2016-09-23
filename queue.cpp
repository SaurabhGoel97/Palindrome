//  File:   queue.cpp
//  Authors: John Bogunovich and
//           Patrick Gagliano
//  Course: CSC 136
//  Date:   Spring 2015
//  Purpose: This file contains the specification for the generic queue
//           class and all its operations.  This queue is implemented as a
//           linked structure

#include "queue.h"
#include <iostream>

using namespace std;

#ifndef QUEUE_CPP
#define QUEUE_CPP

  //constructor
  template <class Type>
  queue<Type>::queue()
  {
    frontPtr = NULL;
    rearPtr = NULL;
  }
    
  //copy constructor
  template <class Type>
  queue<Type>::queue(const queue<Type> &rhs)
  {
    frontPtr = NULL;
    rearPtr = NULL;

    *this = rhs;
  }

  //destructor
  template <class Type>
  queue<Type>::~queue()
  {
    clear();
  }

  //overload of assignment operator
  template <class Type>
  queue<Type> & queue<Type>::operator=(const queue &rhs)
  {
    clear();
    queueNode *p1;     
    queueNode *ptr;  

    p1 = rhs.frontPtr;      

    if(p1 != NULL)    
      {
	frontPtr = new queueNode(p1 -> data);     
	ptr = frontPtr; 
	p1 = p1 -> next;        
      }

    while(p1 != NULL)  
      {
	ptr -> next = new queueNode(p1 -> data);
	p1 = p1 -> next;
	ptr = ptr -> next;
      }
    return *this;
  }

  //Name: push
  //Description: put item on the rear of the queue
  //Parameters: item -IN - item to add
  //Return: none
  template <class Type> 
  void queue<Type>::push(const Type &item)
  {
    if(frontPtr != NULL)
      {
	rearPtr -> next = new queueNode(item);
	rearPtr = rearPtr -> next;
      }
    else
      {
	rearPtr = new queueNode(item);
	frontPtr = rearPtr;
      }
  }

  //Name: pop
  //Description: take the value from the front of the queue if not empty
  //Parameters: none
  //Return: none
  template <class Type>
  void queue<Type>::pop()
  {
    queueNode *p;

    if(frontPtr != NULL)
      {
        p = frontPtr;
        frontPtr = frontPtr -> next;
        delete p;

      if(rearPtr == p)
        rearPtr = NULL;
     
      //      delete p;
      }
   }

  //Name: front
  //Description: returns the value at the front of the queue if not empty
  //Parameters: none
  //Return: the value on the front
  template <class Type>
  Type queue<Type>::front() const
  {
  if(frontPtr != NULL)
   return frontPtr -> data;
  }

  //Name: clear
  //Description: empty out the queue by deleting all the nodes
  //Parameters: none
  //Return: none
  template <class Type>
  void queue<Type>::clear()
  {
    queueNode *p1 = frontPtr;
    while (frontPtr != NULL)
    {
      frontPtr = frontPtr -> next;
      delete p1;
      p1 = frontPtr;
    }
  }

  //Name: isEmpty
  //Description: checks to see if the queue is empty
  //Parameters: none
  //Return: true if empty, false otherwise
  template <class Type>
  bool queue<Type>::isEmpty() const
  {
    if(frontPtr == NULL)
      return true;
    else
      return false; 
  }

  //Name: isFull
  //Description: checks to see if the queue is full
  //Parameters: none
  //Return: true if full, false otherwise
  template <class Type>
  bool queue<Type>::isFull() const
  {
    if (frontPtr != NULL)
      return true;
    else 
      return false;
  }

#include "queue.h"
#endif
