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

int main() {
    TreeNode *root = nullptr;
    int val, maxlvl = 0;

    while (cin >> val && val) {
        if (!root) {
            root = new TreeNode(val);
            maxlvl = 1;
        }
        else maxlvl = max(maxlvl, insert(root, val, 1));
    }

    cout << maxlvl << endl;
}
