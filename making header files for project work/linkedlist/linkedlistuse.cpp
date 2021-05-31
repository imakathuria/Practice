#include<iostream>
using namespace std;
#include "linkedlist.h"
node*takeInput(){
    int data;
    cin>>data;
    node*head=NULL,*tail=NULL;
    while(data!=-1){
        node*newnode=new node(data);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }else{
            tail->next=newnode;
            tail=tail->next;
        }
        cin>>data;
    }
    return head; 
}
void print(node*head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    node*head=takeInput();
    print(head);
    return 0;
}