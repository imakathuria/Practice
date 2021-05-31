#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void InplaceHeapSort(int *arr,int n){
    for(int i=1;i<n;i++){
        int child=i;
        int parent=(child-1)/2;
        while(child>0 && arr[child]<arr[parent]){
            swap(arr[child],arr[parent]);
            child=parent;
            parent=(child-1)/2;
        }
    }
}
void printtheArray(int * a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void remove_minimum_element_in_heap(int *arr,int n){
    /*
        step 1: store value of zeroth element in some variable
        step 2: put value of n th element in the zeroth index
        step 3: Down heapify wala process lagana hai
        step 4: nextindex-- karna hai...
    */
    if(n==0){
        return ;
    }
    cout<<arr[0]<<" ";
    arr[0]=arr[n-1];
    int parent=0;
    int childleft=1;
    int childright=2;
    while(childleft<n-1){
        int minIndex=parent;
        if(arr[childleft]<arr[parent]){
            minIndex=childleft;
        }
        if(arr[minIndex]>arr[childright]){
            minIndex=childright;
        }
        if(minIndex==parent){
            return ;
        }
        swap(arr[minIndex],arr[parent]);
        parent=minIndex;
        childleft=(2*parent)+1;
        childright=(2*parent)+2;
    }
    // return ans;
}
int main(){
    int arr[10];
    int n=10,j=10;
    for(int i=0;i<10;i++){
        arr[i]=10-i;
    }
    InplaceHeapSort(arr,n);
    printtheArray(arr,n);
    cout<<"Now statrting to remove elements"<<endl;

    //Basically sorting happens
    for(int i=0;i<j;i++){
        remove_minimum_element_in_heap(arr,n);
        n--;
    }
    cout<<"THE END"<<endl;
    return 0;
}
