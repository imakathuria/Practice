#include<iostream>
using namespace std;
#include "dynamicArray.h"
int main(){
    DynamicArray<char> d1;
    int n=10;
    for(int i=0;i<n;i++){
        d1.push(97+i);
    }
    d1.add(5,65);
    DynamicArray<char> d2(d1);
    d1.add(5,66);
    d1.print();
    d2.print();

}