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

    void dfs(TreeNode* p){
        if(!p) return;
        dfs(p->left);
        res.push_back(p->val);
        dfs(p->right);
    }

    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        int ans = INT_MAX;
        for (int i = 1; i < res.size(); i++){
            int d = res[i] - res[i-1];
            ans =min(ans, d);
        }
        return ans;
    }
};