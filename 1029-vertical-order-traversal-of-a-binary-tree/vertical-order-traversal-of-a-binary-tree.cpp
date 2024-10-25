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
    int l = INT_MAX;
    int r = INT_MIN;
    vector<vector<int>> res;
    unordered_map<int, unordered_map<int, priority_queue<int, vector<int>, greater<int>>>> hash;
    // unordered_map<int, unordered_map<int, bool>> st;
    void dfs(TreeNode* p, int d, int w) {
        if (!p) return ;
        hash[d][w].push(p -> val);
        dfs(p -> left, d-1, w+1);
        l = min(l, d);
        r = max(r, d);
        dfs(p -> right, d+1, w+1);
        return;
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        for (int i = l; i <= r; i++){
            vector<int> cur;
            for (int j = 0; j < hash[i].size(); j++){
                while (hash[i][j].size()) {
                    auto t = hash[i][j].top();
                    hash[i][j].pop();
                    cur.push_back(t);
                }
            }
            res.push_back(cur);
        }
        return res;
    }
};