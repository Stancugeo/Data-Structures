#include <iostream>
#include "DoublyLinkedList.hpp"
using namespace std;
Node::Node(int info){
    this->prev = NULL;
    this->next = NULL;
    this->info = info;
}
Node::Node(int info,Node* prev , Node* next){
    this->prev = prev;
    this->next = next;
    this->info = info;
}
DoublyLinkedList::DoublyLinkedList(){
    head = NULL;
    tail = NULL;
    this->size = 0;
}
bool DoublyLinkedList :: IsEmpty(){
    if(this->size <= 0) return true;
    return false;
}
void DoublyLinkedList :: addFirst(int element){
    Node* tmp = new Node(element);
    if(this->head!=NULL){ 
        this->head->prev = tmp;
        tmp->next = head;
    }
    this->head = tmp;
    if(tail == NULL) tail = head;
    this->size++;
}
void DoublyLinkedList :: addLast(int element){
    Node* tmp = new Node(element);
    if(this->tail!=NULL){
        this->tail->next = tmp;
        tmp->prev = tail;
    }
    tail = tmp;
    if(head == NULL) head = tail;
    this->size ++ ;
}
void DoublyLinkedList :: PrintList(){
    Node* tmp = head;
    while(tmp!=NULL){
        cout << tmp->info << " ";
        tmp = tmp->next;
    }
}
void DoublyLinkedList :: PrintReverseList(){
    Node* tmp = tail;
    while(tail!=NULL){
        cout << tail->info << " ";
        tail = tail->prev;
    }
}
void DoublyLinkedList :: DeleteFirst(){
    if(IsEmpty()) throw -1;
    Node* tmp = head;
    head = head->next;
    head->prev = NULL;
    delete tmp;
    this->size--;
}
void DoublyLinkedList :: DeleteLast(){
    if(IsEmpty()) throw -1;
    Node * tmp = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete tmp;
    this->size--;
}
Node* DoublyLinkedList :: getFront(){
    return head;
}
Node* DoublyLinkedList :: getBack(){
    return tail;    
}
int DoublyLinkedList :: getSizeOfList(){
    return this->size;
}
void DoublyLinkedList :: DeleteNode(int key,int position){
    Node*tmp = head;
    if(position < 1 || position > this->size) throw -1;
    if(IsEmpty()) throw -1;
    int cnt = 1;
    while(tmp!=NULL && cnt < position){
        tmp = tmp->next;
        cnt++;
    }
    if(tmp!=NULL && tmp->info == key){
        if(tmp->next!=NULL && tmp->prev!=NULL){
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            delete tmp;
            this->size--;
        }else if(tmp->next == NULL){
            DeleteLast();
        }else if(tmp->prev == NULL){
            DeleteFirst();
        }
    }
    
}
void DoublyLinkedList :: ReverseList(){
    if(!IsEmpty()){
        int middle = this->size/2;
        Node* headcpy = head;
        Node* tailcpy = tail;
        for(int i = 1 ; i <= middle; i++){
            swap(headcpy->info,tailcpy->info);
            headcpy = headcpy->next;
            tailcpy = tailcpy->prev;
        }
    }
}

void DoublyLinkedList :: InsertNodeAt(int key,int position){
    
    if(position < 1 || position > this->size) throw -1;
    if(position == 1){ 
        addFirst(key);
        return;
    }
    if(position == this->size){
        addLast(key);
        return;
    } 
    
    Node*tmp = head;
    int cnt = 1;
    while(tmp!=NULL && cnt < position){
        tmp = tmp->next;
        cnt++;
    }
    Node * NewNode = new Node(key);
    NewNode->next = tmp;
    NewNode->prev = tmp->prev;
    tmp->prev = NewNode;
    tmp->prev->prev->next = NewNode;
    this->size ++;
    
    
}
