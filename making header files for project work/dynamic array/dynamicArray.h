#include<iostream>
template<typename T>
class DynamicArray{
    T * data;
    int nextIndex;
    int capacity;
    public:
        DynamicArray(){
            data = new T[5];
            capacity = 5;
            nextIndex = 0;
        }   
        DynamicArray(DynamicArray const &obj){
            T*narr=new T[obj.capacity];
            for(int i=0;i<obj.nextIndex;i++){
                narr[i]=obj.data[i];
            }
            this->data=narr;
            this->capacity=obj.capacity;
            this->nextIndex=obj.nextIndex;
        }
        void operator=(DynamicArray const &obj){
            T*narr=new T[obj.capacity];
            for(int i=0;i<obj.nextIndex;i++){
                narr[i]=obj.data[i];
            }
            this->data=narr;
            this->capacity=obj.capacity;
            this->nextIndex=obj.nextIndex;
        }
        void push(int element){
            if(nextIndex==capacity){
                T * newArray=new T[2*capacity];
                for(int i=0;i<capacity;i++){
                    newArray[i]=data[i];
                }
                delete []data;
                data = newArray;
                capacity*=2;
                
            }
            data[nextIndex]=element;
            nextIndex++;
        }
        T get(int index) const{
            if(index>=nextIndex){
                cout<<"Index out of capacity"<<endl;
                return 0;
            }
            else{
                return data[index];
            }
        }
        void add(int index,T element){
            if(index<nextIndex){
                data[index]=element;
            }
            else if(index==nextIndex){
                push(element);
                // data[nextIndex]=element;
                // nextIndex++;
            }else{
                cout<<"Index is out of capacity"<<endl;
            }
        }
        void print() const{
            if(nextIndex==0)return;
            for(int i=0;i<nextIndex;i++){
                cout<<data[i]<<" ";
            }
            cout<<endl;
        }

};