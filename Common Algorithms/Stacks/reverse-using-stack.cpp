/*
    # We will reverse two things -
    # 1. String.
    # 2. Linked List.

    # Note - This is the only problem where I will implement stack. Other problems will use STL Stack.
*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Stack {
private:
    char stack[101];
    int top = -1;

public:
    void Push(char);
    void Pop();
    char Top();
    bool isEmpty();
};

void Stack::Push(char ui){ //ui stands for user input.
    if(top == 100){
        cout<<"Stack is full"<<'\n';
        return;
    }
    top++;
    stack[top] = ui;
}

void Stack::Pop(){
    if(top == -1){
        cout<<"Stack is empty"<<'\n';
        return;
    }
    top--;
}

char Stack::Top(){
    if(top == -1){
        cout<<"Stack is empty"<<'\n';
    }
    else return stack[top];
}

bool Stack::isEmpty(){
    return top==-1;
}

// Linked List implementation.
class Node {
public:
    int data;
    Node* next;

    void Display();
    Node* traversal();
    Node* createNode(int);
    void insertAtEnd(Node*);
};

Node* head = nullptr;

void Node::Display(){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<' ';
        temp = temp->next;
    }
}

Node* Node::traversal()
{
    // 2a. Traversing to the end

    // Logic - Initially, we declare a pointer to point at head, then we make that pointer point to the next element of the list.
    // When this pointer reaches the last element, it's next field will have nullptr, so we break the loop then.

    Node* traversal = head;
    while(traversal->next != nullptr){
        traversal = traversal->next;
    }
    return traversal;
}

Node* Node::createNode(int value)
{
    // 1. Creating a node in memory - First element of Linked List.
    Node* temp = new Node(); //temp is a pointer
    temp -> data = value;
    temp -> next = nullptr;
    return temp;
}

void Node::insertAtEnd(Node* temp)
{
    Node* last = traversal();
    last->next = temp;
}

void LLReverse(){
    // Logic - We push all nodes of LL in stack in first loop. Before next loop starts, we set a temp variable as top of stack, head as the temp variable and then pop the stack once. Then we loop till stack is empty. For every iteration, we set temp's next element to be the top of stack, then pop stack, then make temp point to temp's next.

    // Eg. LL - 2 7 5 3 10
    // Before 2nd loop - temp = 10, head = 10, stack.top = 3;
    // First iter - 
    // temp -> next = stack.top => temp->next = 3;
    // stack.pop() => stack.top = 5;
    // temp = temp->next => temp = 3;

    // When this loop finishes, temp will be pointing to first element of unreversed LL. We make next of temp point to null.

    stack<Node*> stack;
    Node* temp = head;
    while(temp!=nullptr){
        stack.push(temp);
        temp = temp->next;
    }
    temp = stack.top();
    head = temp;
    stack.pop();
    while(!stack.empty()){
        temp->next = stack.top();
        stack.pop();
        temp = temp->next;
    }
    temp->next = nullptr;
    return;
}

// String reversal using stack.

// Time complexity - O(n)
// Space complexity - O(n)
void StringReverse(string s){
    // Logic - We will push each character of string in stack, then place the top character at first index and pop the first character, and continue the process till stack is empty.

    Stack stack;
    for(int i=0;i<s.length();i++){
        stack.Push(s[i]);
    }

    for(int i=0;i<s.length();i++){
        s[i] = stack.Top();
        stack.Pop();
    }
    cout<<s<<'\n';
}

int main(){
    // string s;
    // cout<<"Enter a string"<<'\n';
    // getline(cin, s);

    // StringReverse(s);
    Node node;
    Node* temp = node.createNode(2);

    // Now, head should point to the temp node that has been created. That is what we do next.
    head = temp;

    // 2. Inserting elements at the end.

    temp = node.createNode(3);
    node.insertAtEnd(temp);

    temp = node.createNode(4);
    node.insertAtEnd(temp);

    temp = node.createNode(5);
    node.insertAtEnd(temp);

    node.Display();
    LLReverse();
    node.Display();
}
