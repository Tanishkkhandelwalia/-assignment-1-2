#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node* random;
    Node(int val) {
        data = val;
        next = prev = random = NULL;
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
    cout << "Node  Random\n";
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        if (temp->random)
            cout << temp->random->data;
        else
            cout << "NULL";
        cout << endl;
        temp = temp->next;
    }
}


void fixRandom(Node* head) {
    Node* temp = head;

    while (temp) {
        Node* expected = temp->next; 
        if (temp->random != expected) {
            cout << "\nIncorrect random pointer found at node " << temp->data
                 << " (currently points to ";
            if (temp->random)
                cout << temp->random->data;
            else
                cout << "NULL";
            cout << ")\nFixing it...\n";

            temp->random = expected;
        }
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);

    
    head->random = head->next;           
    head->next->random = head->next->next->next; 
    head->next->next->random = head->next->next->next; 
    head->next->next->next->random = NULL; 

    cout << "Before fixing:\n";
    printList(head);

    fixRandom(head);

    cout << "\nAfter fixing:\n";
    printList(head);

    return 0;
}
