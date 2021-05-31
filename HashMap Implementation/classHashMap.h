using namespace std;
template<typename V>
class mapNode{
public:
    string key;
    V value;
    mapNode<V>*next;
    //constructor
    mapNode(string key,V value){
        this->key=key;
        this->value=value;
        next=NULL;
    }
    //destructor to delete Nodes recursively
    ~mapNode(){
        delete next;
    }
};
template<typename V>
class hashMap{
public:
    mapNode<V>**bucket;//bucket array
    int count;
    int BucketSize;
    //constructor
    hashMap(){
        bucket=new mapNode<V>*[1];
        count=0;
        BucketSize=1;
        for(int i=0;i<BucketSize;i++){
            bucket[i]=NULL;
        }
    }
    //destructor
    ~hashMap(){
        //delete the bucket array
        for(int i=0;i<BucketSize;i++){
            delete[]bucket[i];
        }
        delete []bucket;
    }
private:
    getBucketIndex(string key){
        int currentCofficient=1;
        int hashCode=0;
        //doing % bucket size to prevent it from going out of range of integers
        for(int i=key.length()-1;i>=0;i--){
            hashCode+=key[i]*currentCofficient;
            hashCode=hashCode%BucketSize;
            currentCofficient*=37;
            currentCofficient%BucketSize;
        }
        return hashCode%BucketSize;
    }
public:
    double getLoadFactor(){
        return (1.0 * count)/BucketSize;
    }
private:
    void Rehash(){
        count=0;
        mapNode<V>**temp=bucket;
        bucket=new mapNode<V>*[2*BucketSize];
        for(int i=0;i<2*BucketSize;i++){
            bucket[i]=NULL;
        }
        int OldBucketSize=BucketSize;
        BucketSize*=2;
        for(int i=0;i<OldBucketSize;i++){
            mapNode<V>*head=temp[i];
            while(head!=NULL){
                string k=head->key;
                V val=head->value;
                insertKeyValue(k,val);
                head=head->next;
            }
        }
        for (int i = 0; i < OldBucketSize; i++) {
            /* code */
            mapNode<V>*head=temp[i];
            delete head;
        }
        delete []temp;
    }
public:
    //getting value corresponding to a key
    V getValue(string key){
        int BucketIndex=getBucketIndex(key);
        mapNode<V>*head=bucket[BucketIndex];
        while(head!=NULL){
            if(head->key==key){
                return head->value;
            }
            head=head->next;
        }
        return 0;
    }
    //delete a key from map
    V deleteKey(string key){
        int BucketIndex=getBucketIndex(key);
        mapNode<V>*prev=NULL;
        mapNode<V>*head=bucket[BucketIndex];
        while(head!=NULL){
            if(head->key==key){
                if(prev==NULL){
                    bucket[BucketIndex]=head->next;
                }else{
                    prev->next=head->next;
                }
                V value=head->value;
                head->next=NULL;
                delete head;
                count--;
                return value;
            }
            head=head->next;
        }
        return 0;
    }
    //Insert key in table with its value
    void insertKeyValue(std::string key,V value){
        int BucketIndex=getBucketIndex(key);
        mapNode<V>*head=bucket[BucketIndex];
        while(head!=NULL){
            if(head->key==key){
                head->value=value;
                return ;
            }
            head=head->next;
        }
        count++;
        mapNode<V>*newhead=new mapNode<V>(key,value);
        newhead->next=bucket[BucketIndex];
        bucket[BucketIndex]=newhead;
        if(getLoadFactor()>0.7){
            Rehash();
        }
    }
    //returning size of the map i.e. total number of elements in the map
    int getSize(){
        return count;
    }
};
