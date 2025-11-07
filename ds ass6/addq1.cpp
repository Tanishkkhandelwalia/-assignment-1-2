#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};


void insertNode(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        newNode->next = head; 
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}


void splitCircularList(Node* head) {
    if (head == NULL || head->next == head) {
        cout << "List too small to split.\n";
        return;
    }

    
    int count = 1;
    Node* temp = head;
    while (temp->next != head) {
        count++;
        temp = temp->next;
    }

    
    int mid = (count + 1) / 2;

    
    Node* curr = head;
    for (int i = 1; i < mid; i++) {
        curr = curr->next;
    }

    
    Node* head1 = head;
    Node* head2 = curr->next;

    
    curr->next = head1;  
    temp->next = head2; 

      
    cout << "First Half: ";
    Node* t1 = head1;
    do {
        cout << t1->data << " ";
        t1 = t1->next;
    } while (t1 != head1);
    cout << endl;

    cout << "Second Half: ";
    Node* t2 = head2;
    do {
        cout << t2->data << " ";
        t2 = t2->next;
    } while (t2 != head2);
    cout << endl;
}


void printList(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    Node* head = NULL;

    
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);
    insertNode(head, 6);

    cout << "Original Circular Linked List: ";
    printList(head);

    splitCircularList(head);

    return 0;
}
