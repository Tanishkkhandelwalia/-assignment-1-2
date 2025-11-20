#include <bits/stdc++.h>
using namespace std;

class treenode {
public:
    int val;
    treenode *left, *right;

    treenode(int x) {
        val = x;
        left = right = NULL;
    }
};

treenode* insertNode(treenode* root, int key) {
    if (!root) return new treenode(key);

    if (key < root->val)
        root->left = insertNode(root->left, key);
    else
        root->right = insertNode(root->right, key);

    return root;
}


treenode* search(treenode* root, int key) {
    if (!root || root->val == key) return root;
    if (key < root->val) return search(root->left, key);
    return search(root->right, key);
}


treenode* inorderSuccessor(treenode* root, treenode* p) {
    treenode* successor = nullptr;

    while (root != nullptr) {
        if (p->val < root->val) {
            successor = root;     
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return successor;
}


treenode* inorderPredecessor(treenode* root, treenode* p) {
    treenode* predecessor = nullptr;

    while (root != nullptr) {
        if (p->val > root->val) {
            predecessor = root;     
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return predecessor;
}


int main() {
    treenode* root = NULL;

    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : arr)
        root = insertNode(root, x);

    int key;
    cout << "Enter node value: ";
    cin >> key;

    treenode* node = search(root, key);

    if (!node) {
        cout << "Node not found in BST.\n";
        return 0;
    }

    treenode* succ = inorderSuccessor(root, node);
    treenode* pred = inorderPredecessor(root, node);

    if (succ)
        cout << "Inorder Successor of " << key << " is: " << succ->val << endl;
    else
        cout << "Inorder Successor does not exist.\n";

    if (pred)
        cout << "Inorder Predecessor of " << key << " is: " << pred->val << endl;
    else
        cout << "Inorder Predecessor does not exist.\n";

    return 0;
}
