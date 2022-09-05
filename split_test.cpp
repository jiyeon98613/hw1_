#include "split.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>  
#include <iostream>     // namespaces
using namespace std;

int main()
{
    int ranNum;

    /* initialize random seed: */
    srand (time(NULL));

    //cout <<"??"<<endl;  //here works
    /* create testLL */
     

    /*Make the first node and bunch of pointers */
    ranNum = rand() % 1000 + 1;
    Node * test = new Node(ranNum, nullptr);

    Node* head2 = test; //tracker2
    //Node* head3 = test; //tracker2
    Node*  odd; 
    Node*  even;
    int a = 1;


    /*make a singly LL and print the result*/
    cout << a++ <<" "<<head2->value<<endl;
    for (int i=0; i< 9; ++i)
    {
        // cout <<"!!"<<endl;  //this loop works
        ranNum = rand() % 1000 + 1;
        head2->next = new Node(ranNum, nullptr);
        head2 = head2->next;
        cout << a++ <<" "<<head2->value<<endl;
    }
    //cout<<"This is another printing test."<<endl;


    //if(head == nullptr) {cout <<"yes"<<endl;} 
    //if(test == nullptr) {cout <<"yes"<<endl;}
    //cout<<"This is another printing test."<<endl;
    Node* head = test;  //tracker1
    //cout << head->value<<endl;
//    cout<< head->next->value<<endl;
    if(head->next == nullptr){cout<<"yes"<<endl;}
    while (head != nullptr)
    {
        cout << head->value << " ";
        head = head->next;

    }
    cout <<endl;
    
    
    cout <<"?"<<endl;
    //split to two LLs    //works
    split(test, odd, even);                 
    cout <<"!"<<endl;  //works
    //print the LLS
    cout << even->value<< endl;
    cout << odd->value<<endl;;

    while (odd->next != nullptr)
    {
        cout << odd->value << " ";
        odd = odd->next;

    }
    cout << odd->value <<endl;
    
    while (even->next != nullptr)
    {
        cout << even->value << " ";
        even = even->next;
    }
    cout <<even->value <<endl;  

    //delete test, odd, even;
    

    /*for (int i=0; i<= 9; i++)
    {   Node* p = head2->next;
        delete head2;
        head2 = p;
    }*/

}