#include<iostream>
//Balanced BST use karein ge taki insert delete and getmin/getmax O(logN)me ho jae
#include<vector>
// #define push_back pq.push_back()
using namespace std;
class PriorityQueue{
    vector<int> pq;
public:
    PriorityQueue(){
    }
    bool isEmpty(){
        return pq.size()==0;
    }
    void insert(int data){
        pq.push_back(data);
        int childIndex=pq.size()-1;
        while(childIndex>0){
            int parentIndex=(childIndex-1)/2;
            if(pq[childIndex]<pq[parentIndex]){
                int p=parentIndex;
                swap(pq[childIndex],pq[parentIndex]);
                childIndex=p;
                parentIndex=(childIndex-1)/2;
            }else{
                break;
            }
        }
    }
    int removeMin(){
        if(pq.size()==0){
            return 0;
        }
        int ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        int parentIndex=0;
        int leftchildIndex=(2*parentIndex)+1;
        int rightchildIndex=(2*parentIndex)+2;
        while(leftchildIndex<pq.size()){
            // int minValue=pq[parentIndex];
            int minIndex=parentIndex;
            if(pq[parentIndex]>pq[leftchildIndex]){
                minIndex=leftchildIndex;
                // minValue=pq[leftchildIndex];
            }if(rightchildIndex<pq.size() && pq[rightchildIndex]< pq[minIndex]){
                // minValue=pq[rightchildIndex];
                minIndex=rightchildIndex;
            }
            if(minIndex==parentIndex){
                break;
            }
            swap(pq[parentIndex],pq[minIndex]);
            parentIndex=minIndex;
            leftchildIndex=(2*parentIndex)+1;
            rightchildIndex=(2*parentIndex)+2;

        }
        return ans;
    }
    int getsize(){
        return pq.size();
    }
    int getMin(){
        if(pq.size()!=0){
            return pq[0];
        }
        return 0;
    }

};
