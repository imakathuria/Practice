#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeNodeClass.h"
BinaryTreeNode<int>* takeInputLevelWise(){
    int data;
    cout<<"Enter Root data : ";
    queue<BinaryTreeNode<int>*> pn;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(data);
    pn.push(root);
    while(pn.size()!=0){
        BinaryTreeNode<int>*front=pn.front();
        pn.pop();
        cout<<"enter left child of "<<front->data<<endl;
        int lc;
        cin>>lc;
        if(lc!=-1){
            BinaryTreeNode<int>*lcd=new BinaryTreeNode<int>(lc);
            front->left=lcd;
            pn.push(lcd);
        }

        cout<<"enter right child of "<<front->data<<endl;
        int rc;
        cin>>rc;
        if(rc!=-1){
            BinaryTreeNode<int>*rcd=new BinaryTreeNode<int>(rc);
            front->right=rcd;
            pn.push(rcd);
        }
    }
    return root;
}
void PrintTreeRecursively(BinaryTreeNode<int>*root){
    queue<BinaryTreeNode<int>*> pn;
    pn.push(root);
    while(pn.size()!=0){
        BinaryTreeNode<int>*front=pn.front();
        pn.pop();
        cout<<front->data<<" : ";
        if(front->left){
            cout<<"L -> "<<front->left->data;
            pn.push(front->left);
        }
        if(front->right){
            cout<<"  ||  R->"<<front->right->data;
            pn.push(front->right);
        }
        cout<<endl;
    }
}
int main(){
    //5 2 3 1 9 7 8 -1 -1 -1 -1 -1 -1 -1 -1
    cout<<"lets begin\n!!!!!"<<endl;
    BinaryTreeNode<int>*root=takeInputLevelWise();
    cout<<endl;
    PrintTreeRecursively(root);
    return 0;
}
