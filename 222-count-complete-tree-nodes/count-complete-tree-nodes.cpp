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

    void dfs(TreeNode* p){
        if (!p) return ;
        res++;
        dfs(p -> left);
        dfs(p -> right);
    }

    int countNodes(TreeNode* root) {
        dfs(root);
        return res;
    }
};