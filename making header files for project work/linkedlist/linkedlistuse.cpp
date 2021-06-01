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
        return head;
    }else{
        node*temp=head;
        while(temp and index-1>0){
            temp=temp->next;
            index--;
        }
        if(temp){
            newnode->next=temp->next;
            temp->next=newnode;
            return head;
        }else{
            return head;
        }
    }
    return head;
}
node*deletenode(node*head,int index){
    if(index==0){
        if(!head)return head;
        node*a=head;
        head=head->next;
        delete a;
        return head;
    }
    else{
        int count=0;
        node*temp=head;
        while(temp && count<index-1){
            temp=temp->next;
            count++;
        }
        if(!temp){
            return head;
        }
        node*b=temp->next;
        if(temp->next){
            temp->next=temp->next->next;
        }
        delete b;
        return head;
    }
}
node*insert_node_recursively(node*head,int index,int val){
    if(!head)return head;
    if(index==0){
        node*newnode=new node(val);
        newnode->next=head;
        head=newnode;
        return head;
    }
    node*sa=insert_node_recursively(head->next,index-1,val);
    head->next=sa;
    return head;

}

node*deleteNode_recursively(node*head,int index){
    if(head==NULL){
        return head;
    }
    if(index==0){
        node*a=head;
        head=head->next;
        delete a;
    }
    node*sa=deleteNode_recursively(head->next,index-1);
    head->next=sa;
    return head;
}
int main(){
    node*head=takeInput();
    print(head);
    cout<<endl;
    head=insert(0,head,100);
    print(head);
    cout<<endl;
    head=deletenode(head,0);
    print(head);
    cout<<endl;
    head=deleteNode_recursively(head,0);
    print(head);
    cout<<endl;
    head=insert_node_recursively(head,3,500);
    print(head);
    cout<<endl;
    head=insert_node_recursively(head,0,1000);
    print(head);
    cout<<endl;
    return 0;
}