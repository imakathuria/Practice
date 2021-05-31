#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int knap_DP(int n,int *weights,int*values,int maxweight){
    int **arr=new int*[n+1];
    for(int i=0;i<=n;i++){
        arr[i]=new int[maxweight+1];
    }
    for(int i=0;i<=n;i++){
        arr[i][0]=0;
    }
    for(int i=0;i<=maxweight;i++){
        arr[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=maxweight;j++){
            int x=j-weights[n-i];
            if(x>=0){
                arr[i][j]=max(arr[i-1][j-weights[n-i]]+values[n-i],arr[i-1][j]);
            }else{
                arr[i][j]=arr[i-1][j];
            }
        }
    }
    return arr[n][maxweight];
}
/*........................................................................................*/
int knapsack_Memoization_Helper(int n,int*weights,int * values,int maxweight,int ** arr){
    if(n==0 ||maxweight==0){
        arr[n][maxweight]=0;
        return 0;
    }
    if(arr[n][maxweight]!=-1){
        return arr[n][maxweight];
    }
    if(weights[0]>maxweight){
        return knapsack_Memoization_Helper(n-1,weights+1,values+1,maxweight,arr);
    }
    int x=knapsack_Memoization_Helper(n-1,weights+1,values+1,maxweight-weights[0],arr)+values[0];
    int y=knapsack_Memoization_Helper(n-1,weights+1,values+1,maxweight,arr);
    arr[n][maxweight]=max(x,y);
    return max(x,y);
}
int knapsack_Memoization(int n,int*weights,int * values,int maxweight){
    int**arr=new int*[n+1];
    for(int i=0;i<=n;i++){
        arr[i]=new int[maxweight+1];
        for(int j=0;j<=maxweight;j++){
            arr[i][j]=-1;
        }
    }
    return knapsack_Memoization_Helper(n,weights,values,maxweight,arr);
}

/*........................................................................................*/
/*........................................................................................*/
/*........................................................................................*/


int knapsack(int n,int*weights,int * values,int maxweights){
    if(n==0 || maxweights==0){
        return 0;
    }
    if(weights[0]>maxweights){
        return knapsack(n-1,weights+1,values+1,maxweights);
    }
    int x=knapsack(n-1,weights+1,values+1,maxweights-weights[0])+values[0];
    int y=knapsack(n-1,weights+1,values+1,maxweights);
    return max(x,y);
}
/*sample input
5
12 7 11 8 9
24 13 23 15 16
26

5
5 4 6 3 2
8 7 5 5 4
9a

larger input
120
9 1 2 3 6 4 5 10 6 4 9 1 2 3 6 4 5 10 6 4 9 1 2 3 6 4 5 10 6 4 9 1 2 3 6 4 5 10 6 4 9 1 2 3 6 4 5 10 6 4 9 1 2 3 6 4 5 10 6 4 9 1 2 3 6 4 5 10 6 4 9 1 2 3 6 4 5 10 6 4 9 1 2 3 6 4 5 10 6 4 9 1 2 3 6 4 5 10 6 4 9 1 2 3 6 4 5 10 6 4 9 1 2 3 6 4 5 10 6 4
9 1 10 2 3a 6 4 5 5 10 6 4 6 4 9 1 2 3 6 4 9 1 10 2 3 6 4 5 5 10 6 4 6 4 9 1 2 3 6 4 9 1 10 2 3 6 4 5 5 10 6 4 6 4 9 1 2 3 6 4 9 1 2 3 6 4 5 10 6 4 9 1 2 3 6 4 5 10 6 4 9 1 2 3 6 4 5 10 6 4 9 1 2 3 6 4 5 10 6 4 9 1 2 3 6 4 5 10 6 4 9 1 2 3 6 4 5 10 6 4
680
*/
int main(){
    int n;
    cout<<"enter the no of items"<<endl;
    cin>>n;
    int *weights=new int[n];
    int *values=new int[n];
    cout<<"weights"<<endl;
    for(int i=0;i<n;i++){
        cin>>weights[i];
    }
    cout<<"values"<<endl;
    for(int i=0;i<n;i++){
        cin>>values[i];
    }
    int maxweights;
    cout<<"Maxweights : ";
    cin>>maxweights;
    cout<<endl;
    cout<<"DP result : "<<knap_DP(n,weights,values,maxweights)<<endl;
    cout<<"Memoization result : "<<knapsack_Memoization(n,weights,values,maxweights)<<endl;
    cout<<"Bruteforce Result : "<<knapsack(n,weights,values,maxweights)<<endl;

}
