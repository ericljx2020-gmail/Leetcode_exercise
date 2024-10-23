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

    int dfs(TreeNode* p) {
        if (!p) return 0;
        int depth = 1;
        int height = 1;
        int left = dfs(p -> left);
        int right = dfs(p -> right);
        height += max(left, right);
        depth += left;
        depth += right;
        res = max(depth, res);
        return height;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res-1;
    }
};