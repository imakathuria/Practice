#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//print the graph using DFS
void print(bool **edges,int n,int startingVertex,bool *visited){
    cout<<startingVertex<<endl;
    visited[startingVertex]=true;
    for(int i=0;i<n;i++){
        if(i==startingVertex){
            continue;
        }
        if(edges[startingVertex][i]){
            if(visited[i]){
                continue;
            }
            print(edges,n,i,visited);
        }
    }
}
//Print Graph using BFS
void PrintBFS(bool**edges,int n,bool*visited,int startingVertex){
    queue<int> q;
    q.push(startingVertex);
    visited[startingVertex]=true;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        cout<<front<<" ";
        for(int i=0;i<n;i++){
            if(i==front){
                continue;
            }
            if(edges[front][i]){
                if(!visited[i]){
                    visited[i]=true;
                    q.push(i);
                }
            }
        }
        cout<<endl;
    }
}
//sample input
/*
6
7
1 2
1 3
2 0
2 4
0 5
4 5
3 4
*/
int main() {
    int n;
    cin>>n;//No of vertices
    int e;
    cin>>e;//No of edges
    bool **edges=new bool*[n];
    for(int i=0;i<n;i++){
        edges[i]=new bool[n];
        for(int j=0;j<n;j++){
            edges[i][j]=false;
        }
    }
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=true;
        edges[s][f]=true;
    }
    bool *visited=new bool[n];
    memset(visited,false, sizeof(visited));
    print(edges,n,1,visited);
    memset(visited,false, sizeof(visited));
    cout<<endl;
    PrintBFS(edges,n,visited,1);
    return 0;
}
