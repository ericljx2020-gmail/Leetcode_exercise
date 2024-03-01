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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        TreeNode* q[10005];
        int tt = -1, hh = 0;
        root -> val = 1;
        q[++tt] = root;
        int depth = 0;
        while (hh <= tt) {
            auto cur = q[hh++];
            if (cur -> left) q[++tt] = cur -> left, cur -> left -> val = cur -> val + 1;
            if (cur -> right) q[++tt] = cur -> right, cur -> right -> val = cur -> val +1;
            depth = max(depth, cur -> val);
        }
        return depth;
    }
    
};