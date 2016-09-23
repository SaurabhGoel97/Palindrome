//Author:  Patrick Gagliano	
//File:	   queue.h
//Purpose: This file contains the specification for the generic queue class and all its operations.  
//         This queue is implemented as a linked structure.
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

template <class Type>
class queue
{
        public:
	   //constructor
           queue();

	   //copy constructor
           queue(const queue<Type> &rhs);
	   //destructor
           ~queue();
	   //overload of assignment operator
           queue<Type> & operator=(const queue<Type> &rhs);

	   //Name: push
	   //Description: put item on the rear of the queue
	   //Parameters: item -IN - item to add
	   //Return: none
           void push(const Type &item);

	   //Name: pop
	   //Description: take the value from the front of the queue if not empty
	   //Parameters: none
	   //Return: none
           void pop();

	   //Name: front 
	   //Description: returns the value at the front of the queue if not empty
	   //Parameters: none
	   //Return: the value on the front
	   Type front() const;
	   
	   //Name: clear
	   //Description: empty out the queue by deleting all the nodes
	   //Parameters: none
	   //Return: none
           void clear();

	   //Name: isEmpty
	   //Description: checks to see if the queue is empty
	   //Parameters: none
	   //Return: true if empty, false otherwise
           bool isEmpty() const;
	   
	   //Name: isFull
	   //Description: checks to see if the queue is full
	   //Parameters: none
	   //Return: true if full, false otherwise
	   bool isFull() const;

        private:

	   class queueNode
	   {
	     public:
	       Type data;
	       queueNode *next;
	       queueNode() {next= NULL;}
	       queueNode(Type initData, queueNode *link = NULL) {data=initData; next=link;}
	   };

           queueNode *frontPtr, *rearPtr;
};


#include "queue.cpp"
#endif
