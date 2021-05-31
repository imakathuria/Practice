#include<iostream>
using namespace std;
#include"priorityQueue.h"
#include<cstdlib>
int main(){
    PriorityQueue p;
    for(int i=0;i<10;i++){
        int n=rand();
        p.insert(n);
    }
    cout<<"Size of heap : "<< p.getsize()<<endl;
    cout<<"min element : " << p.getMin()<<endl;
    while(!p.isEmpty()){
        cout<<"top element removed is : " << p.removeMin()<<endl;
    }
    cout<<"\n\n";
    cout<<p.getsize();
}
