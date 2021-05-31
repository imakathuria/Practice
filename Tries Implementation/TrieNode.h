class trieNode{
public:
    char data;
    trieNode**children;
    bool isTerminal;
    trieNode(char a){
        this->data=a;
        children=new trieNode*[26];
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};
