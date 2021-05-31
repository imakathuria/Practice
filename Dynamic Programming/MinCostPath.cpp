#include<bits/stdc++.h>
using namespace std;
/*...DP approach...*/
int min_costDP(int n,int m,int **arr){
    if(n<0||m<0){
        return 0;
    }
    int **ans=new int *[n];
    for(int i=0;i<n;i++){
        ans[i]=new int[m];
    }
    ans[n-1][m-1]=arr[n-1][m-1];
    for(int i=n-2;i>=0;i--){
        ans[i][m-1]=arr[i][m-1]+ans[i+1][m-1];
    }
    for(int i=m-2;i>=0;i--){
        ans[n-1][i]=arr[n-1][i]+ans[n-1][i+1];
    }
    for(int i=n-2;i>=0;i--){
        for(int j=m-2;j>=0;j--){
            ans[i][j]=min(ans[i][j+1],min(ans[i+1][j+1],ans[i+1][j]))+arr[i][j];
        }
    }
    return ans[0][0];
}

/*...Memoization approach...*/
int minCost_usingMemoizationHelper(int n,int m,int i,int j,int **ans,int **arr){
    if(i==n-1 && j==m-1){
        ans[i][j]= arr[i][j];
        return arr[i][j];
    }
    if(i>=n || j>=m || i<0 || j<0){
        return INT_MAX;
    }
    if(ans[i][j]!=-1){
        return ans[i][j];
    }
    int x,y,z;
    x = minCost_usingMemoizationHelper(n,m,i+1,j+1,ans,arr);
    y = minCost_usingMemoizationHelper(n,m,i,j+1,ans,arr);
    z = minCost_usingMemoizationHelper(n,m,i+1,j,ans,arr);
    ans[i][j]=min(x,min(y,z))+arr[i][j];
    return ans[i][j];
}

int minCost_usingMemoization(int n,int m,int **arr){
    int **ans=new int *[n];
    for(int j=0;j<n;j++){
        ans[j]=new int[m];
        for(int i=0;i<m;i++){
            ans[j][i]=-1;
        }
    }
    return minCost_usingMemoizationHelper(n,m,0,0,ans,arr);
}
/*............................................................................*/
/*....Brute force approach....*/
int minCost_bruteforce(int n,int m,int i,int j,int **arr){
    if(i==n-1 && j==m-1){
        return arr[i][j];
    }
    if(i>=n || j>=m || i<0 || j<0){
        return INT_MAX;
    }
    int x,y,z;
    x=minCost_bruteforce(n,m,i+1,j,arr);
    y=minCost_bruteforce(n,m,i,j+1,arr);
    z=minCost_bruteforce(n,m,i+1,j+1,arr);
    return min(x,min(y,z))+arr[i][j];
}
int minCost(int n,int m,int **arr){
    return minCost_bruteforce(n,m,0,0,arr);
}
/*..............................................................................*/
int main(){
    int n,m;
    cout<<"enter the number of rows and columns in the matrix"<<endl;
    cin>>n>>m;
    cout<<"enter the matrix"<<endl;
    int **arr=new int*[n];

    for(int i=0;i<n;i++){
        arr[i]=new int[m];
    }
    for(int i=0;i<n;i++){
        for (int j=0;j<m;j++) {
            cin>>arr[i][j];
        }
    }
    cout<<"DP :"<<min_costDP(n,m,arr)<<endl;
    cout<<"Memoization :"<<minCost_usingMemoization(n,m,arr)<<endl;
    cout<<"bruteforce :"<<minCost(n,m,arr)<<endl;
    /*
    sample input
    80 10
    5 7 2 4 3 1 5 7 8 4
    1 8 1 3 5 7 2 4 3 1
    6 2 9 5 1 8 1 3 3 1
    1 6 2 8 5 7 8 8 1 3
    5 7 2 4 3 1 5 7 8 4
    1 8 1 3 5 7 2 4 3 1
    6 2 9 5 1 8 1 3 3 1
    1 6 2 8 5 7 8 8 1 3
    5 7 2 4 3 1 5 7 8 4
    1 8 1 3 5 7 2 4 3 1
    5 7 2 4 3 1 5 7 8 4
    1 8 1 3 5 7 2 4 3 1
    6 2 9 5 1 8 1 3 3 1
    1 6 2 8 5 7 8 8 1 3
    5 7 2 4 3 1 5 7 8 4
    1 8 1 3 5 7 2 4 3 1
    6 2 9 5 1 8 1 3 3 1
    1 6 2 8 5 7 8 8 1 3
    5 7 2 4 3 1 5 7 8 4
    1 8 1 3 5 7 2 4 3 1
    5 7 2 4 3 1 5 7 8 4
    1 8 1 3 5 7 2 4 3 1
    6 2 9 5 1 8 1 3 3 1
    1 6 2 8 5 7 8 8 1 3
    5 7 2 4 3 1 5 7 8 4
    1 8 1 3 5 7 2 4 3 1
    6 2 9 5 1 8 1 3 3 1
    1 6 2 8 5 7 8 8 1 3
    5 7 2 4 3 1 5 7 8 4
    1 8 1 3 5 7 2 4 3 1
    5 7 2 4 3 1 5 7 8 4
    1 8 1 3 5 7 2 4 3 1
    6 2 9 5 1 8 1 3 3 1
    1 6 2 8 5 7 8 8 1 3
    5 7 2 4 3 1 5 7 8 4
    1 8 1 3 5 7 2 4 3 1
    6 2 9 5 1 8 1 3 3 1
    1 6 2 8 5 7 8 8 1 3
    5 7 2 4 3 1 5 7 8 4
    1 8 1 3 5 7 2 4 3 1
    5 7 2 4 3 1 5 7 8 4
    1 8 1 3 5 7 2 4 3 1
    6 2 9 5 1 8 1 3 3 1
    1 6 2 8 5 7 8 8 1 3
    5 7 2 4 3 1 5 7 8 4
    1 8 1 3 5 7 2 4 3 1
    6 2 9 5 1 8 1 3 3 1
    1 6 2 8 5 7 8 8 1 3
    5 7 2 4 3 1 5 7 8 4
    1 8 1 3 5 7 2 4 3 1
    5 7 2 4 3 1 5 7 8 4
    1 8 1 3 5 7 2 4 3 1
    6 2 9 5 1 8 1 3 3 1
    1 6 2 8 5 7 8 8 1 3
    5 7 2 4 3 1 5 7 8 4
    1 8 1 3 5 7 2 4 3 1
    6 2 9 5 1 8 1 3 3 1
    1 6 2 8 5 7 8 8 1 3
    5 7 2 4 3 1 5 7 8 4
    1 8 1 3 5 7 2 4 3 1
    5 7 2 4 3 1 5 7 8 4
    1 8 1 3 5 7 2 4 3 1
    6 2 9 5 1 8 1 3 3 1
    1 6 2 8 5 7 8 8 1 3
    5 7 2 4 3 1 5 7 8 4
    1 8 1 3 5 7 2 4 3 1
    6 2 9 5 1 8 1 3 3 1
    1 6 2 8 5 7 8 8 1 3
    5 7 2 4 3 1 5 7 8 4
    1 8 1 3 5 7 2 4 3 1
    5 7 2 4 3 1 5 7 8 4
    1 8 1 3 5 7 2 4 3 1
    6 2 9 5 1 8 1 3 3 1
    1 6 2 8 5 7 8 8 1 3
    5 7 2 4 3 1 5 7 8 4
    1 8 1 3 5 7 2 4 3 1
    6 2 9 5 1 8 1 3 3 1
    1 6 2 8 5 7 8 8 1 3
    5 7 2 4 3 1 5 7 8 4
    1 8 1 3 5 7 2 4 3 1

    */
}
