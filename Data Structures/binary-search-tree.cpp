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

// Delete a node in BST - First find element to be deleted. Then there are 3 cases -
// Case 1 - Delete a node with no children (Leaf node) - This is simple. We just remove the link and free the memory allocated to the node.
// Case 2 - Delete a node with 1 child - 
// Here we make the parent of the node to be deleted point to the child of the node to be deleted. This preserves the BST property for the resulting tree.
// Case 3 - Delete a node with 2 children -
// Approach 1 - Here, we first find the minimum element in the right subtree of the node to be deleted, then make the node to be deleted have data equal to this minimum element that we found. We then traverse the right subtree till we find this minimum element, then we delete that element.
// Approach 2 - Same as 1, but instead of min in right subtree, we use max of left subtree.

// The Delete() function should return address of root node, because root can change.

// Time Complexity - O(log n).
// Space Complexity - O(log n).

Node* FindMin(Node* root){
    // Logic - The left most element of a BST is the minimum element of the BST. So we have to return the left most element.
    if(root->left == nullptr) return root;
    else return FindMin(root->left);
}

Node* Delete(Node* root, int data){
    if(root == nullptr) return root;
    if(data < root->data) root->left = Delete(root->left, data);
    else if (data > root->data) root->right = Delete(root->right, data);
    else { // Found data, now delete it.
        // Case 1 - No children
        if(root->left == nullptr && root->right==nullptr){
            delete root;
            root = nullptr;
        }
        // Case 2 - One child.
        else if(root->left == nullptr){
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == nullptr){
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        // Case 3 -  2 children.
        else {
            Node* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
        
    }
    return root;
}

void Inorder(Node* root){
    if(root == nullptr) return;
    if(root->left != nullptr) Inorder(root->left);
    cout<<root->data<<' ';
    if(root->right != nullptr) Inorder(root->right);
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
    // cout<<Search(169)<<'\n';
    // cout<<Iter_Min()->data<<'\n';
    // cout<<Iter_Max()->data<<'\n';
    // cout<<Height(p_root)<<'\n';
    Inorder(p_root);
    cout<<'\n';
    Delete(p_root, 45);
    Inorder(p_root);

}