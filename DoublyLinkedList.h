#ifndef SINGLYLINKEDLIST_HPP
#define SINGLYLINKEDLIST_HPP
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
    int size;
    

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
    void ReverseList();
    void Reverse(Item * list,Item * & root);
    void DeleteAt(int position);
    void DeleteAtfunc(Item * & list , int & position);
    int Length();
    Item * GetNodeAt(int position);
    Item * GetNodeAtfrom_end(int position);
    Item * CountGivenNum(int value);
    bool DetectAloop();
    int FindTheLengthOfLoop();
    bool CheckPalindrome();
    void SortLinkedList();
    ~LinkedList();

};
#endif
