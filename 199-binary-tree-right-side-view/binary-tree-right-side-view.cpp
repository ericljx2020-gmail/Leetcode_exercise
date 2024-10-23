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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> res(200, -1);
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int h = 0;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            h = max(h, t.second);
            if (res[t.second] == -1) res[t.second] = t.first -> val;
            if (t.first -> right) q.push({t.first -> right, t.second+1});
            if (t.first -> left) q.push({t.first -> left, t.second+1});
        }
        vector<int> ans;
        for (int i = 0; i <= h; i++){
            ans.push_back(res[i]);
        }
        return ans;
    }
};