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
    while(ArrayFront<=ArrayRear){
        cout<<ArrayQueue[ArrayFront]<<' ';
        ArrayFront++;
    }
    cout<<'\n';
}

int main(){
    ArrayPop();
    ArrayPush(3);
    ArrayPush(4);
    ArrayPush(5);
    ArrayPeek();
    ArrayPop();
    ArrayPeek();
    ArrayDisplay();
}