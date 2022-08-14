class Item{
    public:
    int info;
    Item * next;
    Item();
    Item(int value);

};
class LinkedList{
    public:
    Item * list ;
    LinkedList();
    bool IsEmpty();
    void Add(int value);
    void AddItem(Item * & list , int & value);
    void Search(int value);
    Item * SearchItem(Item * & list, int value);
    void Remove(int value);
    void RemoveItem(Item * & list, int value);
    void Print();
    void PrintItem(Item * list);
};
