#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Node{
public:
    T data;
    Node<T>*next;
    Node(T element){
        data=element;
        next=NULL;
    }
};
template<typename T>
class StackLL{
private:
    int size;
    Node<T>*head;
public:
    StackLL(){
        size=0;
        head=NULL;
    }

    Node<T>* InsertElement(T data){
        Node<T>*newNode=new Node<T>(data);
        newNode->next=head;
        head=newNode;
        size++;
    }
    T DeleteElement(){
        if(head){
            T value=head->data;
            Node<T>*temp=head;
            head=head->next;
            delete temp;
            return value;
            size--;
        }
        return 0;
    }
    int SizeofStack(){
        return size;
    }
    bool IsEmpty(){
        return size==0;
    }
    T TopElementOfStack(){
        if(head){
            return head->data;
        }
        return 0;
    }
};
int main(){
    StackLL<int> s;
    // TopElementOfStack , IsEmpty , SizeofStack , DeleteElement ,InsertElement
    s.InsertElement(13);
    s.InsertElement(23);
    s.InsertElement(33);
    s.InsertElement(43);
    s.InsertElement(53);
    s.InsertElement(63);
    cout<<"Size of Stack :"<<s.SizeofStack()<<endl;
    cout<<"IsEmpty"<<s.IsEmpty()<<endl;
    cout<<"Top Element Of Stack"<<s.TopElementOfStack()<<endl;
    int i=s.SizeofStack();
    while(i>=0){
        cout<<s.DeleteElement()<<" ";
        i--;
    }
    cout<<"Size of Stack :"<<s.SizeofStack()<<endl;
    cout<<"IsEmpty"<<s.IsEmpty()<<endl;
    return 0;
}
