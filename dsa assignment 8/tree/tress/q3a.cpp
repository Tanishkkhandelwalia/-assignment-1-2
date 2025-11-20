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

    
    if (key == root->data) {
        cout << "Duplicate value " << key << " not allowed!\n";
        return root;
    }

    
    if (key < root->data)
        root->left = insertNode(root->left, key);

    
    else
        root->right = insertNode(root->right, key);

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

    cout << "Enter elements to insert into BST (-1 to stop):\n";

    while (true) {
        int x;
        cin >> x;
        if (x == -1) break;
        root = insertNode(root, x);
    }

    cout << "\nInorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    return 0;
}
