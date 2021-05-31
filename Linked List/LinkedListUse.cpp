#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node*next;
    Node(int d){
      this->data=d;
      next=NULL;
    }
};
void Print(Node*head){
  Node*temp=head;
  while(temp){
    cout<<temp->data <<" ";
    temp=temp->next;
  }
  cout<<endl;
}
Node* TakeInputBetter(){
  int data;
  cin>>data;
  Node*head=NULL;
  Node*tail=NULL;
  while(data!=-1){
    Node*newNode=new Node(data);
    if(head==NULL){
      head=newNode;
      tail=newNode;
    }
    else{
      tail->next=newNode;
      tail=newNode;
    }
    cin>>data;
  }
  return head;
}
int main(){
  Node*head = TakeInputBetter();
  cout<<"Printing Linked List"<<endl;
  Print(head);
  return 0;
}
