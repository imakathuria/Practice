#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeNodeClass.h"
BinaryTreeNode<int>* takeInputRecursively(){
    int data;
    cout<<"Enter data : ";
    cin>>data;
    if(data==-1){
        return NULL;
    }
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(data);
    root->left=takeInputRecursively();
    root->right=takeInputRecursively();
    return root;
}
void PrintTreeRecursively(BinaryTreeNode<int>*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" : ";
    if(root->left!=NULL){
        cout<<"L : "<<root->left->data;
    }
    if(root->right!=NULL){
        cout<<"  ||  R : "<<root->right->data;
    }
    cout<<endl;
    PrintTreeRecursively(root->left);
    PrintTreeRecursively(root->right);
}
int main(){
    //IP 5 2 1 -1 -1 9 -1 -1 3 7 -1 -1 8 -1 -1
    cout<<"lets begin\n!!!!!"<<endl;
    BinaryTreeNode<int>*root=takeInputRecursively();
    cout<<endl;
    PrintTreeRecursively(root);
    return 0;
}
