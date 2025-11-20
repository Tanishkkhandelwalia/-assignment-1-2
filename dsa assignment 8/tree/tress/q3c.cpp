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
    if (!root) return new Node(key);

    if (key < root->data)
        root->left = insertNode(root->left, key);
    else
        root->right = insertNode(root->right, key);

    return root;
}


int maxDepth(Node* root) {
    if (root == NULL)
        return 0;

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return 1 + max(leftDepth, rightDepth);
}

int main() {
    Node* root = NULL;

    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : arr)
        root = insertNode(root, x);

    cout << "Maximum Depth of BST = " << maxDepth(root) << endl;

    return 0;
}
