#include<iostream>
using namespace std;
#include"classHashMap.h"
int main(){
    hashMap<int> map;
    string str="Akhil";
    for(int i=0;i<10;i++){
        char c='0'+i;
        string key=str+c;
        cout<<"Load on map"<< map.getLoadFactor()<<endl;
        map.insertKeyValue(key,i+1);
    }
    cout<<"size: "<<map.getSize()<<endl;
    str="Akhil";
    for(int i=0;i<map.getSize();i++){
        char c='0'+i;
        string key=str+c;
        cout<<key<<" : "<<map.getValue(key)<<endl;
    }
    int i=map.deleteKey("Akhil1");
    int j=map.deleteKey("Akhil2");
    cout<<"size: "<<map.getSize()<<endl;
    for(int i=0;i<map.getSize();i++){
        char c='0'+i;
        string key=str+c;
        cout<<key<<" : "<<map.getValue(key)<<endl;
    }
}
