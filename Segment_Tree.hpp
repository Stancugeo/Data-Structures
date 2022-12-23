#define SEGMENT_TREE_HPP
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Segment_Tree{
public:
    vector<int>SumArray;
    vector<int>ValueArr;
    int height;
    int NumOfNodes;
    int NumOfLeaves;
    Segment_Tree(const vector<int>&Arr);
    int ConstructST(int left, int right , int node, const vector<int> & Arr);
    void updateValue(int pos , int value);
    void update(int left , int right , int index , int diff , int node);
    int getsum(int left,int right);
    int sum(int left,int right,int l , int r,int node);



};
