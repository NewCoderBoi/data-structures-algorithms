#include<iostream>
using namespace std;

//Array based implementation

// We are declaring the max size of the array which will be the stack using a macro.

#define MAX_SIZE 3 //Macro
int array_stack[MAX_SIZE]; //stack of integers.

int top = -1; // When top is -1, it means the stack is empty.

void ArrayPush(int x){
    // Logic - We increment top by 1, then put the value sent by user to the top index.
    // When array is full, we send an error.

    if(top == MAX_SIZE - 1) { //Full condition
        cout<<"Stack is full"<<'\n';
        return;
    }
    top++;
    array_stack[top] = x;
}

void ArrayPop(){
    //Logic - We just decrement top by 1.
    //If stack is empty, we throw error.

    if(top == -1){ //Empty condition
    cout<<"Stack is empty"<<'\n';
    return;
    }
    top--;
}

void ArrayTop(){
    // Logic - Prints the element pointed by top
    cout<<array_stack[top]<<'\n'; 
}

void ArrayPrint(){ //Only for testing purposes, normally not present in stack implementation
    for(int i=0;i<=top;i++){
        cout<<array_stack[i]<<' ';
    }
    cout<<'\n';
}


// Linked List Based Implementation.

// Note - The list will be filled in reverse, because if it was filled in forward direction, insertion and deletion both have to be done at tail end, which would take O(N) time. But acc to definition of stack, Push and Pop operations should be O(1). Insertion and deletion at beginning or the head takes O(1) time in Linked List.

struct Node {
    int data;
    Node* next;
};

Node* LLStack = nullptr; // This is the head pointer. LLStack = null means stack is empty.

void LLPush(int x){
    // Logic - Same as How to insert at beginning of LL.
    Node* newNode = new Node();
    newNode -> data = x;
    newNode -> next = LLStack;
    LLStack = newNode;
}

void LLPop(){
    // Logic - Same as How to delete from beginning of LL, and adding a stack empty error condition.
    if(LLStack == nullptr){
        cout<<"Stack is empty"<<'\n';
        return;
    }
    Node* temp = LLStack;
    LLStack = LLStack -> next;
    delete temp;
}

void LLTop(){
    cout<<LLStack->data<<'\n';
}

void LLPrint() //This function does not exist normally in stack, so I did not do reverse print here.
{
    //SAME AS TRAVERSAL, BUT WITH A PRINT STATEMENT INCLUDED
    Node* temp = LLStack;
    while(temp!=nullptr){
        cout<<temp->data<<' ';
        temp = temp->next;
    }
}

int main(){
    //Checking Array implementation.
    ArrayPop();
    ArrayPush(2);
    ArrayPush(3);
    ArrayPush(4);
    ArrayPush(5);
    ArrayTop();
    ArrayPop();
    ArrayPrint();

    // Checking LL implementation.
    LLPop();
    LLPush(2);
    LLPush(3);
    LLPush(10);
    LLTop();
    LLPop();
    LLPrint();

    // Note - LL implementation of stack has advantages over array implementation - 
    // 1. Array is finite length so can get filled. LL fills only when computer memory is full.
    // 2. We can free the memory of the element not required when we are doing Pop for LL. In array, the element still stays in memory.
}



