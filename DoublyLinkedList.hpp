#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP
class Node{
    public:
    int info;
    Node* prev;
    Node* next;
    Node(int info);
    Node(int info,Node* prev , Node* next);
};
class DoublyLinkedList{
    public:
    Node * head;
    Node * tail;
    int size;
    DoublyLinkedList();
    bool IsEmpty();
    void addFirst(int element);
    void addLast(int element);
    void PrintList();
    void PrintReverseList();
    void DeleteFirst();
    void DeleteLast();
    Node* getFront();
    Node* getBack();
    int getSizeOfList();
    void DeleteNode(int key,int position);
    void ReverseList();
    void InsertNodeAt(int key,int position);
    ~DoublyLinkedList();
    
};
#endif
