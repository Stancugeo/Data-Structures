#include<iostream>
#include "BST.hpp"
using namespace std;
Node :: Node(int key){
    this->right = NULL;
    this->left = NULL;
    this->value = key;
}
Node :: Node(){
    this->right = NULL;
    this->left = NULL;
    this->value = 0;
}
BinaryTree :: BinaryTree(){
    this->root = NULL;
}
void BinaryTree :: Insert(int num, Node * leaf){
    if(leaf->value > num){
        if(leaf->left!=NULL){
            Insert(num,leaf->left);
        }else{
            leaf->left = new Node(num);
        }
        
    }else if(leaf->value <= num){
        if(leaf->right!=NULL){
            Insert(num,leaf->right);
        }else{
            leaf->right = new Node(num);
        }
    }
    
}
void BinaryTree :: Insertkey(int value){
    Node *Leaf = new Node(value);
    if(root == NULL){    
        this->root = Leaf; 
    }else{
        Insert(value,root);
    }
}
Node * BinaryTree :: search(int key){
    return search(key,this->root);
}
Node * BinaryTree :: search(int key, Node * leaf){
    if(leaf!=NULL){
        if(key == leaf->value){ return leaf; }else
        {
            if (key < leaf->value){
                search(key,leaf->left);
            }else if(key >= leaf->value){
                search(key,leaf->right); 
            }
        }
    }else{ return NULL; }
}
void BinaryTree :: inorder_print(Node * leaf){
    if(leaf!=NULL){
        inorder_print(leaf->left);
        cout << leaf->value << " ";
        inorder_print(leaf->right);
    }
}
void BinaryTree :: inorder_print(){
    inorder_print(root);
    cout << endl;
}
void BinaryTree :: preorder_print(){
    preorder_print(root);
    cout << endl;
}
void BinaryTree :: preorder_print(Node * leaf){
    if(leaf!=NULL){
        cout << leaf->value << " ";
        preorder_print(leaf->right);
        preorder_print(leaf->left);
    }
}
void BinaryTree :: postorder_print(Node * leaf){
    if(leaf!=NULL){
        postorder_print(leaf->left);
        postorder_print(leaf->right);
        cout << leaf->value << " ";
    }
}
void BinaryTree :: postorder_print(){
    postorder_print(root);
    cout << endl;
}
BinaryTree :: ~BinaryTree(){
    deleteNode(root);
}
void BinaryTree :: deleteNode(Node * leaf){
    if(leaf!=NULL){
        deleteNode(leaf->left);
        deleteNode(leaf->right);
        delete leaf;
    }
}
void BinaryTree :: Remove(int key){
    RemoveLeaf(key,root);
}
Node * BinaryTree :: RemoveLeaf(int key, Node * & leaf){
    if(leaf == NULL) return leaf;
    else if(key < leaf->value) return RemoveLeaf(key,leaf->left);
    else if(key > leaf->value) return RemoveLeaf(key,leaf->right);
    else{
        if(leaf->left == NULL && leaf->right == NULL){
            delete leaf;
            leaf = NULL;
            
            
        }else if(leaf->left == NULL){
            Node * temp = leaf;
            leaf = leaf -> right;
            delete temp;
        }else if(leaf->right == NULL){
            Node * temp = leaf ;
            leaf = leaf -> left;
            delete temp;
        }else{
            Node * temp = FindMin(leaf->right);
            leaf->value = temp->value;
            leaf->right = RemoveLeaf(temp->value,leaf->right);
        }
        return leaf;
    }
   
}
Node* BinaryTree :: FindMin(Node* leaf){
    while(leaf->left!=NULL){
        leaf = leaf->left;
    }
    return leaf;
}
Node* BinaryTree :: FindMax(Node * leaf){
    while(leaf->right!=NULL){
        leaf = leaf->right;
    }
    return leaf;
}
int BinaryTree :: height(Node* leaf) {
    if (leaf == NULL) 
        return 0;
    else{
        int left_height = height(leaf->left);
        int right_height = height(leaf->right);
        return max(left_height, right_height) + 1;
    }
}
int BinaryTree :: levelofnode(int key){
    return lofn(key,this->root,0);
}
int BinaryTree :: lofn(int key , Node * leaf, int level){
    if(leaf==NULL) return -1;
    else if(leaf->value == key) return level;
    int l = lofn(key,leaf->left,level+1);
    if(l!=-1) return l;
    return lofn(key,leaf->right,level+1);
}

