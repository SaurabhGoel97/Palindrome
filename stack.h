//   File:    stack.h
//   Author:  Linda Day adapted from the text
//   Course:  CSC 136
//   Date:    Spring 2015
//   Purpose: The file contains the definition for a stack class implemented as a linked list
#include <iostream>
using namespace std;
#ifndef STACK_H
#define STACK_H

template <class stackElem>
class stack
{
     public:
       //constructor to initialize the top of an empty stack
       stack() {topPtr = NULL;}
       //destructor
       ~stack();
       //copy constructor
       stack(const stack<stackElem> &rhs);
       //assignment operator
       stack<stackElem> & operator=(const stack<stackElem> &rhs);

       //Name: push
       //Description: places the value on the stack as long as it is not empty
       //Parameters:  stackElem value IN -
       //Return: none
       void push(const stackElem &value);

       //Name: pop
       //Description: takes an element off the top of the stack if the stack is
       //Parameters: none
       //Return: none
       void pop();

       //Name: top
       //Description: places the top value in item if the stack is not empty
       //Parameters: none
       //Return: element on the top
       stackElem top() const;


       //Name: empty
       //Description: tests to see if the stack is empty
       //Parameters: none
       //Return: true if empty, false otherwise
       bool empty() const;

       //Name: full
       //Description: tests to see if the stack is full
       //Parameters: none
       //Return: true if full, false otherwise
       bool full() const;

       
       //Name:clear
       //Description: clears all the heap memory
       //Parameters: none
       //Return: none
       void clear();


     private:

       class stackNode
       {
         public:
	   stackElem data;
	   stackNode *next;
	   stackNode(const stackElem &value, stackNode *link = NULL) {data=value; next=link;}
       };

       stackNode * topPtr;
};


#include "stack.cpp"
#endif





