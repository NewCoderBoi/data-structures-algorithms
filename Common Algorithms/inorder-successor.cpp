// Q: Find the inorder successor of the given element in a BST.
// Logic - We traverse till the given element. 
// Case 1 - If there is right subtree : Then we search the minimum element in it's right subtree, that will be the next element in the inorder traversal of the BST.
// Case 2 - If there is no right subtree : We have to find the deepest ancestor for which reqd node lies in left subtree.
// Time Complexity - O(log n)

#include<iostream>
using namespace std;

// Boilerplate start
struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* p_root = nullptr;

Node* CreateNode(int x){
    Node* newNode = new Node();
    newNode->data = x;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void Iter_Insert(int x){
    Node* newNode = CreateNode(x);
    if(p_root == nullptr){
        p_root = newNode;
    }
    else{
        Node* temp = p_root;
        Node* prev_temp = temp;
        
        while(temp!=nullptr){
            prev_temp = temp;
            if(x<=temp->data) temp = temp->left;
            else temp = temp->right;
        }
        if(x<=prev_temp->data){
            prev_temp->left = newNode;
        }
        else {
            prev_temp->right = newNode;
        }
    }
}

Node* InorderSuccessor(int data){
    Node* temp = p_root;
    Node* prev_temp = temp;
    while(temp!=nullptr){
        // Finding given element.
        if(temp->data < data){
            prev_temp = temp; 
            temp=temp->right;
        }
        else if(temp->data > data){
            prev_temp = temp; 
            temp = temp->left;
        }
        else break;
        
    }
    // Case 2. Node has no right subtree.
    if(temp->right == nullptr){
        Node* successor = nullptr;
        Node* ancestor = p_root;
        while(ancestor!= temp){
            if(temp->data < ancestor->data){
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else ancestor = ancestor->right; 
        }
        return successor;
    }
    // Case 1. Node has right subtree
    Node* successor = temp->right;
    temp = temp->right;
    while(temp!=nullptr){
        successor = temp;
        temp = temp->left;
    }
    return successor;
}

// Boilerplate end.

int main(){
    // Boilerplate start

    Iter_Insert(20);
    Iter_Insert(15);
    Iter_Insert(12);
    Iter_Insert(17);

    Iter_Insert(5);
    Iter_Insert(7);

    Iter_Insert(19);
    Iter_Insert(45);
    Iter_Insert(857);
    // Iter_Insert(0);
    Iter_Insert(33);
    Iter_Insert(5);
    Iter_Insert(131);
    Iter_Insert(5);
    Iter_Insert(66);
    Iter_Insert(149);
    Iter_Insert(169);

    // Boilerplate end
    cout<<InorderSuccessor(45)->data<<'\n';
    cout<<InorderSuccessor(66)->data<<'\n';
    cout<<InorderSuccessor(131)->data<<'\n';
    cout<<InorderSuccessor(149)->data<<'\n';
    cout<<InorderSuccessor(169)->data<<'\n';
    // cout<<InorderSuccessor(45)->data<<'\n';
}