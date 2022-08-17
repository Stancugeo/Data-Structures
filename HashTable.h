#include "SinglyLinkedList.hpp"
// Separate Chaining // 
class HashTable{
    public:
    LinkedList * Table ;
    int array_size;
    HashTable(int size);
    void AddinTable(int value);
    void DeleteinTable(int value);
    void PrintTable();
    int HashFunction(int value);
    bool IsEmpty(int index);
    const int SearchItem(int value);
    ~HashTable();
};
