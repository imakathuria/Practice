#include<bits/stdc++.h>
using namespace std;
class StackClass{
private:
  int *data;//array naming data
  int capacity;
  int nextindex;
public:
  StackClass(int size){
    data=new int[size];
    capacity=size;
    nextindex=0;
  }
  void InsertElement(int x){
    if(nextindex==capacity){
      cout<<"Stack is full"<<endl;
      return ;
    }
    data[nextindex]=x;
    nextindex++;
  }
  int DeleteElement(){
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
  int TopElement(){
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
  StackClass s(5);
  s.InsertElement(10);
  s.InsertElement(20);
  s.InsertElement(30);
  s.InsertElement(40);
  s.InsertElement(50);
  s.InsertElement(60);
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
