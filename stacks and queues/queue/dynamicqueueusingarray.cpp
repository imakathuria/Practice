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
    QueueUsingArray(){
        size=0;
        data=new T[5];
        capacity=5;
        FirstIndex=-1;
        NextIndex=0;
    }
    void insertElement(T d){
        if(size==capacity){
            T*newData=new T[2*capacity];
            int j=0;
            for(int i=FirstIndex;i<capacity;i++){
                newData[j++]=data[i];
            }
            for(int i=0;i<FirstIndex;i++){
                newData[j++]=data[i];
            }
            delete []data;
            data=newData;
            FirstIndex=0;
            NextIndex=capacity;
            capacity*=2;
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
        return ans;
    }
    int sizeOfQueue(){
        return size;
    }
    bool IsEmpty(){
        return size==0;
    }
    T top(){
        if(size==0){
            return 0;
        }
        return data[FirstIndex];
    }
};
int main(){
    // IsEmpty, top , sizeOfQueue,deleteElement,insertElement
    QueueUsingArray<int> q;
    for(int i=0;i<=100;i++){
        q.insertElement(i);
    }
    cout<<endl;
    for(int i=0;i<=100;i++){
        cout<<"IsEmpty : "<<q.IsEmpty() <<" top : "<< q.top()<<" sizeOfQueue : "<< q.sizeOfQueue()<<endl;
        q.deleteElement();
    }
    cout<<"IsEmpty : "<<q.IsEmpty() <<" top : "<< q.top()<<" sizeOfQueue : "<< q.sizeOfQueue()<<endl;
    return 0;
}
