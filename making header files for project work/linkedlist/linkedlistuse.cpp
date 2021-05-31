#include<iostream>
using namespace std;
#include "linkedlist.h"
void print(node*head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    // statically
    node n1(10);
    node*head=&n1;
    // obj
    node n2(20);
    n1.next = &n2;
    // cout<<n1.data<<" "<<n2.data<<endl;
    
    // dynamically
    node*obj=new node(30);
    obj->next=&n1;
    head=obj;
    print(head);
    return 0;
}