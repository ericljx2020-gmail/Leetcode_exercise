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

    int res = 0;

    void dfs(TreeNode* p, int low, int high) {
        if (!p) return;
        if (p -> val <= high && p -> val >= low) res += p -> val;
        dfs(p -> left, low, high);
        dfs(p -> right, low, high);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        dfs(root, low, high);
        return res;
    }
};