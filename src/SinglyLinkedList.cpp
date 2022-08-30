#include "SinglyLinkedList.hpp"
#include <iostream>
using namespace std;

Item :: Item(){
    this->info = 0;
    this->next = NULL;
}
Item :: Item(int value){
    this->info = value;
    this->next = NULL;
}
LinkedList :: LinkedList(){
    this->size = 0;
    this->list = NULL;
}
bool LinkedList :: IsEmpty(){
    if(this->list!=NULL) return false;
    return true;
}
void LinkedList :: Add(int value){
    this->size ++ ;
    AddItem(list,value);
}
void LinkedList ::  AddItem(Item * & list , int & value){
    if(list==NULL) list = new Item(value);
    else AddItem(list->next,value);
    
}
void LinkedList :: Search(int value){
    if(SearchItem(list,value)!=NULL) cout << value;
    else cout << "Valoare nu exista";
}
Item * LinkedList :: SearchItem(Item * & list, int value){
    if(list == NULL) return list;
    if(list!=NULL && list->info == value) return list;
    return SearchItem(list->next,value);
}
void LinkedList :: Remove(int value){
    RemoveItem(list,value);
}
void LinkedList ::  RemoveItem(Item * & list, int value){
    if(list!=NULL){
        if(list->info == value){
            Item * tmp = list;
            list = list->next;
            delete tmp;
            this->size -- ;
            return ;
        }else RemoveItem(list->next,value);
    }
}
void LinkedList :: Print(){
    PrintItem(list);
}
void LinkedList :: PrintItem(Item * list){
    while(list!=NULL){
        cout << list->info << " ";
        list = list->next;
    }
}
Item * LinkedList :: GetNodeAt(int position){
    Item * tmp = this->list;
    while(position-- > 0){
        tmp = tmp->next;
    }
    return tmp;
}
void LinkedList :: ReverseList(){
    Item * root = new Item(0);
    Item * cpyroot = root;
    Reverse(list,root);
    this->list = cpyroot->next;
}
void LinkedList :: Reverse(Item * list,Item * & root){
    if(list->next!=NULL) Reverse(list->next,root);
    root->next = new Item(list->info);
    root = root->next;
}
void LinkedList ::DeleteAt(int position){
    if(position <= this->size){
        Item * prev = new Item(0);
        prev->next = list;
        DeleteAtfunc(prev,position);
        this->list = prev->next;
        this->size--;
    }
}
void LinkedList ::DeleteAtfunc(Item * & list , int & position){
    position--;
    if(list!=NULL && position > 0) DeleteAtfunc(list->next,position);
    else{
        Item * tmp = list->next;
        list->next = tmp->next;
        delete tmp;
    }
}
int LinkedList ::Length(){
    return this->size;
}
LinkedList :: ~LinkedList(){
    while(this->list!=NULL){
        Item * tmp = this->list;
        this->list = this->list->next;
        delete tmp;
    }
}
