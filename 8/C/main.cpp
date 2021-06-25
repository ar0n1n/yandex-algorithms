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

TreeNode *find2ndLargest(TreeNode *node) {
    if (!node->right && node->left)
        return findLargest(node->left);
    if (node->right && !node->right->left &&
        !node->right->right)
        return node;
    return find2ndLargest(node->right);
}

int main() {
    TreeNode *root = nullptr;
    int val;

    while (cin >> val && val)
        root = insert(root, val);

    cout << find2ndLargest(root)->val << endl;
}

