#include <iostream>
#include "SinglyLinkedList.hpp"
using namespace std;
HashTable :: HashTable(int size){   
    this->Table = new LinkedList[size];
    this->array_size = size;
}
void HashTable ::  AddinTable(int value){
    int index = HashFunction(value);
    Table[index].Add(value);
}
void HashTable ::  DeleteinTable(int value){
     int index = HashFunction(value);
     Table[index].Remove(value);
}
void HashTable :: PrintTable(){
     for(int i = 0 ; i < array_size; i ++){
        cout << i << ":";
        Table[i].Print();
        cout << endl;
    }
}
int HashTable :: HashFunction(int value){
    return value % array_size;
}
bool HashTable ::  IsEmpty(int index){
    return (Table[index].IsEmpty());
}
HashTable :: const int SearchItem(int value){
    if(Table[HashFunction(value)].Search(value)!=NULL) return value;
    return -1;
}
~HashTable(){
    delete[] Table;
    Table = NULL;
}
