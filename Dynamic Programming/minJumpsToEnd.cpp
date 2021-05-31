#include<bits/stdc++.h>
using namespace std;
// O(N*N)
// int main(){
//     int n;
//     cin>>n;
//     int *arr=new int[n];
//     int *dp=new int[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//         dp[i]=INT_MAX;
//     }
//     dp[0]=0;
//     for(int i=1;i<n;i++){
//         for(int j=0;j<i;j++){
//             if(dp[j]!=INT_MAX and arr[j]+j>=i){
//                 if(dp[j]+1<dp[i]){
//                     dp[i]=dp[j]+1;
//                 }
//             }
//         }
//     }
//     if(dp[n-1]!=INT_MAX){
//         cout<<dp[n-1]<<endl;
//     }
//     else{
//         cout<<-1<<endl;
//     }
// }
int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    // int *dp=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        // dp[i]=INT_MAX;
    }
    // dp[0]=0;
    int maxReach=arr[0];
    int steps=arr[0];
    int jumps=1;
    if(n==1 || n==0){
        cout<<0<<endl;
        return 0;
    }
    else if(arr[0]==0){
        cout<<-1<<endl;
        return 0;
    }else{
        for(int i=1;i<n;i++){
            if(i==n-1){
                cout<<jumps<<endl;
                return 0;
            }
            maxReach=max(maxReach,arr[i]+i);
            steps--;
            if(steps==0){
                jumps++;
                if(i>=maxReach)return -1;
                steps=maxReach-i;
            }
        }
    }
}
