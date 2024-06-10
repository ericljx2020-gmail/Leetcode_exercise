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
    string path = "";
    vector<string> res;
    void dfs(TreeNode* p){
        if (!p -> right && !p -> left){
            string tmp = path + to_string(p -> val);
            res.push_back(tmp);
            return;
        }
        string s = to_string(p -> val) + "->";
        path += s;
        if (p -> left) dfs(p -> left);
        if (p -> right) dfs(p -> right);
        for (int i = 0; i < s.size(); i++) path.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root);
        return res;
    }
};