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
    unordered_map<int, vector<int>> hash;
    int lft = INT_MAX;
    int rht = INT_MIN;

    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) return {};
        queue<pair<TreeNode*,int>> q;
        q.push({root, 0});

        while (q.size()){
            auto t = q.front();
            q.pop();
            auto p = t.first;
            int l = t.second;
            hash[l].push_back(p -> val);
            lft = min(lft, l);
            rht = max(rht, l);
            if (p -> left) q.push({p -> left, l-1});
            if (p -> right) q.push({p -> right, l+1});
        }

        vector<vector<int>> res;
        for (int i = lft; i <= rht; i++) {
            vector<int> cur;
            for (auto c : hash[i]){
                cur.push_back(c);
            }
            res.push_back(cur);
        }
        return res;
    }
};