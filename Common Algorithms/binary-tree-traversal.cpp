#include<iostream>
#include<queue>
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

queue<Node*> temp;

// Level Order traversal or Breadth-first search traversal of a tree
// Logic - We store all the children of a node we are visiting in a queue, and pop them out of the queue when they are visisted. We have to use a queue because we have to first access the nodes that have been pushed first to the data structure. In other words, we need a FIFO data structure, which is queue. 

void LevelOrder(Node* root){
    if(!temp.empty()) temp.pop();
    if(root->left != nullptr) temp.push(root->left);
    if(root->right != nullptr) temp.push(root->right);
    cout<<root->data<<' ';
    if(temp.empty()) return;
    LevelOrder(temp.front());
}

void IterLevelOrder(){
    queue<Node*> iterTemp;
    if(!iterTemp.empty()) iterTemp.pop();
    Node* tempRoot = p_root;
    if(tempRoot->left != nullptr) iterTemp.push(tempRoot->left);
    if(tempRoot->right != nullptr) iterTemp.push(tempRoot->right);
    cout<<tempRoot->data<<' ';
    while(!iterTemp.empty()){
        tempRoot = iterTemp.front();
        iterTemp.pop();
        if(tempRoot->left != nullptr) iterTemp.push(tempRoot->left);
        if(tempRoot->right != nullptr) iterTemp.push(tempRoot->right);
        cout<<tempRoot->data<<' ';
    }
}

int main(){
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

    LevelOrder(p_root);
    cout<<'\n';
    IterLevelOrder();
}