#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

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


int minDepth(Node* root) {
    if (root == NULL)
        return 0;

    
    if (root->left == NULL)
        return 1 + minDepth(root->right);

    
    if (root->right == NULL)
        return 1 + minDepth(root->left);

    
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

int main() {
    Node* root = NULL;

    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 90);

    cout << "Minimum Depth of BST = " << minDepth(root) << endl;

    return 0;
} 