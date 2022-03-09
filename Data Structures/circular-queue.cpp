/*  In regular queues, the queue might be full even though some earlier spaces are left unoocupied. We use circular queue to 
    solve this issue.
*/

#include<iostream>
using namespace std;

// Array based implementation
// Logic - For current position i - Next position = (i+1)%N. Prev position = (i+N-1)%N.
// When (i+1)%N == front, queue is full.
// Rest same as regular queue.

int circularQueue[10];
int front=-1, rear=-1;

bool isEmpty(){
    return front==-1 && rear==-1;
}

void Push(int x){
    if((rear+1)%10 == front){
        cout<<"Queue is full"<<'\n';
        return;
    }
    if(front==-1) front=0;
    rear = (rear+1)%10;
    circularQueue[rear] = x;
}

void Pop(){
    if(isEmpty()){
        cout<<"Queue is empty"<<'\n';
        return;
    }
    if(front==rear){
        front=-1;
        rear=-1;
    }
    front = (front+1)%10;
}

int Peek(){
    return circularQueue[front];
}

int main(){
    Push(2);
    Push(3);
    Push(5);
    Push(4);
    Push(6);
    Push(7);
    Push(23);
    Push(8);
    Push(39);
    Push(24);
    Push(2);


}