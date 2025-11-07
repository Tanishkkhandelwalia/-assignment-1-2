#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int coeff;
    int power;
    Node* next;

    Node(int c, int p) {
        coeff = c;
        power = p;
        next = NULL;
    }
};


void insert(Node*& head, int coeff, int power) {
    Node* newNode = new Node(coeff, power);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}


Node* addPolynomial(Node* poly1, Node* poly2) {
    Node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->power == poly2->power) {
            insert(result, poly1->coeff + poly2->coeff, poly1->power);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->power > poly2->power) {
            insert(result, poly1->coeff, poly1->power);
            poly1 = poly1->next;
        }
        else {
            insert(result, poly2->coeff, poly2->power);
            poly2 = poly2->next;
        }
    }

    
    while (poly1 != NULL) {
        insert(result, poly1->coeff, poly1->power);
        poly1 = poly1->next;
    }

    
    while (poly2 != NULL) {
        insert(result, poly2->coeff, poly2->power);
        poly2 = poly2->next;
    }

    return result;
}


void printPoly(Node* head) {
    while (head) {
        cout << head->coeff << "x^" << head->power;
        if (head->next) cout << " + ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;

    
    insert(poly1, 5, 3);
    insert(poly1, 4, 2);
    insert(poly1, 2, 1);

    
    insert(poly2, 3, 3);
    insert(poly2, 1, 1);
    insert(poly2, 6, 0);

    cout << "Polynomial 1: ";
    printPoly(poly1);

    cout << "Polynomial 2: ";
    printPoly(poly2);

    Node* result = addPolynomial(poly1, poly2);

    cout << "\nResultant Polynomial: ";
    printPoly(result);

    return 0;
}
