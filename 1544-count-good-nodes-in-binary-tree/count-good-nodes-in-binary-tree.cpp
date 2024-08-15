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
    int goodNodes(TreeNode* root) {
        dfs(root, INT_MIN);
        return res;
    }

    void dfs(TreeNode* p, int cur_max) {
        if (!p) return;
        if (p -> val >= cur_max){
            res++;
            cur_max = p -> val;
        }

        dfs(p -> left, cur_max);
        dfs(p -> right, cur_max);
    }
};