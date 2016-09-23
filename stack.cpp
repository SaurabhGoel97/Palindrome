//   File:    stack.cpp
//   Author:  Patrick Gagliano and  
//            John Bogunovich
//   Course:  CSC 136
//   Date:    Spring 2015
//   Purpose: The file contains the definition for a stack class implemented as an array
#include "stack.h"
#include <iostream>

using namespace std;

#ifndef STACK_CPP
#define STACK_CPP

//Name: copy Constructor
//Description: Creates a deep copy
//Parameters: value to copy from
//Return: None
template <class stackElem>
stack<stackElem>::stack(const stack<stackElem> & rhs)
{
  topPtr = NULL;

  *this = rhs;
}

//Name: Destructor
//Description: Deletes all nodes from the list
//Parameters: None
//Return: None
template <class stackElem>
stack<stackElem>::~stack()
{
  clear();
}

//Name: Assignment Operator
//Description: Creates a deep copy
//Parameters: stack to copy from
//Return: The instance of the list
template <class stackElem>
stack<stackElem> & stack<stackElem>::operator=(const stack &rhs)
{
  clear();                                              
  stackNode *p1;                                             
  stackNode *ptr;                                           

  p1 = rhs.topPtr;                                       

  if( p1 != NULL)                                      
    {
      topPtr = new stackNode(p1 -> data);                                   
      ptr = topPtr;                                       
      p1 = p1 -> next;                                 
    }

  while(p1 != NULL)                                    
    {
      ptr -> next = new stackNode(p1 -> data);
      p1 = p1 -> next;
      ptr = ptr -> next;
    }
  return *this;
}

//Name: push
//Description: places the value on the stack as long as it is not empty
//Parameters:  stackElem value IN -
//Return: none
template <class stackElem>
void stack<stackElem>::push(const stackElem &value)
{
  topPtr = new stackNode(value, topPtr);
}

//Name: pop
//Description: takes an element off the top of the stack if the stack is
//Parameters: none
//Return: none
template <class stackElem>
void stack<stackElem>::pop()
{
  stackNode *p;

  if(topPtr != NULL)
    {
      p = topPtr;
      topPtr = topPtr -> next;
      delete p;
    }
}

//Name: top
//Description: places the top value in item if the stack is not empty
//Parameters: none
//Return: element on the top
template <class stackElem>
stackElem stack<stackElem>::top() const
{
  if(topPtr != NULL)
    {
      return topPtr -> data;
    }
}

//Name: empty
//Description: tests to see if the stack is empty
//Parameters: none
//Return: true if empty, false otherwise
template <class stackElem>
bool stack<stackElem>::empty() const
{
  if(topPtr == NULL)
    {
      return true;
    }
  else
    {
      return false;
    }
}

//Name: full
//Description: tests to see if the stack is full
//Parameters: none
//Return: true if full, false otherwise
template <class stackElem>
bool stack<stackElem>::full() const
{
  if(topPtr != NULL)
    {
      return true;
    }
  else
    {
      return false;
    }
}

//Name: clear
//Description: clears the stack
//Parameters: none
//Return: none
template <class stackElem>
void stack<stackElem>::clear()
{
  stackNode *p = topPtr;

  while(topPtr != NULL)
    {
      topPtr = topPtr -> next;
      delete p;
      p = topPtr;
    }
}

#include "stack.h"

#endif
