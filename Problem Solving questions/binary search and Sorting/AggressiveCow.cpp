/*AGGRCOW - Aggressive cows
#binary-search
Farmer John has built a new long barn, with
N (2 <= N <= 100,000) stalls. The stalls are
located along a straight line at positions
x1,...,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout
and become aggressive towards each other once put into a stall.
To prevent the cows from hurting each other, FJ wants to assign
the cows to the stalls, such that the minimum distance between
any two of them is as large as possible. What is the largest
minimum distance?
Input
t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin<<t;
    while(t--){
        int n,c;
        cin>>n>>c;
        int *arr=new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int gap,start=1,end=n;
        gap=start+(end-start)/2;
        int prev;
        for(int )
        cout<<largestMinimumDistance()<<endl;
    }
}
