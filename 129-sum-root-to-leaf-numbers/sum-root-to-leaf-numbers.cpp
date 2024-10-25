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
    int res = 0;

    void dfs(TreeNode* p, int h) {
        int cur = h * 10 + p -> val;
        if (!p -> left && !p ->right){
            res +=cur;
        }
        if (p -> left) dfs(p -> left, cur);
        if (p -> right) dfs(p -> right, cur);
    }

    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        dfs(root, 0);
        return res;
    }
};