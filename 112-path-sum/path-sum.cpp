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
    int cur = 0;
    bool flag = false;

    void dfs(TreeNode* p, int targetSum) {
        if (!p) return;
        cur += p -> val;
        if (cur == targetSum && !p -> left && !p -> right){
            flag = true;
        }
        dfs(p -> left, targetSum);
        dfs(p -> right, targetSum);
        cur -= p -> val;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return flag;
    }
};