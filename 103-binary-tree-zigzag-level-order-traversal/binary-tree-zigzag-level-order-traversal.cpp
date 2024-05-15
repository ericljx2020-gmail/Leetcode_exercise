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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        stack<TreeNode*> l, r;
        l.push(root);
        int idx = 1;
        vector<vector<int>> res;
        while (idx) {
            vector<int> cur;
            if (idx & 1){
                while (l.size()){
                    auto p = l.top();
                    l.pop();
                    cur.push_back(p -> val);

                    if (p -> left) r.push(p -> left);
                    if (p -> right) r.push(p -> right);
                }
                res.push_back(cur);
                if (r.empty()) break;
            }else{
                while (r.size()) {
                    auto p = r.top();
                    r.pop();
                    cur.push_back(p -> val);

                    if (p -> right) l.push(p -> right);
                    if (p -> left) l.push(p -> left);
                }
                res.push_back(cur);
                if (l.empty()) break;
            }
            idx++;
        }
        return res;
    }
};