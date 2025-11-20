#include <bits/stdc++.h>
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


Node* insertNode(Node* root, int key) {
    if (root == NULL)
        return new Node(key);

    if (key < root->data)
        root->left = insertNode(root->left, key);
    else if (key > root->data)
        root->right = insertNode(root->right, key);
    else
        cout << "Duplicate value not allowed!\n";

    return root;
}


Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}


Node* deleteNode(Node* root, int key) {
    if (!root) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        if (!root->left && !root->right) {
            delete root;
            return NULL;
        }

        else if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}


void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : arr)
        root = insertNode(root, x);

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    int key;
    cout << "Enter element to delete: ";
    cin >> key;

    root = deleteNode(root, key);

    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
