#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include"TrieClass.h"
int main(){
    trieclass obj;
    obj.insert("akhil");
    obj.insert("kathuria");
    obj.insert("sidharth");
    obj.insert("monika");
    obj.insert("bharat");
    obj.insert("akkhi");
    obj.insert("sidhu");
    obj.remove("akhil");
    cout<<"Searching akhil after deleteing "<<obj.search("akhil")<<endl;
    cout<<"Searching from the dictionary "<<obj.search("kathuria")<<endl;
    cout<<"Searching from the dictionary "<<obj.search("sidharth")<<endl;
    cout<<"Searching from the dictionary "<<obj.search("monika")<<endl;
    cout<<"Searching from the dictionary "<<obj.search("bharat")<<endl;
    cout<<"Searching from the dictionary "<<obj.search("akkhi")<<endl;
    cout<<"Searching from the dictionary "<<obj.search("sidhu")<<endl;


}
