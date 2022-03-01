#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

Node* head; // global variable

void InsertAtHead(int x)
{
    Node* temp = new DoublyLinkedList;
    temp->data = x;
    temp->prev = nullptr;
    temp->next = nullptr;
}

int main()
{

}
