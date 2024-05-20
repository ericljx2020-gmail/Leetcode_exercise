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
    vector<int> res;

    void dfs(TreeNode* p) {
        if (!p) return;
        res.push_back(p -> val);
        dfs(p -> left);
        dfs(p -> right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);
        return res;
    }
};