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

    void BFS(TreeNode* p, int d){
        if (!p) return ;
        res = max(res, d);
        if (p -> left) BFS(p -> left, d+1);
        if (p -> right) BFS(p -> right, d+1);
    }

    int maxDepth(TreeNode* root) {
        BFS(root, 1);
        return res;    
    }
};