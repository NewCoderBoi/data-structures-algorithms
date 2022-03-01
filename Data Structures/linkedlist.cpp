/*
* Currently done till deleting at nth node.
* Invalid cases not handled.
* Number of functions can be reduced for Insert.
* Inserting first element not done properly.
 */

#include<iostream>
using namespace std;

// The struct Node below is a prototype of every node of the Linked List.

struct Node
{
    int data;
    Node* next;
};
// This is the pointer to the head of the linked list
Node* head;

// Here I have named it head, but ideally the head pointer is named according to what the linked list is,
// since the head pointer is the only reference we have of the linked list.
// For example, if the LL is a list of students, the head pointer can be named "student".

Node* traversal()
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

Node* traversalTillNth(int n)
{

    // This function will traverse till a given nth position
    // Note - This function does not handle invalid values of n yet.

    int i=1;
    Node* traversal = head;

    while(i<n-1){
        i++;
        traversal = traversal -> next;
    }
    return traversal;

}

Node* createNode(int value)
{
    // 1. Creating a node in memory - First element of Linked List.
    Node* temp = new Node(); //temp is a pointer
    temp -> data = value;
    temp -> next = nullptr;
    return temp;
}

void insertAtEnd(Node* temp)
{
    Node* last = traversal();
    last->next = temp;
}

void insertAtBeginning(Node* temp)
{
    temp->next = head;
    head = temp;
}

void insertAtNthPosition(Node* temp, int n)
{
    Node* nth = traversalTillNth(n); //This is actually n-1th node, not nth.
    temp->next = nth->next;
    nth->next=temp;
}

void deleteAtNthPosition(int n)
{
    // Note. Traversal till nth function returns (n-1)th element.
    // we make that n-1th point to n+1th and free the nth node from memory.

    // Deleting first element
    if(n==1){
        Node* temp = head;
        head = head->next;
        delete(temp);
    }
    else{
        Node* n_minus_one = traversalTillNth(n);
        Node* nth = n_minus_one->next;

        n_minus_one->next = nth->next;
        delete(nth);
    }
}

void display()
{
    //SAME AS TRAVERSAL, BUT WITH A PRINT STATEMENT INCLUDED
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<' ';
        temp = temp->next;
    }
}

void Reverse()
{
    // Logic -
    // We use 3 pointers. One to keep track of current element of iteration,
    // one to keep track of previous element of the list because LL does not have in-built provision
    // to keep track of previous element. The last one is to keep track of the next element in original
    // LL, because when we are changing the current element to point to prev element, then we are losing the
    // in-built access to the next element.

    // For every iteration of the loop, we are making current element point to the previous element, and we do this
    // till the LL finishes. After that, we make the head point to the last element of the original LL. Thus, the LL
    // is reversed.

    Node *prev, *current, *next_temp;
    current = head;
    prev = nullptr;

    while(current != nullptr){
        next_temp = current->next;
        current->next = prev;
        prev = current;
        current = next_temp;
    }
    head = prev;
}

void RecursionPrint(Node* temp)
{
    // Logic - Simple. Instead of using a loop, we are calling the same function with argument as next element of LL,
    // and exit condition for recursion is when LL finishes.

    if(temp == nullptr) return;
    cout<<temp->data<<' ';
    RecursionPrint(temp->next);
}

void RecursionReversePrint(Node* temp)
{
    // Logic - Here, we are using the backward travel path of recursively called functions for printing.
    // The forward path is only used to traverse till the last element of the LL.

    if(temp == nullptr) return;
    RecursionReversePrint(temp->next);
    cout<<temp->data<<' ';
}
int main()
{
    // Initially, there is no linked list, so head is a null pointer.
    head = nullptr;

    Node* temp = createNode(2);

    // Now, head should point to the temp node that has been created. That is what we do next.
    head = temp;

    // 2. Inserting elements at the end.

    temp = createNode(3);
    insertAtEnd(temp);

    temp = createNode(4);
    insertAtEnd(temp);

    temp = createNode(5);
    insertAtEnd(temp);

    // 3. Inserting element at beginning of list
    temp = createNode(6);
    insertAtBeginning(temp);

    // 4. Inserting at nth position
    temp = createNode(7);
    insertAtNthPosition(temp, 3);

    // 5. Deleting at nth position
    deleteAtNthPosition(1);

    // 6. Display elements of Linked List
    display();

    // 7. Reverse the resulting Linked List
    Reverse();
    cout<<'\n';
    display();
    cout<<'\n';
    // 8. Print list forward and backward using recursion
    RecursionPrint(head);
    cout<<'\n';
    RecursionReversePrint(head);
}
