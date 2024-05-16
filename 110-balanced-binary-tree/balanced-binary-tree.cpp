/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (abs(getH(root -> right) - getH(root -> left)) > 1) return false;
        return isBalanced(root -> left) && isBalanced(root -> right);
        // cout << getH(root);
        // return true;
    }

    int getH(TreeNode* p) {
        if (!p) return 0;
        return 1 + max(getH(p -> left), getH(p -> right));
    }
};