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


int minDepth(Node* root) {
    if (root == NULL)
        return 0;

    if (!root->left && !root->right)
        return 1;

    if (!root->left)
        return 1 + minDepth(root->right);

    if (!root->right)
        return 1 + minDepth(root->left);

    return 1 + min(minDepth(root->left), minDepth(root->right));
}

int main() {
    Node* root = NULL;

    int arr[] = {50, 30, 70, 20, 40};
    for (int x : arr)
        root = insertNode(root, x);

    cout << "Minimum Depth of BST = " << minDepth(root) << endl;

    return 0;
}
