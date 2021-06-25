#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int insert(TreeNode *root, int val, int lvl) {
    lvl += 1;
    if (val < root->val) {
        if (root->left) return insert(root->left, val, lvl);
        else root->left = new TreeNode(val);
    }
    else if (val > root->val){
        if (root->right) return insert(root->right, val, lvl);
        else root->right = new TreeNode(val);
    }
    else return -1;
    return lvl;
}

void printNodesWithTwoChilds(TreeNode *root) {
    if (!root) return;
    if (root->left) printNodesWithTwoChilds(root->left);
    if (root->left && root->right)
        cout << root->val << endl;
    if (root->right) printNodesWithTwoChilds(root->right);
}

int main() {
    TreeNode *root = nullptr;
    int val;

    while (cin >> val && val) {
        if (!root) root = new TreeNode(val);
        else insert(root, val, 1);
    }

    printNodesWithTwoChilds(root);
}
