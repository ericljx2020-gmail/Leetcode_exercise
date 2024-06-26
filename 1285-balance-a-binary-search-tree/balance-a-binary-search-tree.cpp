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
    vector<int> v;

    void dfs(TreeNode* p){
        if (!p) return;
        dfs(p -> left);
        v.push_back(p -> val);
        dfs(p -> right);
    }

    TreeNode* build(int l, int r){
        if (l > r) return nullptr;
        int k = l + r + 1 >> 1;
        TreeNode* p = new TreeNode(v[k]);
        p -> left = build(l, k-1);
        p -> right = build(k+1, r);
        return p;
    }

    TreeNode* balanceBST(TreeNode* root) {
        dfs(root);
        auto p = build(0, v.size()-1);
        return p;
    }
};