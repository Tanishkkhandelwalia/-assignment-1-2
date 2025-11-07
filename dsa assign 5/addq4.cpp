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
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}


Node* rotateLeft(Node* head, int k) {
    if (!head || k == 0)
        return head;

    
    Node* temp = head;
    int len = 1;
    while (temp->next) {
        temp = temp->next;
        len++;
    }

    
    temp->next = head;

    
    k = k % len;
    if (k == 0) {
        temp->next = NULL;
        return head;
    }

   
    Node* newTail = head;
    for (int i = 1; i < k; i++)
        newTail = newTail->next;

    
    Node* newHead = newTail->next;

   
    newTail->next = NULL;

   
    return newHead;
}


void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);

    cout << "Original List: ";
    printList(head);

    int k = 2;
    head = rotateLeft(head, k);

    cout << "List after rotating left by " << k << " positions: ";
    printList(head);

    return 0;
}
