#include <iostream>
using namespace std;
struct Node{
    int value;
    Node * right;
    Node * left;
    Node(int key);
    Node();

};
class BinaryTree{
    public:
    Node * root;
    BinaryTree();
    void Insert(int num, Node * leaf);
    void Insertkey(int value);
    Node * search(int key);
    Node * search(int key, Node * leaf);
    void inorder_print(Node * leaf);
    void inorder_print();
    void preorder_print();
    void preorder_print(Node * leaf);
    void postorder_print(Node * leaf);
    void postorder_print();
    ~BinaryTree();
    void deleteNode(Node * leaf);
    void Remove(int key);
    Node * RemoveLeaf(int key, Node * & leaf);
    Node* FindMin(Node* leaf);
    Node* FindMax(Node * leaf);
    int height(Node* leaf);
    int levelofnode(int key);
    int lofn(int key , Node * leaf, int level);
};
