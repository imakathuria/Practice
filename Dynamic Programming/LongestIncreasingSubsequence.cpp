#include<bits/stdc++.h>
using namespace std;
int longestIncreasingSubsequencee(int n,int *arr){
    int *dp=new int[n];
    dp[0]=1;
    for(int i=1;i<n;i++){
        dp[i]=1;
        for(int j=i-1;j>=0;j--){
            if(arr[j]>=arr[i]){
                continue;
            }
            int possibleAns=dp[j]+1;
            if(possibleAns>dp[i]){
                dp[i]=possibleAns;
            }
        }
    }
    int maxVal=0;
    for(int i=0;i<n;i++){
        if(dp[i]>maxVal){
            maxVal=dp[i];
        }
    }
    return maxVal;
}
int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<longestIncreasingSubsequencee(n,arr)<<endl;
    return 0;
}
