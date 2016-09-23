//  File:   application.cpp
//  Author: John Bogunovich and 
//          Patrick Gagliano
//  Course: CSC 136
//  Date:   Spring 2015
//  Purpose: to test strings to see if they are palindromes 
//           by using stacks and queues

#include "stack.h"
#include "queue.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Name: strip
//Description: converts a string s to only alphabetic values
//Parameters: s IN the string to convert
//Return: strip(string, s)
string strip(string s);

//Name: fillData
//Description: fills up stack and queue with stripped line
//Parameters: stripped line, stack, queue
//Return: none 
void fillData(string stripLine, stack<string> &stk, queue<string> &que);

//Name: testString
//Description: process string to see if it is a palindrome
//Parameters: stripped line, stack, queue
//Return: bool
bool testString(stack<string> &stk, queue<string> &que); 

int main()
{
  bool test;
  stack<string> stk;
  queue<string> que;
  ifstream f;
  string fname, line, stripLine;

  cout << "Enter the file name to be tested: ";
  cin >> fname;
  f.open(fname.c_str());
  if(f.fail())
    {
      cout << "Failed to open" << endl;
      return 0;
    }

   getline(f, line); //get first line
   while(!f.eof())
    {
      //display line
      cout << line;
      cout <<endl;

      //get a new line by calling strip
      stripLine = strip(line);  //returns string

      //fill up a stack and a queue using the stripped line
      fillData(stripLine, stk, que);  //returns void
      
      //process the stack and queue
      test = testString(stk, que); //returns bool

      //report results
      if(test == true)
	 cout << "Palindrome: YES"; 
      else
	cout << "Palindrome: NO";
      cout << endl;
      cout << endl;

      stk.clear();  //clear stack 
      que.clear();  //clear queue

      getline(f,line);  //get next line      
    }
    return 0;
}

//Name: strip
//Description: converts a string s to only alphabetic values
//Parameters: s IN the string to convert
//Return: strip(string, s)
string strip(string s)
{
  string ss;
  for(int i=0; i<s.length(); i++)
    {
     if (isalpha(s[i]))
     ss.append(1, s[i]);
    }
  return ss;
}


//Name: fillData
//Description: fills up stack and queue with stripped line
//Parameters: stripped line, stack, queue
//Return: none
void fillData(string stripLine, stack<string> &stk, queue<string> &que)
{
  string letter;

  if(stk.empty() && que.isEmpty())
  {
        //fill stack loop 
        for(int i=0; i<stripLine.length(); i++)
          {
	    letter = stripLine[i];
	    stk.push(letter);
          }
        //fill queue loop
	for(int i=0; i<stripLine.length(); i++)
	  {
	    letter = stripLine[i];
	    que.push(letter);
	  }
  }
  else
    cout << "Cannot fill because stack and queue are not empty";


 return;
}
//Name: testString
//Description: process string to see if it is a palindrome
//Parameters: stripped line, stack, queue
//Return: bool
bool testString(stack<string> &stk, queue<string> &que)
{
  while(!stk.empty() && !que.isEmpty())
  {
      if(stk.top() == que.front())
	{
          stk.pop();
          que.pop();
        } 
      else
	 return false;
    }
  return true;
}
