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

    void dfs(TreeNode* root, int d, int l) {
        if (!root) return;

        res = max(res, l);

        dfs(root -> right, 0, d == 0 ? 1 : l+1);
        dfs(root -> left, 1, d == 1 ? 1 : l + 1);
    }

    int longestZigZag(TreeNode* root) {
        dfs(root, 0, 0);
        // dfs(root, 1, 0);
        return res;
    }
};