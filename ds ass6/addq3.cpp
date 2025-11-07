#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};


void insertEnd(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}


void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " <-> ";
        head = head->next;
    }
    cout << endl;
}


Node* reverseInGroups(Node* head, int k) {
    if (!head || k == 1) return head;

    Node* current = head;
    Node* newHead = NULL;
    Node* groupPrev = NULL;

    while (current) {
        Node* groupStart = current;
        Node* prev = NULL;
        int count = 0;

       
        while (current && count < k) {
            Node* nextNode = current->next;
            current->next = prev;
            current->prev = nextNode; 
            prev = current;
            current = nextNode;
            count++;
        }

        
        if (!newHead)
            newHead = prev;

        
        if (groupPrev) {
            groupPrev->next = prev;
            prev->prev = groupPrev;
        }

        groupPrev = groupStart; 
    }

    return newHead;
}

int main() {
    Node* head = NULL;

    
    for (int i = 1; i <= 8; i++)
        insertEnd(head, i);

    cout << "Original list:\n";
    printList(head);

    int k = 3;
    head = reverseInGroups(head, k);

    cout << "\nReversed in groups of " << k << ":\n";
    printList(head);

    return 0;
}
