#include <iostream>
using namespace std;
void print(int *arr,int n){
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    cout<<endl;
}
void reArrangeArray(int *arr,int n){
    int i,j;
    if(n==0 || n==1){
        return;
    }
    for( i=0,j=n-1;i<j;){
        if(arr[i]>=0)i++;
        else if(arr[j]<0)j--;
        else {
            swap(arr[i],arr[j]);
            i++,j--;
        }
    }
    print(arr,n);
    if(arr[j]>0)j++;
    int l=0,r=j;
    if(r==0 || r==n){
        return;
    }
    cout<<l<<" "<<r<<endl;

    for(;l<n and r<n;l+=2,r++){
        swap(arr[l],arr[r]);
    }
    return;
}

int main() {
// 	cout<<"GfG!";
	int n;
	cin>>n;
	int *arr=new int[n];
	for(int i=0;i<n;i++)cin>>arr[i];
	reArrangeArray(arr,n);
	print(arr,n);
	return 0;
}