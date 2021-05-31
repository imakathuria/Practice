#include<bits/stdc++.h>
#include<queue>
#include<iostream>
using namespace std;
#include "TreeNode.h"
TreeNode<int>* takeInputLevelWise(){
    int x;
    cout<<"Enter Data";
    cin>>x;
    queue<TreeNode<int>*> PendingNodes;
    TreeNode<int>* root=new TreeNode<int>(x);
    PendingNodes.push(root);
    cout<<endl;
    while(PendingNodes.size()!=0){
        TreeNode<int>*front=PendingNodes.front();
        PendingNodes.pop();
        cout<<"Enter number of children of "<<front->data;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cout<<"Enter "<<i<<" child of "<<front->data<<endl;
            int x;
            cin>>x;
            TreeNode<int>* child=new TreeNode<int>(x);
            front->children.push_back(child);
            PendingNodes.push(child);
        }
    }
    cout<<endl;
    return root;
}
void PrintTreeLevelWise(TreeNode<int>*root){
    queue<TreeNode<int>*> PendingNodes;
    PendingNodes.push(root);
    while(PendingNodes.size()!=0){
        TreeNode<int>*front=PendingNodes.front();
        PendingNodes.pop();
        cout<<front->data<<" : ";
        for(int i=0;i<front->children.size();i++){
            cout<<front->children[i]->data<<" ";
            PendingNodes.push(front->children[i]);
        }
        cout<<endl;
    }
}
int Find_Count(TreeNode<int>*root){
    int ans=1;
    for(int i=0;i<root->children.size();i++){
        ans+=Find_Count(root->children[i]);
    }
    return ans;
}
int SumOfAllNodes(TreeNode<int>*root){
    int ans=root->data;
    for(int i=0;i<root->children.size();i++){
        ans+=SumOfAllNodes(root->children[i]);
    }
    return ans;
}
int MaxOfAllNodes(TreeNode<int>*root){
    int m=root->data;
    for(int i=0;i<root->children.size();i++){
        m=max(m,MaxOfAllNodes(root->children[i]));
    }
    return m;
}
template <typename T>
class Node{
public:
    TreeNode<T>* ptr;
    T sum;
    Node(){
        sum=0;
    }
};
Node<int>* Node_with_maximum_child_sum(TreeNode<int>*root){
    if(root==NULL){
        Node<int>*ans=new Node<int>;
        ans->ptr=NULL;
        ans->sum=INT_MIN;
        return ans;
    }
    Node<int>*ans=new Node<int>;
    ans->ptr=root;
    ans->sum=root->data;
    for(int i=0;i<root->children.size();i++){
        ans->sum+=root->children[i]->data;
    }
    Node<int>*res=NULL;
    for(int i=0;i<root->children.size();i++){
        res=Node_with_maximum_child_sum(root->children[i]);
        if(ans->sum<res->sum){
            ans=res;
        }
    }
    return ans;
}
TreeNode<int>*maxchildsum(TreeNode<int>*root){
    return Node_with_maximum_child_sum(root)->ptr;
}

int main(){
    // ip 5 2 2 3 2 1 9 2 7 8 0 0 0 0
    TreeNode<int>*root=takeInputLevelWise();
    PrintTreeLevelWise(root);
    TreeNode<int>*res=maxchildsum(root);
    cout<<"Node with maximum child sum : "<<res->data<<endl;
    cout<<"Total No. Of Nodes "<<Find_Count(root)<<endl;
    cout<<"Sum of all nodes = "<<SumOfAllNodes(root)<<endl;
    cout<<"Max of All Nodes = "<<MaxOfAllNodes(root)<<endl;

    return 0;
}
