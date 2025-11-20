#include <bits/stdc++.h>
using namespace std;
   
class treenode {
public:
    int val;
    treenode *left, *right;
    treenode(int v) {
        val = v;
        left = right = nullptr;
    }
};

bool isLeaf(treenode* node) {
    return (node != nullptr && node->left == nullptr && node->right == nullptr);
}


int sumOfLeftLeaves(treenode* root) {
    if (root == nullptr)
        return 0;

    int sum = 0;

    
    if (isLeaf(root->left))
        sum += root->left->val;
    else
        sum += sumOfLeftLeaves(root->left); 

    sum += sumOfLeftLeaves(root->right);

    return sum;
}

treenode* create() {
    int x;
    cout << "Enter data (-1 for no node): ";
    cin >> x;

    if (x == -1)
        return nullptr;

    treenode* newnode = new treenode(x);
    cout << "Enter left child of " << x << ": ";
    newnode->left = create();
    cout << "Enter right child of " << x << ": ";
    newnode->right = create();

    return newnode;
}

int main() {
    treenode* root = create();
    int result = sumOfLeftLeaves(root);
    cout << "\nSum of all left leaves = " << result << endl;
    return 0;
}
