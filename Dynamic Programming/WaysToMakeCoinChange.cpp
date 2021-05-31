#include<bits/stdc++.h>
using namespace std;
/*..DP solution*/
int WaysToMakeCoinChange_DP(int n,int*arr,int sum){
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[sum+1];
    }
    for(int j=0;j<=sum;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        dp[i][0]=1;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j-arr[i-1]>=0){
                dp[i][j]=dp[i-1][j]+dp[i][j-arr[i-1]];
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    int ans_=dp[n][sum];
    for(int i=0;i<=n;i++){
        delete []dp[i];
    }
    delete []dp;
    return ans_;
}
/*..Memoization solution..*/
int WaysToMakeCoinChange(int n,int*arr,int sum,int **ans){
    if(sum==0){
        return 1;
    }
    if(sum<0 || n<=0){
        return 0;
    }
    if(ans[n][sum]!=-1){
        return ans[n][sum];
    }

    int x=WaysToMakeCoinChange(n-1,arr+1,sum,ans);
    int y=WaysToMakeCoinChange(n,arr,sum-arr[0],ans);
    ans[n][sum]=x+y;
    return x+y;
}
int WaysToMakeCoinChange_memoization(int n,int *arr,int sum){
    int **ans=new int*[n+1];
    for(int i=0;i<=n;i++){
        ans[i]=new int[sum+1];
        for(int j=0;j<=sum;j++){
            ans[i][j]=-1;
        }
    }
    return WaysToMakeCoinChange(n,arr,sum,ans);
}
/*..bruteforce solution..*/
int WaysToMakeCoinChange(int n,int*arr,int sum){
    if(sum==0){
        return 1;
    }
    if(sum<0 || n<=0){
        return 0;
    }
    int x=WaysToMakeCoinChange(n-1,arr+1,sum);
    int y=WaysToMakeCoinChange(n,arr,sum-arr[0]);
    return x+y;
}
int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum;
    cin>>sum;
    cout<<"DP : "<<WaysToMakeCoinChange_DP(n,arr,sum)<<endl;
    cout<<"Memoization : "<<WaysToMakeCoinChange_memoization(n,arr,sum)<<endl;
    cout<<"Recursion : "<<WaysToMakeCoinChange(n,arr,sum)<<endl;
}
