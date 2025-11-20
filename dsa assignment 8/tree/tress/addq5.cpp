#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

unordered_map<int, int> inorderIndex;  
TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd,
                          vector<int>& inorder, int inStart, int inEnd) {
    if (preStart > preEnd || inStart > inEnd) 
        return NULL;

    
    TreeNode* root = new TreeNode(preorder[preStart]);

    
    int inRoot = inorderIndex[root->val];
    int numsLeft = inRoot - inStart;  

    
    root->left = buildTreeHelper(preorder, preStart + 1, preStart + numsLeft,
                                 inorder, inStart, inRoot - 1);

    root->right = buildTreeHelper(preorder, preStart + numsLeft + 1, preEnd,
                                  inorder, inRoot + 1, inEnd);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    
    for (int i = 0; i < inorder.size(); i++) {
        inorderIndex[inorder[i]] = i;
    }

    return buildTreeHelper(preorder, 0, preorder.size() - 1,
                           inorder, 0, inorder.size() - 1);
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> preorder(n), inorder(n);

    cout << "Enter preorder: ";
    for (int i = 0; i < n; i++)
        cin >> preorder[i];

    cout << "Enter inorder: ";
    for (int i = 0; i < n; i++)
        cin >> inorder[i];

    TreeNode* root = buildTree(preorder, inorder);
}