#include<iostream>
using namespace std;
#include "linkedlist.h"
/*
1 2 3 4 5 -1
*/




/* merging two sorted linked lists*/
node*merge(node*head1,node*head2){
    if(!head1)return head2;
    if(!head2)return head1;
    node*final_head=NULL,*final_tail=NULL;
    
    while(head1 and head2){
        if(head1->data<=head2->data){
            if(final_head==NULL){
                final_head=head1;
                final_tail=head1;
                head1=head1->next;
            }else{
                final_tail->next=head1;
                head1=head1->next;
                final_tail=final_tail->next;
            }
        }
        else{
            if(final_head==NULL){
                final_head=head2;
                final_tail=head2;
                head2=head2->next;
            }else{
                final_tail->next=head2;
                head2=head2->next;
                final_tail=final_tail->next;
            }
        }
    }
    if(!head1){
        final_tail->next=head2;
    }
    if(!head2){
        final_tail->next=head1;
    }
    return final_head;
}
/*Middle node of linked list is*/
node* mid_element(node*head){
    if(!head || !head->next)return head;
    node*slow=head,*fast=head->next;
    while(fast and fast->next){
        fast=fast->next->next;
        slow =slow->next;
    }
    return slow;
}

/*Taking input from user in the linked list*/
node*takeInput(){
    int data;
    cin>>data;
    node*head=NULL,*tail=NULL;
    while(data!=-1){
        node*newnode=new node(data);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }else{
            tail->next=newnode;
            tail=tail->next;
        }
        cin>>data;
    }
    return head; 
}
/* Printing the whole linked list */
void print(node*head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}
/* Inserting node in the linked list at a specific index */
node* insert(int index,node*head,int element){
    node*newnode=new node(element);
    if(index==0){
        newnode->next=head;
        head=newnode;
        return head;
    }else{
        node*temp=head;
        while(temp and index-1>0){
            temp=temp->next;
            index--;
        }
        if(temp){
            newnode->next=temp->next;
            temp->next=newnode;
            return head;
        }else{
            return head;
        }
    }
    return head;
}
/* Deleting a node in linked list from a specific index */
node*deletenode(node*head,int index){
    if(index==0){
        if(!head)return head;
        node*a=head;
        head=head->next;
        delete a;
        return head;
    }
    else{
        int count=0;
        node*temp=head;
        while(temp && count<index-1){
            temp=temp->next;
            count++;
        }
        if(!temp){
            return head;
        }
        node*b=temp->next;
        if(temp->next){
            temp->next=temp->next->next;
        }
        delete b;
        return head;
    }
}
/* Inserting a node in linked list recursively */
node*insert_node_recursively(node*head,int index,int val){
    if(!head)return head;
    if(index==0){
        node*newnode=new node(val);
        newnode->next=head;
        head=newnode;
        return head;
    }
    node*sa=insert_node_recursively(head->next,index-1,val);
    head->next=sa;
    return head;

}
/* Deleting a node in the linked list at specific index recursively */
node*deleteNode_recursively(node*head,int index){
    if(head==NULL){
        return head;
    }
    if(index==0){
        node*a=head;
        head=head->next;
        delete a;
    }
    node*sa=deleteNode_recursively(head->next,index-1);
    head->next=sa;
    return head;
}

/*merge sort linked list*/
node*merge_sort(node*head){
    if(!head || !head->next)return head;
    node*mid=mid_element(head);
    // cout<<mid->data<<endl;
    node*b=mid->next;
    mid->next=NULL;
    node*h1=merge_sort(head);
    node*h2=merge_sort(b);
    node*finalhead=merge(h1,h2);
    return finalhead;
}

/*reverseLL*/
node*reverseLL(node*head){
    if(!head || !head->next){
        return head;
    }
    node*prev=NULL,*curr=head,*next=NULL;
    while(curr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

/* reverse linked list recursively*/
node*reverseLL_recursively(node*head){
    if(!head || !head->next)return head;
    node*sans=reverseLL(head->next);
    head->next->next=head;
    return sans;
}
/* Main function */
int main(){
    // creating a linked list
    node*head=takeInput();
    print(head);
    cout<<endl;
    // insert element at specific index
    head=insert(0,head,100);
    print(head);
    cout<<endl;
    // delete element from a specific index in linked list
    head=deletenode(head,0);
    print(head);
    cout<<endl;
    // delete element from a specific index in linked list recursively
    head=deleteNode_recursively(head,0);
    print(head);
    cout<<endl;    
    // insert element from a specific index in linked list recursively
    head=insert_node_recursively(head,3,500);
    print(head);
    cout<<endl;

    // insert element from a specific index in linked list recursively
    head=insert_node_recursively(head,0,1000);
    print(head);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;

    // finding mid node of the formed linked list
    // node*mid=mid_element(head);
    // // cout<<mid->data<<endl;
    // node*head2=mid->next;
    // mid->next=NULL;
    // mergin two sorted linked lists
    // print(head);
    // cout<<endl;
    // print(head2);
    // cout<<endl;
    // head=merge(head ,head2);
    // print(head);
    // cout<<endl;


    // merge sort on a linked list
    head = merge_sort(head);
    // cout<<head->data<<endl;
    print(head);
    cout<<endl;

    // Reverse a linked list
    // head = reverseLL(head);

    // Reverse a Linked list recursively
    // head = reverseLL_recursively(head);


    return 0;
}