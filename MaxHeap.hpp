#include <iostream>
using namespace std;

class MaxHeap{
    public:
    int capacity;
    int * array;
    MaxHeap(int capacity);
    MaxHeap(int capacity,int * array);
    const int parent(const int index);
    const int right_child(const int index);
    const int left_child(const int index);
    void sift_up(int index);
    void sift_down(int index);
    void insert(int value);
    void extractMax();
    void changePriority(int index , int value);
    int getMax();
    void remove(int index);
    void print();
    const int find(const int index , const int value);

    

};
