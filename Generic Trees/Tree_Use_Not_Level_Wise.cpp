#include<iostream>
using namespace std;
#include "TreeNode.h"
TreeNode<int>* takeInputRecursively(){
    int x;
    cout<<"Enter Data";
    cin>>x;
    TreeNode<int>* root=new TreeNode<int>(x);
    cout<<endl;
    cout<<"Enter number of children of "<<x;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        TreeNode<int>*child=takeInputRecursively();
        root->children.push_back(child);
    }
    return root;
}
void PrintTreeRecursively(TreeNode<int>*root){
    cout<<root->data<<" : ";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<" ";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        PrintTreeRecursively(root->children[i]);
    }
}
int main(){
    TreeNode<int>*root=takeInputRecursively();
    PrintTreeRecursively(root);
}
