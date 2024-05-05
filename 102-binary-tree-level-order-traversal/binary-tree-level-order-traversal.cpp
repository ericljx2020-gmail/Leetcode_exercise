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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return{};
        pair<TreeNode*, int> p = {root, 0};
        queue<pair<TreeNode*, int>> q;
        q.push(p);
        vector<vector<int>> res;
        vector<int> cur;
        int l = 0;
        while (q.size()){
            auto t = q.front();
            q.pop();
            if (t.second != l){
                l = t.second;
                res.push_back(cur);
                cur.clear();
            }
            cur.push_back(t.first -> val);
            if (t.first -> left != nullptr) q.push({t.first -> left, t.second+1});
            if (t.first -> right != nullptr) q.push({t.first -> right, t.second+1});
        }
        res.push_back(cur);
        return res;
    }
};