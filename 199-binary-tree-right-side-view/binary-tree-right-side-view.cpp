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
    vector<int>res;
    void BFS(TreeNode* p) {
        queue<pair<TreeNode*, int>> q;
        q.push({p,0});
        while (q.size()){
            auto t = q.front();
            if (t.second == res.size()) res.push_back(t.first->val);
            q.pop();
            if (t.first -> right) q.push({t.first->right, t.second+1});
            if (t.first -> left) q.push({t.first->left, t.second+1});
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        BFS(root);
        return res;
    }
};