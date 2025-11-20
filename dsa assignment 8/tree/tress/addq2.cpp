#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<TreeNode*> generateTreesHelper(int start, int end) {
    vector<TreeNode*> result;

    if (start > end) {
        result.push_back(NULL);
        return result;
    }

    for (int i = start; i <= end; i++) {
        
        vector<TreeNode*> leftTrees = generateTreesHelper(start, i - 1);
        vector<TreeNode*> rightTrees = generateTreesHelper(i + 1, end);

        
        for (auto left : leftTrees) {
            for (auto right : rightTrees) {
                TreeNode* root = new TreeNode(i);
                root->left = left;
                root->right = right;
                result.push_back(root);
            }
        }
    }

    return result;
}


vector<TreeNode*> generateTrees(int n) {
    if (n == 0) return {};
    return generateTreesHelper(1, n);
}

void printPreorder(TreeNode* root) {
    if (!root) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<TreeNode*> trees = generateTrees(n);

    cout << "\nTotal Unique BSTs = " << trees.size() << "\n\n";

    int t = 1;
    for (auto tree : trees) {
        cout << "Tree " << t++ << ": ";
        printPreorder(tree);
        cout << "\n";
    }

    return 0;
}
