#include<iostream>
using namespace std;
#include "linkedlist.h"
int main(){
    // statically
    node n1(10);
    node*head=&n1;
    // obj
    node n2(20);
    n1.next = &n2;
    // cout<<n1.data<<" "<<n2.data<<endl;
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    return 0;
}