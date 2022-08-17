
#include "HashTable2.hpp"
#include <iostream>
using namespace std;

Node :: Node(){}
Node :: Node(int value){
    this->value = value;
}
HashTable :: HashTable(int size){
    this->array = new Node*[size];
    for(int i = 0 ; i < size ; i ++){
        this->array[i] = NULL;
    }
    this->array_size = size;
    this->curr_num = 0;
}
HashTable :: HashTable(int size, int * arr){
    this->array = new Node*[size];
    this->array_size = size ;
    for(int i = 0 ; i < size ; i ++){
        AddinTable(arr[i]);
    }
}
void HashTable :: AddinTable(int value){
    if(this->curr_num < this->array_size){
        int index = HashFunction(value);
        Node * tmp = new Node(value); 
        while(this->array[index]!=NULL){
            index = (index + 1) % this->array_size;
        }
        this->array[index] = tmp;
        this->curr_num++;
    }else{
        throw overflow_error("Vectorul e plin :(");
    }
}
void HashTable :: DeleteinTable(int value){
    if(this->curr_num > 0){
        int index = HashFunction(value);
        int counter = 0;
        while(this->array[index]!=NULL && this->array[index]->value!=value){
            index = (index+1) % this->array_size;
            if(counter++>=array_size) return ;
        }
        this->array[index] = NULL;
        this->curr_num--;
    }
}
    
void HashTable :: PrintTable(){
    for(int i = 0 ; i < this->array_size;  i++){
        if(array[i]!=NULL) cout << i << " " << array[i]->value << endl;
        else cout << "~" << endl;
    }
}
int HashTable :: HashFunction(int value){
    return value % array_size; 
}
bool HashTable :: IsEmpty(int index){
    if(this->curr_num > 0) return false;
    return true;
}
Node * HashTable :: SearchItem(int value){
     if(this->curr_num > 0){
        int index = HashFunction(value);
        int counter = 0;
        while(this->array[index]!=NULL && this->array[index]->value!=value){
            index = (index+1) % this->array_size;
            if(counter++>=array_size) return NULL;
        }
        return this->array[index];
     }
     return NULL;
}
HashTable :: ~HashTable(){
  delete[] this->array;
};
