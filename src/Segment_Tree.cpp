#include "Segment_Tree.hpp"
Segment_Tree :: Segment_Tree(const vector<int>&Arr){
    this->height = ceil(log2(Arr.size()));
    this->SumArray.resize(2 * pow(2,this->height) - 1);
    int size = Arr.size();
    ConstructST(0,size-1,0,Arr);
    this->ValueArr = Arr;
    this->NumOfNodes = this->SumArray.size();
    this->NumOfLeaves = this->ValueArr.size();
}
int Segment_Tree :: ConstructST(int left, int right , int node, const vector<int> & Arr){
    if(left == right){
        this->SumArray[node] = Arr[left];
        return Arr[left];
    }

    int mid = left + (right - left) / 2;
    this->SumArray[node] = ConstructST(left,mid,node*2+1,Arr) +
                           ConstructST(mid+1,right,node*2+2,Arr);
    return this->SumArray[node];


}
void Segment_Tree :: updateValue(int pos , int value){
    int diff = value - ValueArr[pos];
    this->ValueArr[pos] = value;
    update(0,SumArray.size()-1,pos,diff,0);


}
void Segment_Tree :: update(int left , int right , int index , int diff , int node){
    if(index < left || index > right) return;
    SumArray[node] += diff;
    if(left != right){
        int mid = left + (right - left)  / 2;
        update(left,mid,index,diff,2*node+1);
        update(mid+1,right,index,diff,2*node+2);
    }
}
int Segment_Tree :: getsum(int left,int right){
    return sum(0,SumArray.size()-1,left,right,0);
}
int Segment_Tree :: sum(int left,int right,int l , int r,int node){
    if(l >= left && right >= r) return SumArray[node];
    if(right < l || r < left) return 0;
    int mid = left + (right - left) / 2;
    return sum(left,mid,l,r,2*node+1) +
           sum(mid+1,right,l,r,2*node+2);
}
DycSegment_Tree :: DycSegment_Tree(int leftmost , int rightmost , vector<int>& Arr){
    this->leftmost = leftmost;
    this->rightmost = rightmost;
    if(leftmost == rightmost){ this->sum = Arr[leftmost]; }else{
        int mid = (leftmost + rightmost) / 2;
        this->lChild = new DycSegment_Tree(leftmost, mid, Arr);
        this->rChild = new DycSegment_Tree(mid + 1, rightmost, Arr);
        recalc();
    }
}
void DycSegment_Tree :: recalc(){
    if(this->leftmost == this->rightmost) return;
    this->sum = this->lChild->sum + this->rChild->sum;
}
void DycSegment_Tree :: pointUpdate(int index, int newVal){
    if(this->leftmost == this->rightmost){
        this->sum = newVal;
        return ;
    }
    if(index <= this->lChild->rightmost) this->lChild->pointUpdate(index,newVal);
    else this->rChild->pointUpdate(index,newVal);
    recalc();
}
int DycSegment_Tree :: rangeSum(int l , int r){
    if(l > this->rightmost || r < this->leftmost) return 0;
    if(l <= this->leftmost && r >= this->rightmost) return this->sum;
    return this->lChild->rangeSum(l,r) + this->rChild->rangeSum(l,r);

}
