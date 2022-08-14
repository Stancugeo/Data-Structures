#include "SinglyLinkedList.h"
class HashTable{
    public:
    LinkedList * Table ;
    int array_size;
    HashTable(int size);
    void AddinHash(int value);
    void DeleteinHash(int value);
    void Print();
    int HashFunction(int value);
};
