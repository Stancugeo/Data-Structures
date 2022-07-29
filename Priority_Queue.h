#include <iostream>
using std :: cout ;
class Priority_Queue{
    public:
    int capacity;
    int * array;
    Priority_Queue(int capacity){
        this->capacity = capacity;
        this->array = new int[capacity];
        for(int i = 0 ; i < capacity ; i ++ ){
            array[i] = 0 ;
        }
    }
    const int parent(const int index){
        if(index%2==0){ return index/2 - 1 ; }
        else return index/2;
    }
    const int right_child(const int index){
        return index * 2 + 1 ;
    }
    const int left_child(const int index){
        return index * 2 + 2 ;

    } 
    void shift_up(int index){
        while(index > 0 && array[parent(index)] < array[index]){
            swap(array[parent(index)],array[index]);
            index = parent(index);
        }
    }
    void shift_down(int index){
        int maxIndex = index ;
        int l = left_child(index);
        if(l <= this->capacity && array[l] > array[maxIndex]){
            maxIndex = l;
        }
        int r = right_child(index);
        if(r <= this->capacity && array[r] > array[maxIndex]){
            maxIndex = r ;
        }
        if(maxIndex!=index){
            swap(array[index],array[maxIndex]);
            shift_down(maxIndex);
        }
    }
    void insert(int value,int index){
        array[index] = value;
        shift_up(value);

    }
    int extractMax(){
        int result = array[0];
        array[0] = array[this->capacity];
        this->capacity = this->capacity - 1 ;
        shift_down(0);


    }
    void changePriority(int index , int value){
        int v = array[index];
        array[index] = value;
        if(v > value){
            shift_up(index);
        }else shift_down(index);


    }
    int getMax(){ 
        return array[0]; 
    }
    void remove(int index){
        array[index] = getMax() + 1;
        shift_up(index);
        extractMax();

    }
    void print(){
        for(int i = 0 ; i < this->capacity ; i ++ ){
            cout << array[i] << " ";
        }
    }

};