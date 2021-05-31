#include<bits/stdc++.h>
using namespace std;
int allways1(int x,int n,int s=1){
    //base case
    int val=x-pow(s,n);
    if(val==0){
        return 1;
    }if(val<0){
        return 0;
    }
    //recursive call
    //without including the current element
    int a=allways1(x,n,s+1);
    //Including the current element
    int b=allways1(val,n,s+1);
    //our work
    return a+b;
}
int getAllWays(int x, int n) {
    return allways1(x,n);
}
int main(){
    int x,n;
    cin>>x>>n;
    cout<<getAllWays(x,n);
    return 0;
}
