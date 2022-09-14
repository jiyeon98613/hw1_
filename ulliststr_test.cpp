#include "ulliststr.h"
#include <stdlib.h>     /* srand, rand */
#include<cmath>
#include <time.h>  
#include <iostream>
#include <string>
using namespace std;  


int main(int argc, char* argv[])
{
//initialize random seed
  srand (time(NULL));

  // create testLL
  //Make the first node and bunch of pointers
  ULListStr* ull1 = new ULListStr();
  
  

  int i=0;
  while(i < 2) //checking push_f: (if), (else)
  {
    string ranNum = "test:"+ to_string(rand() % 10000 + 1);
    ull1->push_front(ranNum);
    cout << ranNum << " "<<endl;
    i++;
  }
  while(i < 4)  //checking push_b: (elif), (else)
  {
    string  ranNum = "test:" + to_string(i);
    ull1->push_back(ranNum);
    cout << ranNum << " "<<endl;
    i++;
  }
  cout<<endl;
  //So far, there are 4 items in the val array

  int n=4;
  bool cp = true;
  while(cp) //checking pop_f-(else), pop_b-(else), pop_f-(if), pop_b-(elif) 
  {
    //tracker1
    ULListStr* ptr1 = ull1; 
    int m = 0, t = n;
    while(m < t) // print out the string array for every loop
    {
      cout << ptr1->get(m)<< ", ";
      m++;
    }
    cout <<endl;
    cout << "front = " << ptr1->front() <<", back = "<<ptr1->back()<<endl;

    //ULListStr* ptr2 = ull1; 
    if(n % 2 == 0){ptr1->pop_front();} 
    else{ptr1->pop_back();} 
    --n;
    if(ptr1->empty()){
      cp = false;
    }
  }
  ULListStr* ptr = ull1;
  ptr->push_back("a");      //checking push_b: (if)
  ptr->push_back("b");
  cout <<ptr->front()<< " "<<  ptr->back()<<endl; //should print "a b"
  ptr->pop_front(); 
  ptr->pop_front();         //checking pop_f: (elif)

  ptr->push_front("a");     //checking push_f: (elif)
  ptr->push_front("b");
  cout <<ptr->front()<< " "<<  ptr->back()<<endl; //should print "b a"
  ptr->pop_back(); 
  ptr->pop_back(); //checking pop_b: (elif)

  int num_str = 20;
  while(num_str != 0) // total of 20
  {
    ull1->push_back(to_string(rand() % 100000000 + 1));   //generate strings
    cout << ull1->back()<<endl;
    --num_str;
  }//num_str = 0
  while(num_str <20)
  {
    ull1->pop_back();   //delete strings
    ++num_str;
  }//num_str = 20

  while(num_str != 0) // total of 20
  {
    ull1->push_front(to_string(rand() % 10000 + 1));   //generate strings
    cout << ull1->front()<<endl;
    --num_str;
  }
  cout << "12th: " <<ull1->get(12)<< ", and 13th: "<< ull1->get(13)<<endl;
  cout << "after adding 20 strings, is empty? "<<ull1->empty()<<", size = "<<ull1->size()<<endl;
  while(num_str <20)
  {
    ull1->pop_front();   //delete strings
    ++num_str;
  }
  ull1->pop_front();
  cout << "after taking out all the strings, is empty? "<<ull1->empty()<<endl;
  while(num_str != 0) // total of 20
  {
    ull1->push_back(to_string(rand() % 100000000 + 1));   //generate strings
    cout << ull1->back()<<endl;
    --num_str;
  }//num_str = 0
  ull1->clear();
  delete ull1;
  cout << "after clear(), is empty? "<<ull1->empty()<<endl;
  return 0;
}
