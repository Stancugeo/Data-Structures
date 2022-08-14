#include <iostream>
#include "SinglyLinkedList.h"
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
    this->list = NULL;
}
bool LinkedList :: IsEmpty(){
    if(this->list!=NULL) return false;
    return true;
}
void LinkedList :: Add(int value){
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