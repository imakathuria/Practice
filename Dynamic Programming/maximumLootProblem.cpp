#include<bits/stdc++.h>
using namespace std;
/*
Sample input
4
2 3 1000 2000

6
5 5 10 100 10 5
*/
int maxlootDP(int n,int *arr){
    int *ans=new int[n+1];
    ans[0]=0;
    ans[1]=arr[0];
    for(int i=2;i<=n;i++){
        ans[i]=max(ans[i-1],ans[i-2]+arr[i-1]);
    }
    int x=ans[n];
    delete[]ans;
    return x;
}
int maxloot(int n,int*arr,int *ans){
    if(n<=0){
        // ans[0]=0;
        return 0;
    }
    if(ans[n]!=-1){
        return ans[n];
    }
    int y=maxloot(n-1,arr+1,ans);
    int x=maxloot(n-2,arr+2,ans)+arr[0];
    ans[n]=max(x,y);
    return max(x,y);
}
int maxLootMemoization(int n,int*arr){
    int *ans=new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i]=-1;
    }
    int x=maxloot(n,arr,ans);
    delete []ans;
    return x;
}



int MaxLootProblem(int n,int *arr){
    if(n<=0){
        return 0;
    }
    int x=MaxLootProblem(n-2,arr+2)+arr[0];
    int y=MaxLootProblem(n-1,arr+1);
    return max(x,y);
}
int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"DP Result : "<<maxlootDP(n,arr)<<endl;
    cout<<"Memoization result : "<<maxLootMemoization(n,arr)<<endl;
    cout<<"Recursion result : "<<MaxLootProblem(n,arr)<<endl;
    delete []arr;
}
