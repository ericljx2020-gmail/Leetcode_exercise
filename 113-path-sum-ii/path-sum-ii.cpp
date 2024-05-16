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
    vector<int> path;
    int cur = 0;
    void dfs(TreeNode* p, int t) {
        cur += p -> val;
        if (cur == t && !p -> left && !p -> right) {
            res.push_back(path);
        }
        if (p -> left){
            path.push_back(p -> left -> val);
            dfs(p -> left, t);
            path.pop_back();
        }
        if (p -> right) {
            path.push_back(p -> right -> val);
            dfs(p -> right, t);
            path.pop_back();
        }
        cur -= p -> val;
    }

    vector<vector<int>> pathSum(TreeNode* root, int t) {
        if (!root) return {};
        path.push_back(root -> val);
        dfs(root, t);
        return res;
    }
};