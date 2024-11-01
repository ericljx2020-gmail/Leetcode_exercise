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
        int l = dfs(p -> left);
        int r = dfs(p -> right);
        res = max(res, l+r+1);
        return max(l,r)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        res = max(res, dfs(root));
        return res-1;
    }
};