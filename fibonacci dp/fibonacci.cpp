#include<iostream>
using namespace std;
int main(){
  int n;
  cout<<"Enter n upto which you want to find the fibonacci series"<<endl;
  cin>>n;
  int *a=new int[n+1];
  a[0]=0;
  a[1]=1;
  int i;
  for( i=2;i<=n;i++){
    a[i]=a[i-1]+a[i-2];
  }
  cout<<a[n]<<endl;
  return 0;
}
