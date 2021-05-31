#include "TrieNode.h"
#include<string>
class trieclass{
    trieNode*root;
public:
    trieclass(){
        root=new trieNode('\0');
    }
    void insert1(string word,trieNode*root){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        int index=word[0]-'a';
        trieNode*child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }else{
            child=new trieNode(word[0]);
            root->children[index]=child;
        }
        insert1(word.substr(1),child);
    }
    void insert(string word){
        insert1(word,root);
    }

    void remove1(string word,trieNode*root){
        if(word.size()==0){
            root->isTerminal=false;
            return;
        }
        int index=word[0]-'a';
        trieNode*child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return ;
        }
        remove1(word.substr(1),child);
        if(child->isTerminal==false){
            for(int i=0;i<26;i++){
                if(child->children[i]!=NULL){
                    return;
                }
            }
            delete child;
            root->children[index]=NULL;
        }
    }
    void remove(string word){
        remove1(word,root);
    }
    bool search1(string word,trieNode*root){
        if(word.length()==0){
            return root->isTerminal;
        }
        int index=word[0]-'a';
        trieNode*child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }else{
            return false;
        }
        return search1(word.substr(1),child);
    }
    bool search(string word){
        return search1(word,root);
    }
};
