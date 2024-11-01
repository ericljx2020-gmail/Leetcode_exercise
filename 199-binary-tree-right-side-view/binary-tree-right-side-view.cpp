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
    unordered_map<int, vector<int>> level;
    vector<int> rightSideView(TreeNode* root) {
        if (!root ) return {};
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int d = 0;
        while (q.size()){
            auto t = q.front();
            q.pop();
            level[t.second].push_back(t.first -> val);
            d = max(d, t.second);
            if (t.first -> right) q.push({t.first -> right, t.second+1});
            if (t.first -> left) q.push({t.first -> left, t.second + 1});
        }
        vector<int> res;
        for (int i= 0; i <= d; i++){
            res.push_back(level[i][0]);
        }
        return res;
    }
};