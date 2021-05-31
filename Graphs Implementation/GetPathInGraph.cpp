#include<bits/stdc++.h>
using namespace std;
// Get path function for graph
// make function
vector<int>*Get_Path(bool*visited,int sv,int ev,int v,int**edges ){
    // make a queue
    queue<int> q;
    unordered_map<int,int> map;
    // make a map
    q.push(sv);
    bool done = false;
    int curr;
    while(!q.empty()){
        curr=q.front();
        q.pop();
        for(int i=0;i<v;i++){
            if(edges[curr][i]==1 && !visited[i]){
                q.push(i);
                visited[i]=true;
                map[i]=curr;
            }
            if(i==ev){
                done = true;
                break;
            }
        }
    }
    if(!done){
        return NULL;
    }
    vector<int>*vc=new vector<int>();
    curr=ev;
    while(curr!=sv){
        vc->push_back(curr);
        curr=map[curr];
    }
    vc->push_back(sv);
    return vc;
}
int main(){
    //enter no of vertices and edges
    int v,e;
    cin>>v>>e;
    //enter the vertices between which you want to find the path
    int sv,ev;
    cin>>sv>>ev;
    //make loop to enter the edges from the user
    int **edges=new int*[v];
    for(int i=0;i<v;i++){
        edges[i]=new int[v];
        for(int j=0;j<v;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int v1,v2;
        cin>>v1>>v2;
        edges[v1][v2]=1;
        edges[v2][v1]=1;
    }

    //make a visited array and mark every element as not visited yet
    bool*visited=new bool[v];
    memset(visited,false,v);
    //call a function get path
    vector<int>*ans=Get_Path(visited,sv,ev,v,edges);
    if(!ans){
        return 0;
    }
    for(int i=0;i<ans->size();i++){
        cout<<"->"<<ans->at(i);
    }
    cout<<endl;
}
//sample input
/*
5 5
0 4
0 1
0 2
1 3
2 4
3 4

or

7 7 0 6 0 1 0 2 2 6 1 3 2 4 3 5 4 5
or
6 7 1 4 1 2 1 3 2 0 3 5 0 4 0 5 5 4
*/
