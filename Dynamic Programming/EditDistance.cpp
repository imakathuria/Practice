#include<bits/stdc++.h>
using namespace std;
/*Edit DP approach*/
int editDistanceDP(string s1,string s2){
    int **arr=new int*[s1.length()+1];
    for(int i=0;i<=s1.length();i++){
        arr[i]=new int[s2.length()+1];
    }
    for(int i=0;i<=s1.length();i++){
        arr[i][0]=i;
    }
    for(int j=0;j<=s2.length();j++){
        arr[0][j]=j;
    }
    int x=s1.length(),y=s2.length();
    for(int i=1;i<=s1.length();i++){
        for(int j=1;j<=s2.length();j++){
            if(s1[x-i]==s2[y-j]){
                arr[i][j]=arr[i-1][j-1];
            }else{
                arr[i][j]=min(arr[i-1][j-1],min(arr[i-1][j],arr[i][j-1]))+1;
            }
        }
    }
    return arr[s1.length()][s2.length()];
}
/*memoization*/
int editDistanceHelperMemoization(string s1,string s2,int **arr){
    if(s1.length()==0 || s2.length()==0){
        arr[s1.length()][s2.length()]=max(s1.length(),s2.length());
        return max(s1.length(),s2.length());
    }
    if(arr[s1.length()][s2.length()]!=-1){
        return arr[s1.length()][s2.length()];
    }
    if(s1[0]==s2[0]){
        return editDistanceHelperMemoization(s1.substr(1),s2.substr(1),arr);
    }
    int del = editDistanceHelperMemoization(s1,s2.substr(1),arr);
    int ins = editDistanceHelperMemoization(s1.substr(1),s2,arr);
    int update = editDistanceHelperMemoization(s1.substr(1),s2.substr(1),arr);
    arr[s1.length()][s2.length()]=min(del,min(ins,update))+1;
    return min(del,min(ins,update))+1;
}
int editDistanceMemoization(string s1,string s2){
    int **arr=new int*[s1.length()+1];
    for(int i=0;i<s1.length()+1;i++){
        arr[i]=new int[s2.length()+1];
        for(int j=0;j<s2.length()+1;j++){
            arr[i][j]=-1;
        }
    }
    return editDistanceHelperMemoization(s1,s2,arr);
}
int editDistance(string s1,string s2){
    if(s1.length()==0 || s2.length()==0){
        return max(s1.length(),s2.length());
    }
    if(s1[0]==s2[0])return editDistance(s1.substr(1),s2.substr(1));
    int del = editDistance(s1,s2.substr(1));
    int ins = editDistance(s1.substr(1),s2);
    int update = editDistance(s1.substr(1),s2.substr(1));
    return min(del,min(ins,update))+1;
}
/*sample input
saturdaykamajaaeagasaregharpehoengvsdhskdfjb
sujndasareayaeagasareghaenvsdhskdfjbsujndghoengvsdhskdfjb
*/
int main(){
    string s1,s2;
    cout<<"enter first string"<<endl;
    cin>>s1;
    cout<<"enter 2nd string"<<endl;
    cin>>s2;
    cout<<"DP : "<<editDistanceDP(s1,s2)<<" Memoization : "<<editDistanceMemoization(s1,s2)<<" bruteforce : "<<editDistance(s1,s2)<<endl;

}
