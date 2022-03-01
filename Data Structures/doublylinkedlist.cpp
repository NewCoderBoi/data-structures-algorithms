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
    Node* newNode = new Node;
    newNode->data = x;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void InsertAtHead(int x)
{
    Node* newNode = CreateNode(x);
    if(head == nullptr){
        head = newNode;
        return;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }
}

void InsertAtTail(int x)
{
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
    Node* temp = head;
    while(temp!= nullptr){
        cout<<temp->data<<' ';
        temp = temp->next;
    }
    cout<<'\n';
}

void ReversePrint(Node* temp)
{
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
