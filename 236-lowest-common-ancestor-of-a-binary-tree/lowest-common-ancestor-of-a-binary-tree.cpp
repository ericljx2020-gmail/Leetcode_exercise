/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* res = NULL;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return res;
    }

    int dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return 0;
        int st = dfs(root->left, p, q);
        if (root -> val == p -> val) st |= 2;
        if (root -> val == q -> val) st |= 1;
        st |= dfs(root->right, p, q);
        if (st == 3 && res == NULL) res = root;
        return st;
    }
};