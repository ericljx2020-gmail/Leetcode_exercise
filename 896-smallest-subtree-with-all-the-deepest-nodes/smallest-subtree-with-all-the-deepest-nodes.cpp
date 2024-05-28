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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }

    pair<TreeNode*, int> dfs(TreeNode* p) {
        if (!p) return {NULL, 0};
        auto l = dfs(p -> left), r = dfs(p -> right);
        if (l.second == r.second) return {p, l.second+1};
        if (l.second > r.second) return {l.first, l.second + 1};
        return {r.first, r.second + 1};
    }
};