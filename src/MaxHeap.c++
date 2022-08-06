#include "MaxHeap.h"
#include <iostream>
using namespace std;


MaxHeap :: MaxHeap(int capacity){
    this->capacity = capacity;
    this->array = new int[capacity];
    for(int i = 0 ; i < capacity ; i ++ ){
        array[i] = 0 ;
    }
}
MaxHeap :: MaxHeap(int capacity,int * array){
    this->capacity = capacity;
    this->array = array;
    for(int i = capacity/2-1 ; i >= 0 ; i --){
        sift_down(i);
    }
    
}
const int MaxHeap :: parent(const int index){
    if(index%2==0){ return index/2 - 1 ; }
    else return index/2;
}
const int MaxHeap :: right_child(const int index){
    return index * 2 + 1 ;
}     
const int MaxHeap :: left_child(const int index){
    return index * 2 + 2 ;
}
void MaxHeap :: print(){
    for(int i = 0 ; i < this->capacity ; i ++ ){
            cout << array[i] << " ";
    }
}

void MaxHeap :: remove(int index){
    array[index] = getMax() + 1;
    sift_up(index);
    extractMax();
}
int MaxHeap :: getMax(){
    return array[0];
}
void MaxHeap :: extractMax(){
        int result = array[0];
        array[0] = array[this->capacity-1];
        this->capacity = this->capacity - 1 ;
        sift_down(0);
}  
void MaxHeap :: changePriority(int index , int value){
    int v = array[index];
    array[index] = value;
    if(v < value){
        sift_up(index);
    }else sift_down(index);

}
const int MaxHeap :: find(const int index , const int value){
        if(index >= this->capacity) return -1;
        if(value > this->array[index]) return -1;
        if(this->array[index] == value) return index;
        return max(find(right_child(index),value),find(left_child(index),value));
  
        
}
  
void MaxHeap :: insert(int value,int index){
        array[index] = value;
        sift_up(value);
}
void MaxHeap :: sift_down(int index){
        int maxIndex = index ;
        int l = left_child(index);
        if(l < this->capacity && array[l] > array[maxIndex]){
            maxIndex = l;
        }
        int r = right_child(index);
        if(r < this->capacity && array[r] > array[maxIndex]){
            maxIndex = r ;
        }
        if(maxIndex!=index){
            swap(array[index],array[maxIndex]);
            sift_down(maxIndex);
        }
}
void MaxHeap :: sift_up(int index){
    while(index > 0 && array[parent(index)] < array[index]){
        swap(array[parent(index)],array[index]);
        index = parent(index);
    }
}


