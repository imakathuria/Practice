#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int DP_Optimized_For_Knapsack(int n,int *weights,int *values,int maxweights){
    int **arr=new int*[2];
    for(int i=0;i<2;i++){
        arr[i]=new int[maxweights+1];
        for(int j=0;j<=maxweights;j++){
            arr[i][j]=0;
        }
    }

    int i=0;
    while(i<n){
        if(i%2==0){
            int j=0;
            while(j<=maxweights){
                if(weights[i]<=j){
                    arr[0][j]=max(values[i]+arr[1][j-weights[i]],arr[1][j]);
                }else{
                    arr[0][j]=arr[1][j];
                }
                j++;
            }
        }
        if(i%2==0){
            int j=0;
            while(j<=maxweights){

                if(weights[i]<=j){
                    arr[1][j]=max(values[i]+arr[0][j-weights[i]],arr[0][j]);
                }else{
                    arr[1][j]=arr[0][j];
                }
                j++;
            }
        }
        i++;
    }
    if(n%2==0){
        int ans=arr[1][maxweights];
        for(int i=0;i<n;i++){
            delete []arr[i];
        }
        delete []arr;
        return ans;
    }else{
        int ans=arr[0][maxweights];
        for(int i=0;i<n;i++){
            delete []arr[i];
        }
        delete []arr;
        return ans;
    }
}
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
    cout<<DP_Optimized_For_Knapsack(n,weights,values,maxweights);

}
