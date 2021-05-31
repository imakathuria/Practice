#include<bits/stdc++.h>
using namespace std;
#include"NodeClass.h"
template <typename T>
class QueueLL{
private:
    int size;
    Node<T>*head;
    Node<T>*tail;
public:
    QueueLL(){
        size=0;
        head=NULL;
        tail=NULL;
    }
    Node<T>* enqueue(T x){
        Node<T>*newNode=new Node<T>(x);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
        size++;
        return head;
    }
    Node<T>* dequeue(){
        if(!head){
            cout<<" queue empty ";
            return 0;
        }
        T x=head->data;
        Node<T>*nn=head;
        head=head->next;
        delete nn;
        size--;
        return head;
    }
    T top(){
        if(head){
            return head->data;
        }
        return 0;
    }
    int sizeQueue(){
        return size;
    }
    bool isempty(){
        return size==0;
    }
};
int main(){
    QueueLL<int> obj;
    obj.enqueue(10);
    obj.enqueue(20);
    obj.enqueue(30);
    obj.enqueue(40);
    obj.enqueue(50);
    obj.enqueue(60);
    for(int i=0;i<=6;i++){
        cout<<"top : "<<obj.top()<<" size : "<<obj.sizeQueue()<<" isempty ? : "<<obj.isempty()<<endl;
        obj.dequeue();
    }
    return 0;
}
