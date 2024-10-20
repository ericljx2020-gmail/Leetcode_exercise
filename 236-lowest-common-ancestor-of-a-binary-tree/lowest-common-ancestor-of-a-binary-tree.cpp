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

    int dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return 0;
        int state = dfs(root -> left, p, q);
        if (root == p) state |= 1;
        if (root == q) state |= 2;
        state |= dfs(root -> right, p, q);
        if (state == 3 && !res) res = root;
        return state;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return res;
    }
};