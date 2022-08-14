#include <iostream>
#include "SinglyLinkedList.h"
#include "HashTable1.cpp"


using namespace std;
HashTable :: HashTable(int size){
    this->Table = new LinkedList[size];
    this->array_size = size;
}
HashTable :: void AddinHash(int value){
    int index = HashFunction(value);
    Table[index].Add(value);
}
HashTable :: void DeleteinHash(int value){
    int index = HashFunction(value);
    Table[index].Remove(value);
}
HashTable :: void Print(){
    for(int i = 0 ; i < array_size; i ++){
        cout << i << ":";
        Table[i].Print();
        cout << endl;
    }
}
HashTable :: int HashFunction(int value){
    return value % array_size;
}

