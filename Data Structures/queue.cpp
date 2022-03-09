#include<iostream>
using namespace std;

// Array Based Implementation -
// Logic - There are two indicators, front and rear. Initially fromt = -1, rear = -1
// When we have to insert an element, we first check whether array is filled or not, if not, we increment rear by one and insert the element in the index pointed by rear.
// When we have to pop an element, we increment front by one. If popping makes queue empty (i.e., before popping front==rear) we set front and rear to -1.
// When front==rear==-1, the queue is empty.

int ArrayQueue[10];
int ArrayFront = -1, ArrayRear = -1;


bool ArrayIsEmpty(){
    return ArrayFront==-1 && ArrayRear == -1;
}

void ArrayPush(int x){
    if(ArrayRear == 9){
        cout<<"Queue is full"<<'\n';
        return;
    }
    ArrayRear++;
    ArrayFront = ArrayFront==-1 ? 0 : ArrayFront;
    ArrayQueue[ArrayRear] = x;
}

void ArrayPop(){
    if(ArrayIsEmpty()){
        cout<<"Queue is empty"<<'\n';
        return;
    }
    else if(ArrayFront == ArrayRear){
        ArrayFront = -1;
        ArrayRear = -1;
    }
    else {
        ArrayFront++;
    }
}

void ArrayPeek(){
    cout<< ArrayQueue[ArrayFront]<<'\n';
}

void ArrayDisplay(){  //Not a real queue function
    int temp = ArrayFront;
    while(temp<=ArrayRear){
        cout<<ArrayQueue[temp]<<' ';
        temp++;
    }
    cout<<'\n';
}

// Linked List Based Implementation
// Logic - We have two pointers front and rear initially pointing to null. When we push for first time, we make front point to head after pushing. Every time we push, we make rear point to the last element of the list. Now, we can both push and pop in O(1) time.

struct Node {
    int data;
    Node* next;
};

Node* LLQueue = nullptr;
Node* LLfront = nullptr;
Node* LLrear = nullptr;

bool LLIsEmpty(){
    return LLQueue == nullptr;
}

void LLPush(int x){
    Node* temp = new Node();
    temp->data = x;
    temp->next = nullptr;
    if(LLIsEmpty()){
        LLQueue = temp;
        LLfront = LLQueue;
        LLrear = LLQueue;
    }
    else {
        LLrear -> next = temp;
        LLrear = temp;
    }
}

void LLPop(){
    if(LLIsEmpty()){
        cout<<"Queue is empty"<<'\n';
        return;
    }
    Node* temp = LLfront;
    LLQueue = temp->next;
    LLfront = temp->next;
    delete temp;
}

int LLPeek(){
    return LLfront->data;
}

void LLDisplay(){
    Node* temp = LLQueue;
    while(temp != nullptr){
        cout<<temp->data<<' ';
        temp = temp->next;
    }
    cout<<'\n';
}

int main(){
    // ArrayPop();
    // ArrayPush(3);
    // ArrayPush(4);
    // ArrayPush(5);
    // ArrayPeek();
    // ArrayPop();
    // ArrayPeek();
    // ArrayDisplay();

    LLPush(3);
    LLPop();
    LLPush(4);
    LLPush(5);
    LLPush(6);
    LLPush(7);
    LLPush(8);
    LLPush(9);
    cout<<LLPeek()<<'\n';
    LLPop();
    cout<<LLPeek()<<'\n';
    LLPop();
    LLPop();
    cout<<LLPeek()<<'\n';
    LLPop();
    LLDisplay();
}