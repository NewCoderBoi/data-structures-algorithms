#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

Node* head; // global variable

Node* CreateNode(int x)
{
    Node* newNode = new Node; //Dynamic memory allocation
    newNode->data = x;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void InsertAtHead(int x)
{
    Node* newNode = CreateNode(x);

    //Checking whether List is empty or not.

    if(head == nullptr){
        head = newNode;
        return;
    }

    //If list is not empty, we make the current head element's prev point to the new element,
    //and the new element's next point to the current head element. Then we make head point
    //to the new element.

    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }
}

void InsertAtTail(int x)
{
    // Logic - Traverse till the end of the list, when last element reached,
    // make next of last element point to new element, and prev of new element
    // point to last element.

    Node* newNode = CreateNode(x);
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void Display()
{
    // Same as singly linked list.

    Node* temp = head;
    while(temp!= nullptr){
        cout<<temp->data<<' ';
        temp = temp->next;
    }
    cout<<'\n';
}

void ReversePrint(Node* temp)
{
    // Same as singly linked list.

    if(temp->next != nullptr){
        ReversePrint(temp->next);
    }
    cout<<temp->data<<' ';
}

int main()
{
    InsertAtHead(2);
    InsertAtHead(4);
    InsertAtHead(6);

    Display();

    InsertAtTail(8);
    InsertAtTail(10);

    Display();

    ReversePrint(head);
}
