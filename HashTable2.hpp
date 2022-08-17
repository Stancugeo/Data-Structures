// Linear method //
class Node{
    public:
    int value;
    Node();
    Node(int value);
};
class HashTable{
    public:
    Node ** array;
    int array_size;
    int curr_num;
    HashTable(int size);
    HashTable(int size, int * arr);
    void AddinTable(int value);
    void DeleteinTable(int value);
    void PrintTable();
    int HashFunction(int value);
    bool IsEmpty(int index);
    Node * SearchItem(int value);
    ~HashTable();
  
};
