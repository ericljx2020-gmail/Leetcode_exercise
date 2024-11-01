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
    vector<vector<int>> res;
    unordered_map<int, vector<int>> hash;
    int l = INT_MAX, r = INT_MIN;

    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) return {};
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (q.size()) {
            auto t = q.front();
            q.pop();
            hash[t.second].push_back(t.first -> val);
            l = min(l, t.second);
            r = max(r, t.second);

            if (t.first -> left) q.push({t.first -> left, t.second-1});
            if (t.first -> right) q.push({t.first -> right, t.second + 1});
        }
        for (int i = l; i <= r; i++){
            res.push_back(hash[i]);
        }
        return res;
    }
};