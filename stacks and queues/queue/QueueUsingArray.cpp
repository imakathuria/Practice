#include<bits/stdc++.h>
using namespace std;
template <typename T>
class QueueUsingArray{
    T* data;
    int size;
    int FirstIndex;
    int NextIndex;
    int capacity;
public:
    QueueUsingArray(int s){
        size=0;
        data=new T(s);
        capacity=s;
        FirstIndex=-1;
        NextIndex=0;
    }
    void insertElement(T d){
        if(size==capacity){
            cout<<"queue full"<<endl;
            return;
        }
        data[NextIndex]=d;
        NextIndex=(NextIndex+1)%capacity;
        if(FirstIndex==-1){
            FirstIndex=0;
        }
        size++;
    }
    T deleteElement(){
        if(size==0){
            cout<<"Queue Empty";
            return 0;
        }
        T ans=data[FirstIndex];
        FirstIndex=(FirstIndex+1)%capacity;
        size--;
    }
    int sizeOfQueue(){
        return size;
    }
    bool IsEmpty(){
        return size==0;
    }
    T top(){
        if(IsEmpty()){
            cout<<"queue empty";
            return 0;
        }
        return data[FirstIndex];
    }
};
int main(){
    // IsEmpty, top , sizeOfQueue,deleteElement,insertElement
    QueueUsingArray<int> q(5);
    for(int i=0;i<=5;i++){
        q.insertElement(i*10);
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    for(int i=0;i<5;i++){
        cout<<"IsEmpty : "<<q.IsEmpty() <<" top : "<< q.top()<<" sizeOfQueue : "<< q.sizeOfQueue()<<endl;
        q.deleteElement();
    }
    cout<<" top : "<< q.top();
    return 0;
}
