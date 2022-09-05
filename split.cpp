/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <iostream>     // namespaces
using namespace std;

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  Node* ptr;
  if(in != nullptr){ ptr= in->next;}
  if(in == nullptr){return;} 
  else
  {
  
    if(in->value %2 == 0) // if this node has even number
    {
      //store this node to evens LL
      evens = in; //double check if this means 'evens' head ptr pointing 'in's head ptr
      evens->next = nullptr;
      split(ptr, odds, evens->next);
    } else 
   {
      odds = in;
      odds->next = nullptr;
      split(ptr, odds->next, evens);
    }
  }

  
  
  //chech bugs
  if(in != nullptr){
    //cout <<"?"<<endl;
    cout<< "ptr(backqard): "<<in->value<<endl;
  }
  if(odds != nullptr){
    //cout <<"?"<<endl;
    cout<< "odds (backqard): "<<odds->value<<endl;
  }
  //if(odds->next != nullptr){                                //problematic
  //  cout <<"?"<<endl;
  //  cout<< "odds->next (backqard): "<<odds->value<<endl;
  //}
  if(evens != nullptr){
    //cout <<"?"<<endl;
    cout<< "evens (backqard): "<<evens->value<<endl;
  }
  //if(evens->next != nullptr){
  //  cout <<"?"<<endl;
  //  cout<< "evens->next (backqard): "<<evens->value<<endl;
  //}
  


  //delete in;
  //end mechanism is not necessary Ig...
  //I believe I don't have to delete the ptr here...

}