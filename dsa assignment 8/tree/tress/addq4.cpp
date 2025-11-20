#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> rightView(TreeNode* root) {
    vector<int> result;
    if (!root)
        return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();  

        for (int i = 0; i < n; i++) {
            TreeNode* node = q.front();  
            q.pop();

            
            if (i == n - 1)
                result.push_back(node->val);

            
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }

    return result;
}

int main() {
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->right->right = new TreeNode(7);

    vector<int> view = rightView(root);

    cout << "Right View of Binary Tree: ";
    for (int val : view)
        cout << val << " ";
    cout << endl;

    return 0;
}
