#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node*head;
    node(int data){
        this->data=data;
        this->next=NULL;
    }

};