#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node* insertNode(Node* root, int val) {
    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = insertNode(root->left, val);
    else
        root->right = insertNode(root->right, val);

    return root;
}


Node* searchRecursive(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}


Node* searchIterative(Node* root, int key) {
    Node* current = root;

    while (current != NULL) {
        if (current->data == key)
            return current;

        if (key < current->data)
            current = current->left;
        else
            current = current->right;
    }

    return NULL;
}

int main() {
    Node* root = NULL;

    
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : arr)
        root = insertNode(root, x);

    int key;
    cout << "Enter key to search: ";
    cin >> key;

    
    Node* r1 = searchRecursive(root, key);
    if (r1)
        cout << "Recursive Search: Found " << key << endl;
    else
        cout << "Recursive Search: Not Found" << endl;

    
    Node* r2 = searchIterative(root, key);
    if (r2)
        cout << "Iterative Search: Found " << key << endl;
    else
        cout << "Iterative Search: Not Found" << endl;

    return 0;
}
