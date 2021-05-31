#include<iostream>
using namespace std;
#include "linkedlist.h"
/*
1 2 3 4 5
*/
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
node* insert(int index,node*head,int element){
    node*newnode=new node(element);
    if(index==0){
        newnode->next=head;
        head=newnode;
        
    }else{
        node*temp=head;
        while(index-1>0){
            temp=temp->next;
            index--;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    return head;
}
int main(){
    node*head=takeInput();
    print(head);
    insert(0,head,100);
    print(head);
    return 0;
}