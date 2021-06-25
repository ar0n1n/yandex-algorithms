#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode *root, int val) {
    if (!root) return new TreeNode(val);
    else if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);
    return root;
}

TreeNode *findLargest(TreeNode *node) {
    while (node->right)
        node = node->right;
    return node;
}

int height(TreeNode *root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

bool isAVLbalanced(TreeNode *root) {
    if (!root) return true;
    if (abs(height(root->left) - height(root->right)) > 1)
        return false;
    return isAVLbalanced(root->left) && isAVLbalanced(root->right);
}


int main() {
    TreeNode *root = nullptr;
    int val;

    while (cin >> val && val)
        root = insert(root, val);

    cout << (isAVLbalanced(root) ? "YES" : "NO") << endl;
}