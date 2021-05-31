#include<bits/stdc++.h>
using namespace std;
template<typename T>
class StackClass{
private:
  T *data;//array naming data
  int capacity;
  int nextindex;
public:
  StackClass(){
    data=new T[1];
    capacity=0;
    nextindex=0;
  }
  void InsertElement(T x){
    if(nextindex==capacity){
      T*newData=new T[2*capacity];
      for(int i=0;i<capacity;i++){
        newData[i]=data[i];
      }
      delete data;
      data=newData;
      capacity*=2;
    }
    data[nextindex]=x;
    nextindex++;
  }
  T DeleteElement(){
    if(nextindex==0){
      cout<<"Stack is empty"<<endl;
      return 0;
    }
    nextindex--;
    return data[nextindex];
  }
  void PrintStack(){
    int i=0;
    while(i<nextindex){
      cout<<data[i++]<<" ";
    }
    cout<<endl;
  }
  T TopElement(){
    if(nextindex==0){
      cout<<"Stack is empty"<<endl;
      return 0;
    }
    return data[nextindex-1];
  }
  int SizeOfStack(){
    return nextindex;
  }
  bool IsEmpty(){
    return nextindex==0;
  }
};
int main(){
  cout<<"hello Akhil\nEnter Values in stack"<<endl;
  StackClass<int> s;
  s.InsertElement('a');
  s.InsertElement('b');
  s.InsertElement('c');
  s.InsertElement('d');
  s.InsertElement('e');
  s.InsertElement('f');
  cout<<s.TopElement()<<endl;
  cout<<s.SizeOfStack()<<endl;
  cout<<s.IsEmpty()<<endl;
  s.PrintStack();
  cout<<"deleting and Printing Elements"<<endl;
  while(!s.IsEmpty()){
    cout<<s.TopElement()<<" ";
    s.DeleteElement();
  }
  cout<<"\nNow the size of stack is :"<<s.SizeOfStack()<<endl;
  return 0;
}
