#include<iostream>
using namespace std;

//Array based implementation

// We are declaring the max size of the array which will be the stack using a macro.

#define MAX_SIZE 3 //Macro
int array_stack[MAX_SIZE]; //stack of integers.

int top = -1; // When top is -1, it means the stack is empty.

void Push(int x){
    // Logic - We increment top by 1, then put the value sent by user to the top index.
    // When array is full, we send an error.

    if(top == MAX_SIZE - 1) { //Full condition
        cout<<"Stack is full"<<'\n';
        return;
    }
    top++;
    array_stack[top] = x;
}

void Pop(){
    //Logic - We just decrement top by 1.
    //If stack is empty, we throw error.

    if(top == -1){ //Empty condition
    cout<<"Stack is empty"<<'\n';
    return;
    }
    top--;
}

void Top(){
    // Logic - Prints the element pointed by top
    cout<<array_stack[top]<<'\n'; 
}

void Print(){ //Only for testing purposes, normally not present in stack implementation
    for(int i=0;i<=top;i++){
        cout<<array_stack[i]<<' ';
    }
    cout<<'\n';
}

int main(){
    Pop();
    Push(2);
    Push(3);
    Push(4);
    Push(5);
    Top();
    Pop();
    Print();

}



