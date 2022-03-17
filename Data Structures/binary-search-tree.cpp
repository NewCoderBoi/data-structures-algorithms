#include<iostream>
using namespace std;

// Recursive solutions not written.

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

Node* Recur_Insert(Node* root, int x){
    if(root == nullptr){
        root = CreateNode(x);
    }
    else if(x<=root->data){
        root->left = Recur_Insert(root->left, x);
    }
    else if(x>root->data){
        root->right = Recur_Insert(root->right, x);
    }
    return root;
}

bool Search(int x){
    bool isPresent = false;
    Node* temp = p_root;
    // cout<<temp->data<<' ';
    while(temp != nullptr){
        if(x == temp->data){
            isPresent = true;
            break;
        }
        else if(x < temp->data) temp = temp->left;
        else if(x > temp->data) temp = temp->right;
        // cout<<temp->data<<' ';
    }
    return isPresent;
}

Node* Iter_Min(){               // Empty tree condition not handled
    Node* temp = p_root;
    Node* minimum = temp;

    while(temp!=nullptr){
        minimum = temp;
        temp = temp->left;
    }
    return minimum;
}

Node* Iter_Max(){               // Empty tree condition not handled
    Node* temp = p_root;
    Node* maximum = temp;

    while(temp!=nullptr){
        maximum = temp;
        temp = temp->right;
    }
    return maximum;
}

int Height(Node* root){
    if(root==nullptr) return -1;
    return max(Height(root->left), Height(root->right))+1;
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
    cout<<Search(343)<<'\n';
    cout<<Iter_Min()->data<<'\n';
    cout<<Iter_Max()->data<<'\n';
    cout<<Height(p_root)<<'\n';
}