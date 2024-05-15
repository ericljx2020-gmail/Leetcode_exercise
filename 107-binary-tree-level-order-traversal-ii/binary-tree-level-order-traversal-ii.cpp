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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q, d;
        q.push(root);
        int idx = 1;
        while (idx) {
            vector<int> cur;
            if (idx & 1){ 
                while (q.size()) {
                    auto p = q.front();
                    q.pop();
                    cur.push_back(p -> val);
                    if (p -> left) d.push(p -> left);
                    if (p -> right) d.push(p -> right);
                }
                res.push_back(cur);
                if (d.empty()) break;
            }else{
                while (d.size()) {
                    auto p = d.front();
                    d.pop();
                    cur.push_back(p -> val);
                    if (p -> left) q.push(p -> left);
                    if (p -> right) q.push(p -> right);
                }
                res.push_back(cur);
                if (q.empty()) break;
            }
            idx++;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};