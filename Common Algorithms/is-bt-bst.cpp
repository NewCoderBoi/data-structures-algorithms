// Q: Check whether a binary tree is binary search tree.

// Logic - In BST, all elements to left of root is less than root, all elements to right of root is greater than root. Also, every subtree of a BST has to be a BST. So, if we traverse all elements in left, then the root, and then all elements in right, we should get a list sorted in ascending order. This traversal is known as Inorder traversal. So, inorder traversal of a BST is a sorted list in ascending order. 
// If the inorder traversal of the given tree is not sorted, then tree is not BST, else BST.

#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* p_root = nullptr;


// Added for logistic reasons
Node* CreateNode(int x){
    Node* newNode = new Node();
    newNode->data = x;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Added for logistic reasons.
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

vector<int> temp;

void Inorder(Node* root){
    if(root == nullptr) return;
    if(root->left != nullptr) Inorder(root->left);
    temp.push_back(root->data);
    if(root->right != nullptr) Inorder(root->right);
}

int main(){
    // Iter_Insert(20);
    // Iter_Insert(15);
    // Iter_Insert(12);
    // Iter_Insert(17);

    // Iter_Insert(5);
    // Iter_Insert(7);

    // Iter_Insert(19);
    // Iter_Insert(45);
    // Iter_Insert(857);
    // // Iter_Insert(0);
    // Iter_Insert(33);
    // Iter_Insert(5);
    // Iter_Insert(131);
    // Iter_Insert(5);
    // Iter_Insert(66);
    // Iter_Insert(149);
    // Iter_Insert(169);

    Inorder(p_root);
    cout<<temp.size()<<'\n';
    bool isBST = true;
    for(int i=1;i<temp.size();i++){
        if(temp[i]<temp[i-1]){
            isBST = false;
            break;
        }
    }
    if(isBST) cout<<"Is BST"<<'\n';
    else cout<<"Not BST"<<'\n';
}